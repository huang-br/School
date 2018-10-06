/* CS261- HW1 - Program5.c*/
/* Name:Brian Huang
 * Date:4/8/2016
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their initials*/
	int k, j;
	struct student stemp;
	
	for(j=0; j < n-1; ++j)
	{
		for(k=0; k < n-j-1; ++k)
		{
			/*Checking if the first character is the same*/
			if(students[k].initials[1] == students[k+1].initials[1])
			{
				if(students[k].initials[2] > students[k+1].initials[2])
				{
					stemp = students[k];
					students[k] = students[k+1];
					students[k+1] = stemp;
				}
			}
			/*If the first character is different*/
			else if(students[k].initials[1] > students[k+1].initials[1])
			{
				stemp = students[k];
				students[k] = students[k+1];
				students[k+1] = stemp;
			}
		}
	}
					
}

int main(){
	srand(time(NULL));
    /*Declare an integer n and assign it a value.*/
	int n;
	printf("What size? ");
	scanf("%d",&n);
	if(n == 0)
	{
		printf("You have entered 0.\n");
		exit(0);
	}
    /*Allocate memory for n students using malloc.*/
   	struct student *list = NULL;
        list = malloc(n*sizeof(struct student));	
    /*Generate random IDs and scores for the n students, using rand().*/
   	int k;
	for(k=0; k < n; ++k)
	{
		char c1, c2;
		c1 = rand() %26 + 'A';
		c2 = rand() %26 + 'A';
		int score;
		score = rand() % 101;
		list[k].initials[1] = c1;
		list[k].initials[2] = c2;
		
		list[k].score = score;
	}	
    /*Print the contents of the array of n students.*/
	for(k=0; k < n; ++k)
	{
		printf("%c%c: %d\n",list[k].initials[1], list[k].initials[2], list[k].score);
	}
    /*Pass this array along with n to the sort() function*/
    	sort(list, n);
    /*Print the contents of the array of n students.*/
	printf("After running the sort function.\n");
	for(k=0; k < n; ++k)
	{
		printf("%c%c: %d\n",list[k].initials[1], list[k].initials[2], list[k].score);
	}
    /*freeing the memory*/
	free(list);
    return 0;
}
