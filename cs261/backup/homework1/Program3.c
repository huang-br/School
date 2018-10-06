/* CS261- HW1 - Program3.c*/
/* Name:Brian Huang
 * Date:4/8/2016
 * Solution description:
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* mem = malloc(10 * sizeof(struct student)); 
     /*return the pointer*/
     return mem;
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z. 
	The scores must be between 0 and 100*/
	int k;
	for(k=0; k < 10; ++k)
	{
		char c1, c2;
		c1 = rand() %26 + 'A';
		c2 = rand() %26 + 'A';
		int score;
		score = rand() %101;
		students[k].initials[1] = c1;
		students[k].initials[2] = c2;

		students[k].score = score;
	}
     
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
	int k;
	for(k=0; k < 10; ++k)
	{
		printf("%c%c: %d\n", students[k].initials[1], students[k].initials[2], students[k].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int min, max,k;
	float average;
	min = students[0].score;
	max = students[0].score;
	for(k=0; k < 10; k++)
	{
		/*checking for minimum*/
		if(students[k].score < min)
		{
			min = students[k].score;
		}
		/*checking for maximum*/
		if(students[k].score > max)
		{
			max = students[k].score;
		}
		/*finding the average*/
		average = students[k].score + average;

	}

	average = average/10;

	printf("The lowest score was %d and the highset score was %d. The average was %f.\n",min, max,average);

    
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	free(stud);
}

int main(){
    srand(time(NULL));
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate(); 
    /*call generate*/
    generate(stud); 
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
