#include <stdio.h>
#include <stdlib.h>

int main()
{
	char teststr[50];
        //teststr = (char *) malloc(50 * sizeof(char));
	printf("Input a string: ");
	scanf("%s", teststr);
	printf("Your string was: %s\n,",teststr);

	return 0;
}

