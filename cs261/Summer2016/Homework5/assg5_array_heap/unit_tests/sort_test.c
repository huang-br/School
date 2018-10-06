#include "../p_queue.h"
#include "unit_test.h"
#include "sort_test.h"
#include "shell_sort.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*This is a series of unit tests meant to test correct functionality of
 * the inplace heapsort function.*/
int main(int argc, char** argv) {
	
	/*Our defaults*/
	int size = 1000000;
	generic min = (generic)-10000;
	generic max = (generic)10000;

	new_tests();

	/*Local variables*/
	bool sort_is_correct = true, ascending = true, matching = true;
	generic  *to_sort, *correct, *backup;
	int i;

	/*Create a new vector of a given size filled with random values.*/
	to_sort = malloc(size*sizeof(generic));
	array_random_fill(to_sort, size, min, max);
	/*This copy is to be sorted by the Instructor's shell_sort to compare for
	 * correctness.*/
	correct = copy_of_array(to_sort, size);

	/*Time the sorting algorithm.*/
	printf("Sorting %d elements with inplace_heap_sort ...\n",size);
	inplace_heap_sort(to_sort, size);

	/*Check results.*/
	printf("Checking for correctness ...\n");
	shell_sort(correct, size);/*Generate correct solution.*/
	backup = copy_of_array(to_sort, size);/*Copy given solution for later.*/
	for(i=0; i < size; i++) {
		if (i >= size || to_sort[i] != correct[i]) {
			sort_is_correct = false;
			break;
		}
	}
	printf("\t inplace_heap_sort sorted %s.\n",sort_is_correct?"correctly":"incorrectly");
	unit_test(sort_is_correct,15);
	
	if (!sort_is_correct) {
		printf("Diagnosing cause of failure ...\n");
		/*We need to see if we failed because the elements weren't sorted, or
		 * because some elements were clobbered or otherwise overwritten.*/
		shell_sort(backup, size);
		for(i=0; i < size; i++) {
			if (i >= size || backup[i] != correct[i]) {
				matching = false;
				break;
			}
		}
		for(i=1; i < size; i++) {
			if (to_sort[i] < to_sort[i-1]) {
				ascending = false;
				break;
			}
		}
		if (matching && !ascending) {
			printf("\t inplace_heap_sort did not put values in ascending order.\n");
		} else if (!matching && ascending) {
			printf("\t inplace_heap_sort changed some of the original values.\n");
		} else {/*if (!matching && !ascending)*/
			printf("\t inplace_heap_sort did not put values in ascending order and changed some of the original values.\n");
		}
	}

	/*We need to delete our vectors.*/
	free(to_sort);
	free(correct);
	free(backup);
	
	report_tests();
	return 0;
}

void array_random_fill(generic* to_fill,int size,generic min,generic max) {
	srandom(time(NULL));
	generic range = max-min;
	generic factor = range/RAND_MAX;
	int i;
	for (i=0; i < size; i++) {
		to_fill[i] = min + factor*random();
	}
}

generic* copy_of_array(generic* to_copy, int size) {
	int i;
	generic* to_return = malloc(size*sizeof(generic));
	for (i = 0; i < size; i++) {
		to_return[i] = to_copy[i];
	}
	return to_return;
}
