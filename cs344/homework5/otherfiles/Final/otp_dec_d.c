#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>

//functions
int getFile(int socket, int processId);
void getKey(int socket, int processId);
void decode(int processId, int numChars, int socket);
void newThread(int socket, int processId);

int main(int argc, char *argv[]) {
	//setting up the variables and socket.
	int listenSocket; 
	int newListenSocket; 
	int portNumber; 
	int processId; 

	socklen_t clilen; 
	struct sockaddr_in serverAddress, clientAddress; 

	listenSocket = socket(AF_INET, SOCK_STREAM, 0);  

	bzero((char *) &serverAddress, sizeof(serverAddress)); 

	
	portNumber = atoi(argv[1]);

	
	serverAddress.sin_family = AF_INET; 
	serverAddress.sin_port = htons(portNumber); 
	serverAddress.sin_addr.s_addr = INADDR_ANY; 

	
	bind(listenSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));

	
	listen(listenSocket,5); 

	

	clilen = sizeof(clientAddress);

	//making the program run forever
	while(1) {
		newListenSocket = accept(listenSocket, (struct sockaddr *) &clientAddress, &clilen);
		processId = fork(); 
		if(processId == 0) { 
			close(listenSocket);
			int childProcess = getpid(); 
			
			newThread(newListenSocket, childProcess); 
			exit(0);
		}
	}
	return 0;
}

int getFile(int socket, int processId) {
	//getting the temp file that holds the text.
	char fileName[10];
	bzero(fileName, 10);
	char receivedMessage[10];
	sprintf(fileName, "%dt", processId);
	FILE *fr = fopen(fileName, "a");
	int fr_block_sz = 0; 
	while((fr_block_sz = recv(socket, receivedMessage, 10, 0)) > 0) {
		int write_sz = fwrite(receivedMessage, sizeof(char), fr_block_sz, fr); 
		if(write_sz < fr_block_sz) {
		    
		}
		bzero(receivedMessage, 10);
		if (fr_block_sz == 0 || fr_block_sz != 10) { 
		    break;
		}
	}
	fclose(fr);
	FILE *text = fopen(fileName, "r");
	fseek(text, 0, SEEK_END);
	int numChars = ftell(text);
	
	return numChars; 
}

void getKey(int socket, int processId) {
	//getting the temp file that holds the key.
	char fileName[10];
	bzero(fileName, 10);
	char receivedMessage[10];
	sprintf(fileName, "%dk", processId);
	FILE *fr = fopen(fileName, "a");
	int fr_block_sz = 0; 
	while((fr_block_sz = recv(socket, receivedMessage, 10, 0)) > 0) {
		int write_sz = fwrite(receivedMessage, sizeof(char), fr_block_sz, fr); 
		if(write_sz < fr_block_sz) {
		    
		}
		bzero(receivedMessage, 10);
		if (fr_block_sz == 0 || fr_block_sz != 10) {
		    break;
		}
	}
	fclose(fr);

	return;
}

void decode(int processId, int numChars, int socket) {
	//Setting up the variables.
	char fileArray[numChars - 1]; 
	char keyArray[numChars - 1]; 
	char decodedArray[numChars - 1];
	int i = 0;
	int c;

	char fileName[10];
	bzero(fileName, 10);
	sprintf(fileName, "%dt", processId);

	FILE *fr = fopen(fileName, "r"); 
	while((c = fgetc(fr)) != EOF && i < numChars - 1) { 
		fileArray[i] = c; 
		i++;
	}
	fclose(fr);


	char kr_name[10];
	bzero(kr_name, 10);
	sprintf(kr_name, "%dk", processId);

	int j = 0;
	int d;
	FILE *kr = fopen(kr_name, "r"); 
	while((d = fgetc(kr)) != EOF && j < numChars - 1) { 
		keyArray[j] = d; 
		j++;
	}
	fclose(kr);
	char letters[28];
	sprintf(letters, " ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	
	//decoding the message
	for(i = 0; i < numChars - 1; i++) { 
		int sum = 0;
		for(j = 0; j < 28; j++) { 
			if(fileArray[i] == letters[j]) { 
				sum = sum + j; 
			}
			if(keyArray[i] == letters[j]) { 
				sum = sum - j; 
			}
		}
		sum = sum - 1; 
		if(sum < 0) { 
			sum = sum + 27; 
		}
		decodedArray[i] = letters[sum]; 
	}


	char decodedMessage[numChars];
	bzero(decodedMessage, numChars);
	sprintf(decodedArray, "%s\0", decodedArray);
	
	int n = write(socket,decodedArray,numChars - 1); 
	unlink(fileName); 
	unlink(kr_name); 
	return;
}

void newThread(int socket, int processId) {
	int n;
	char type[2];
	bzero(type, 2);
	sprintf(type, "d");
	n = write(socket,type,strlen(type)); 
	int numChars = getFile(socket, processId); 
	char confirmation[2];
  	bzero(confirmation,1);
  	sprintf(confirmation, "1");
  	n = write(socket,confirmation,strlen(confirmation)); 
	getKey(socket, processId); 
	decode(processId, numChars, socket); 
	
	close(socket); 
	return;
}
