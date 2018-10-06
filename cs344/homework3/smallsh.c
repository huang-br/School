#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

#define _GNU_SOURCE

//Defining the structure
struct list
{
	int num;
	int cap;
	pid_t *children;
};

//Globals
struct list childList;
int shell_status = 0;

//Functions
void runshell();
void run(char*, unsigned int);
void cleanup(char*, char*, char**);
void initChildlist();
pid_t popChild();
void pushChild(pid_t);
void trapInterrupt(int);
int wasBackground(pid_t);
void childEnded(int);
void freeChildList();
int hasComment(char*);
char *createFile(char**, int);

int main()
{
	//Initializing the list of children
	initChildlist();

	//Catching the signals.
	signal(SIGINT, trapInterrupt);
	signal(SIGCHLD, childEnded);

	//Starting up the shell.
	runshell();
	return 0;
}

//Running the shell
void runshell()
{
	//initializing variables.
	char *string = NULL;
	size_t cap = 0;
	ssize_t lineLength;
	printf(":");

	//getting the input from the user.
	while((lineLength = getline(&string, &cap, stdin)) > 0)
	{
		//running the command
		run(string, (unsigned int)lineLength);
		printf(":");

		//Clearing out the buffer.
		fflush(stdout);
	}
	//Freeing the children.
	freeChildList();
}

//Runs the commands.
void run(char *line, unsigned int length)
{
	//Defining variables.
	char **args = malloc(length * sizeof(char*));
	const char *newline = " \n";
	const char devnull[] = "/dev/null";

	int infile = STDIN_FILENO;
	int outfile = STDOUT_FILENO;
	pid_t pid;

	char *word = NULL;
	char *input = NULL;
	char *output = NULL;
	int isBackground = 0;

	unsigned int argsIndex = 1;
	
	//Getting the first command from strtok.
	char *command = strtok(line, newline);
	if(command == NULL)
	{
		goto cleanup;
	}
	args[0] = command;

	//the exit command.
	if(strcmp(command, "exit") == 0)
	{
		trapInterrupt(-1);
		freeChildList();
		free(args);
		free(line);
		exit(0);
	}

	//the cd command. Uses strtok again to find the destination.
	else if(strcmp(command, "cd") == 0)
	{
		char *destination = strtok(NULL, newline);
		if(destination == NULL)
		{
			destination = getenv("HOME");
		}

		if(chdir(destination) == -1)
		{
			perror("chdir");
			goto cleanup;
		}
		goto cleanup;
	}

	//the status command.
	else if(strcmp(command,"status") == 0)
	{
		if(WIFEXITED(shell_status))
		{
			printf("Exited: %d\n", WEXITSTATUS(shell_status));
		}
		if(WIFSIGNALED(shell_status))
		{
			printf("Stop signal: %d\n", WSTOPSIG(shell_status));
		}
		if(WTERMSIG(shell_status))
		{
			printf("Termination signal: %d\n", WTERMSIG(shell_status));
		}
		goto cleanup;
	}

	//Creating the bash commands.
	do
	{
		word = strtok(NULL, newline);
		if(word == NULL)
		{
			break;
		}
		else if(hasComment(word))
		{
			args[argsIndex] = word;
			argsIndex++;
			break;
		}
		else if(strncmp(word, "<", 1) == 0)
		{
			word = strtok(NULL, newline);
			if (word == NULL)
			{
					printf("Invalid syntax. No input file provided\n");
					goto cleanup;
			}
			input = createFile(&word, length);
			continue;
		}
		else if(strncmp(word, ">", 1) == 0)
		{
			word = strtok(NULL, newline);
			if(word == NULL)
			{
				printf("Invalid syntax. No output file provided\n");
				goto cleanup;
			}
			output = createFile(&word, length);
			continue;
		}
		else if(strncmp(word, "&", 1) == 0)
		{
			isBackground = 1;
			break;
		}

		args[argsIndex] = word;
		argsIndex++;
	}
	while(word != NULL);

	args[argsIndex] = NULL;

	if(isBackground == 1 && input == NULL)
	{
		input = (char*)devnull;
	}
	if(isBackground == 1 && output == NULL)
	{
		output = (char*)devnull;
	}
	pid = fork();
	if(pid == 0)
	{
		if(input != NULL)
		{
			infile = open(input, O_RDONLY);
			if(infile = -1)
			{
				perror("infile");
				free(args);
				free(line);
				freeChildList(); 
				exit(1);
			}
			else
			{
				dup2(infile, STDIN_FILENO);
				close(infile);
			}
		}
		if(output != NULL)
		{
			outfile = open(output, O_WRONLY | O_CREAT, 0744);
			if(outfile == -1)
			{
				perror("outfile");
				free(args);
				free(line);
				freeChildList();
				exit(1);
			}
			if(output != devnull)
			{
				if(chmod(output, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1)
				{
					perror("chmod");
				}
			}
			dup2(outfile, STDOUT_FILENO);
			close(outfile);
		}

		execvp(command, args);
		perror("execvp"); 
		free(args);
		free(line);
		freeChildList();
		exit(1);
	}
	else
	{
		if(!isBackground)
		{
			waitpid(pid, &shell_status, 0);
		}
		else
		{
			pushChild(pid);
		}
	}
	cleanup:
	if(input != devnull)
	{
		free(input);
	}
	if(output != devnull)
	{
		free(output);
	}
	free(args);
}

//Initializing the children.
void initChildlist()
{
	childList.num = 0;
	childList.cap = 4;
	childList.children = malloc(childList.cap * sizeof(pid_t));
}

//popinng the children off the stack.
pid_t popChild()
{
	if(childList.num > 0)
	{
		childList.num--;
		return childList.children[childList.num + 1];
	}
	else
	{
		return 0;
	}
}

//pushing a child onto the stack.
void pushChild(pid_t child)
{
	if(childList.num = childList.cap)
	{
		childList.cap = 2*childList.cap;
		childList.children = realloc(childList.children, childList.cap * sizeof(pid_t));
	}
	childList.children[childList.num] = child;
	childList.num++;
}

//trapping the signal.
void trapInterrupt(int sig)
{
	int childStatus;
	pid_t child;
	while (child = popChild())
	{
		kill(child, SIGKILL);
		waitpid(child, &childStatus, 0);
	}
}

//Returns true if the process is in the background.
int wasBackground(pid_t pid)
{
	int k;
	for(k=0; k < childList.num; k++)
	{
		if(pid == childList.children[k])
		{
			return 1;
		}
	}
	return 0;
}

//return message for child ending.
void childEnded(int sig)
{
	int child;
	pid_t pid = waitpid(0, &child, 0);
	if(wasBackground(pid))
	{
		printf("%d\n%d\n", pid, WEXITSTATUS(child));
	}
}

//checks for a comment in the line.
int hasComment(char *word)
{
	int i=0;
	for(i=0; word[i] != '\0'; i++)
	{
		if(word[i] == '#')
		{
			word[i] = '\0';
			return 1;
		}
	}
	return 0;
}

//Freeing the children.
void freeChildList()
{
	free(childList.children);
}

//Creating a file.
char *createFile(char **word, int max)
{
	size_t length = strnlen(*word, max);
	char *token = malloc(length * sizeof(char));
	strncpy(token, *word, length);
	return token;
}

