/* CS261- HW1 - Program4.c*/
/* Name:Brian Huang
 * Date:4/8/2016
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
	int k, j, temp;

	for(j=0; j < n-1; ++j)
	{
		for(k=0; k < n-j-1; ++k)
		{
			if(number[k] > number[k+1])
			{
				temp = number[k];
				number[k] = number[k+1];
				number[k+1] = temp;
			}
		}
	}	
			
}

int main(){
	srand(time(NULL));
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
	int *array;
	array = (int *) malloc(n*sizeof(int));
    /*Fill this array with random numbers, using rand().*/
	int k;
	for(k=0; k < n; ++k)
	{
		array[k] = rand() %101;
	}
    /*Print the contents of the array.*/
	printf("Unsorted\n");
	for(k=0; k < n; ++k)
	{
		printf("%d\n",array[k]);
	}
    /*Pass this array along with n to the sort() function of part a.*/
	sort(array, n);
    /*Print the contents of the array.*/
   	printf("Sorted\n");	
	for(k=0; k < n; ++k)
	{
		printf("%d\n",array[k]);
	}
    return 0;
}
