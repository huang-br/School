#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>

//Functions
void getKey(int socket, int processId);
int getFile(int socket, int processId);
void encode(int socket, int processId, int numChars);
void newThread(int socket, int processId);

int main(int argc, char *argv[])
{
	//creating variables
	int listenSocket;
	int newListenSocket;
	int portNum;
	int processId;

	socklen_t clientLength;
	struct sockaddr_in serverAddress, clientAddress; 

	listenSocket = socket(AF_INET, SOCK_STREAM, 0);
	bzero((char *) &serverAddress, sizeof(serverAddress));

	portNum = atoi(argv[1]);

	//Setting up the socket
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(portNum);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	bind(listenSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));

	listen(listenSocket, 5);

	clientLength = sizeof(clientAddress);

	//Making the program run in the background.
	while(1)
	{
		newListenSocket = accept(listenSocket, (struct sockaddr *) &clientAddress, &clientLength);
		processId = fork();
		if(processId == 0)
		{
			close(listenSocket);
			int childProcess = getpid();
			newThread(newListenSocket, childProcess);
			exit(0);
		}
	}
	return 0;
}

void getKey(int socket, int processId)
{
	char fileName[10];
	bzero(fileName, 10);
	char message[10];
	sprintf(fileName, "%dk", processId);

	FILE *fp = fopen(fileName, "a");
	int fileSize = 0;

	while((fileSize = recv(socket, message, 10, 0)) > 0)
	{
		int writeSize = fwrite(message, sizeof(char), fileSize, fp);	
		bzero(message,10);
		if(fileSize == 0 || fileSize != 10)
		{
			break;
		}
	}
	fclose(fp);
	return;
}

int getFile(int socket, int processId)
{
	char fileName[10];
	bzero(fileName, 10);
	char message[10];
	sprintf(fileName, "%dt", processId);
	FILE *fp = fopen(fileName, "a");
	int fileSize = 0;
	while((fileSize = recv(socket, message, 10, 0)) > 0)
	{
		int writeSize = fwrite(message, sizeof(char), fileSize, fp);
		bzero(message, 10);
		if(fileSize ==0 || fileSize != 10)
		{
			break;
		}
	}
	fclose(fp);
	FILE *text = fopen(fileName, "r");
	fseek(text, 0, SEEK_END);
	int numChars = ftell(text);
	return numChars;
}

void encode(int socket, int processId, int numChars)
{
	char fileText[numChars -1];
	char keyText[numChars -1];
	char encodedText[numChars -1];
	int i = 0;
	int c;

	char fileName[10];
	bzero(fileName, 10);
	sprintf(fileName, "%dt", processId);

	FILE *fp = fopen(fileName, "r");
	while((c = fgetc(fp)) != EOF && i < numChars - 1)
	{
		fileText[i] = c;
		i++;
	}
	fclose(fp);

	char keyName[10];
	bzero(keyName, 10);
	sprintf(keyName, "%dk", processId);
	int j = 0;
	int d;

	FILE *fp2 = fopen(keyName, "r");
	while((d = fgetc(fp2)) != EOF && j < numChars - 1)
	{
		keyText[j];
		j++;
	}
	fclose(fp2);
	char letters[28];
	sprintf(letters, "ABCDEFGHIJKLMNOPQRSTUVWXYZ ");

	int k;
	for(k=0; k < numChars - 1; k++)
	{
		int sum = 0;
		int l;
		for(l=0; l < 28; l++)
		{
			if(fileText[k] == letters[l])
			{
				sum = sum + l + 1;
			}
			if(keyText[k] == letters[l])
			{
				sum = sum + l + 1;
			}
		}
		int letter = sum % 27;
		encodedText[k] = letters[letter];
	}
	char encodedMessage[numChars];
	bzero(encodedMessage, numChars);

	sprintf(encodedText, "%s\0", encodedText);
	int n = write(socket, encodedText, numChars - 1);
	unlink(fileName);
	unlink(keyName);
	return;
}

void newThread(int socket, int processId)
{
	int n;
	char type[2];
	bzero(type, 2);
	sprintf(type, "e");

	n = write(socket, type, strlen(type));
	int numChars = getFile(socket, processId);
	char confirmation[2];
	bzero(confirmation,1);
	sprintf(confirmation, "1");
	n = write(socket, confirmation, strlen(confirmation));
	getKey(socket, processId);
	encode(socket, processId, numChars);
	close(socket);
	return;
}


