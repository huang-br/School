#include <stdio.h>
#include <time.h>


int main()
{
	int min = 0;
	int max = 10;
	int i;
	srand(time(NULL));
	int range;
	range = (max - min + 1) + min;
	
	for(i=0; i < 100; i++)
	{
		int r = rand();
		int t = rand() % range;	
		printf("Printing random number: %d\n", r);
		printf("Printing random number in range: %d\n", t);
	}
	return 0;
}

