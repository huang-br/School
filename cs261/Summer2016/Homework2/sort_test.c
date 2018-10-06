#include "sort_test.h"
#include "vector.h"
#include "merge_sort.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*This program expects up to three arguments which get converted into the
 * size, min and max variables below. If unspecified the default is used.
 * 'size' random elements ranging from 'min' to 'max' are given to a
 * sorting algorithm. The algorithm is timed and checked for correctness.*/
int main(int argc, char** argv) {
	
	/*Our defaults*/
	int size = 10;
	int min = -100;
	int max = 100;
	/*Local variables*/
	bool correct = true, ascending = true, matching = true;
	double sort_time;
	struct timespec start, end;
	vector* to_sort_ptr,*correct_ptr,*backup_ptr;
	int i;

	/*Loop through any present arguments and update our variables as appropriate.*/
	for (i=1; i < ((argc<4)?argc:4); i++) {
		char* end_ptr = NULL;
		int n = strtol(argv[i],&end_ptr,10);
		if (strlen(argv[i]) == strlen(end_ptr)) {
			fprintf(stderr,"Argument %s not parseable as an integer.\n",argv[i]);
			return 1;
		} else switch (i) {
			case 1:
				size = n;
				break;
			case 2:
				min = n;
				break;
			case 3:
				max = n;
				break;
		}
	}

	/*Create a new vector of a given size filled with random values.*/
	to_sort_ptr = new_vector(size);
	vector_random_fill(to_sort_ptr, min, max);
	/*This copy is to be sorted by the Instructor's merge_sort to compare for
	 * correctness.*/
	correct_ptr = copy_of_vector(to_sort_ptr);

	/*Time the sorting algorithm.*/
	printf("Sorting %d " macstr(TYPE) " elements with " macstr(SORT_FN) " ...\n",to_sort_ptr->size);
	clock_gettime(CLOCK_REALTIME,&start);
	SORT_FN(to_sort_ptr);
	clock_gettime(CLOCK_REALTIME,&end);
	sort_time = ((end.tv_sec*(1.0e9)+end.tv_nsec)-(start.tv_sec*(1.0e9)+start.tv_nsec))*1.0e-9;
	printf("\t" macstr(SORT_FN) " took %9.9f seconds.\n",sort_time);

	/*Check results.*/
	printf("Checking for correctness ...\n");
	merge_sort(correct_ptr);/*Generate correct solution.*/
	backup_ptr = copy_of_vector(to_sort_ptr);/*Copy given solution for later.*/
	for(i=0; i < correct_ptr->size; i++) {
		if (i >= to_sort_ptr->size || to_sort_ptr->values[i] != correct_ptr->values[i]) {
			correct = false;
			break;
		}
	}
	printf("\t" macstr(SORT_FN) " sorted %s.\n",correct?"correctly":"incorrectly");
	
	if (!correct) {
		printf("Diagnosing cause of failure ...\n");
		/*We need to see if we failed because the elements weren't sorted, or
		 * because some elements were clobbered or otherwise overwritten.*/
		merge_sort(backup_ptr);
		for(i=0; i < correct_ptr->size; i++) {
			if (i >= backup_ptr->size || backup_ptr->values[i] != correct_ptr->values[i]) {
				matching = false;
				break;
			}
		}
		for(i=1; i < to_sort_ptr->size; i++) {
			if (to_sort_ptr->values[i] < to_sort_ptr->values[i-1]) {
				ascending = false;
				break;
			}
		}
		if (matching && !ascending) {
			printf("\t" macstr(SORT_FN) " did not put values in ascending order.\n");
		} else if (!matching && ascending) {
			printf("\t" macstr(SORT_FN) " changed some of the original values.\n");
		} else {/*if (!matching && !ascending)*/
			printf("\t" macstr(SORT_FN) " did not put values in ascending order and changed some of the original values.\n");
		}
	}

	/*We need to delete our vectors.*/
	free_vector(to_sort_ptr);
	free_vector(correct_ptr);
	free_vector(backup_ptr);
	
	return 0;
}

