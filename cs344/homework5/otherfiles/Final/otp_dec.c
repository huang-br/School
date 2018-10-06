#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

void sendText(int listenSocket, char fileName[]);
void sendKey(int listenSocket, char filename []);

int main(int argc, char *argv[])
{
	FILE *text = fopen(argv[1], "r");
	FILE *key = fopen(argv[2], "r");
	fseek(text, 0, SEEK_END);
	fseek(key, 0, SEEK_END);
	int textSize = ftell(text);
	int keySize = ftell(key);
	fclose(text);
	fclose(key);
	if(keySize < textSize)
	{
		printf("Your key is too short.\n");
		exit(1);
	}

	int listenSocket;
	int portNumber;
	int n;
	struct sockaddr_in serverAddress;
	struct hostent *server;

	listenSocket = socket(AF_INET, SOCK_STREAM, 0);
	portNumber = atoi(argv[3]);
	server = gethostbyname("localhost");

	bzero((char *) &serverAddress, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	bcopy((char *)server -> h_addr, (char *)&serverAddress.sin_addr.s_addr, server -> h_length);
	serverAddress.sin_port = htons(portNumber);

	connect(listenSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));

	char type[2];
	bzero(type, 2);

	n = recv(listenSocket, type, 2, 0);
	if(type[0] == 'd')
	{
		sendText(listenSocket, argv[1]);
		char confirmation[2];
		bzero(confirmation, 2);
		n = recv(listenSocket, confirmation, 2, 0);
		if(confirmation[0] == '1')
		{
			sendKey(listenSocket, argv[2]);
		}
		char encodedMessage[textSize];
		bzero(encodedMessage, textSize);
		int m = recv(listenSocket, encodedMessage, textSize -1, 0);
		sprintf(encodedMessage, "%s\0", encodedMessage);
		printf("%s", encodedMessage);
		printf("\n");
	}
	else
	{
		printf("Could not connect to otp_enc_d\n");
		exit(2);
	}
	close(listenSocket);
	return 0;
}

void sendText(int listenSocket, char fileName[])
{
	char buffer[10];
	FILE *fp = fopen(fileName, "r");
	bzero(buffer, 10);
	int fileSize;
	int sentSize;
	while((fileSize = fread(buffer, sizeof(char), 10, fp)) > 0)
	{
		if((sentSize = send(listenSocket, buffer, fileSize, 0)) < 0)
		{
			break;
		}
		bzero(buffer, 10);
	}
	if(sentSize == 10)
	{
		send(listenSocket, "0", 1, 0);
	}
	fclose(fp);
	return;
}

void sendKey(int listenSocket, char fileName[])
{
	char buffer[10];
	FILE *fp = fopen(fileName, "r");
	bzero(buffer, 10);
	int fileSize;
	int sentSize;
	while((fileSize = fread(buffer,sizeof(char), 10, fp)) > 0)
	{
		if((sentSize = send(listenSocket, buffer, fileSize, 0)) < 0)
		{
			break;
		}
		bzero(buffer, 10);
	}
	if(sentSize == 10)
	{
		send(listenSocket, "0", 1, 0);
	}
	fclose(fp);
	return;
}

		
