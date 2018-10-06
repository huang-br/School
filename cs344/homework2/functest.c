#include <stdio.h>

void change(int[]);

int main()
{
	int arr[5] = {1,2,3,4,5};
	int i = 0;
	printf("Before change function.\n");
	for(i=0; i < 5; i++)
	{
		printf("%d\n", arr[i]);
	}
	printf("After change function. \n");
	change(arr);
	for(i=0; i < 5; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}

void change(int list[])
{
	int size = sizeof(list)/sizeof(list[0]);
	printf("The size of this list is %d.\n",size);
	list[0] = 10;
	list[1] = 20;
	list[2] = 30;
}


