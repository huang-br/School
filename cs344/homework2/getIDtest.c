#define _GUN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
	printf("Hello World\n");
	pid_t val = getpid();

	printf("%d\n",val);
	mkdir("~/cs344/homework2/testdir",0777);

	return 0;
}


