#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
	srand(time(NULL));

	int k;
	for(k=0; k < atoi(argv[1]); k++)
	{
		printf("%c", rand() %26 + 65);
	}
	printf("\n");

	return 0;
}

