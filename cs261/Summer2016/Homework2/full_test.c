#include "full_test.h"
#include "vector.h"
#include "bubble_sort.h"
#include "shell_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*This program will grade the non-written portion of this assignment.
 * There are no command line arguments used. The program performs a
 * stress test on each algorithm and then tests it against a relatively
 * large vector of values.*/
int main(int argc, char** argv) {
	
	const char* sort_names[3] = {	"bubble_sort",
									"shell_sort",
									"quick_sort"};
	/*These are function pointers; well outside what you need to know for this
	 * course, but they make iterating over your functions easier.*/
	void (*sort_fns[3])(vector*) = {bubble_sort,
									shell_sort,
									quick_sort};
	const int biggest_test_size[3] = {	10000,
										1000000,
										100};
	const int stress_test_size = 2500;

	int i,score,total;
	total = 0;
	for (i = 0; i < 3; i++) {
		score = 0;
		/*Stress test*/
		score += stress_test(sort_fns[i],sort_names[i],stress_test_size);
		/*Test on large vector*/
		score += big_test(sort_fns[i],sort_names[i],biggest_test_size[i]);
		printf("Score for %s: %d/25\n\n",sort_names[i],score);
		total += score;
	}
	printf("\nTotal score: %d/75 (There are 25 more points for written portion).\n",total);
	return 0;
}

/*The stress test checks for correctness a large number of times, but on
 * relatively small vectors. Note that you expected to handle vectors of size
 * zero and one.*/
int stress_test(void (*sort_fn)(vector*),const char* sort_name,const int size) {
	int score = 15;
	int order_fail = 0;
	int change_fail = 0;
	int i;
	printf("Performing stress test on %s  ...\n",sort_name);
	for (i=0; i <= size; i++) {
		int err_code = single_test(sort_fn,i);
		if (err_code == 1 || err_code == 3) order_fail++;
		if (err_code == 2 || err_code == 3) change_fail++;
	}
	if ((order_fail + change_fail) == 0) {
		printf("\t... %s committed no errors.\n",sort_name);
	} else {
		double order_fail_rate = ((1.0)*order_fail)/(size+1);
		double change_fail_rate = ((1.0)*change_fail)/(size+1);
		int order_penalty = (int)ceil(15.0*order_fail_rate);
		int change_penalty = (int)ceil(15.0*change_fail_rate);
		order_fail_rate *= 100;
		change_fail_rate *= 100;
		int final_penalty = (order_penalty < change_penalty)?change_penalty:order_penalty;
		printf("\t... %s did not put elements in ascending order about %3.3f%% of the time.\n",sort_name,order_fail_rate);
		printf("\t... %s changed the original values about %3.3f%% of the time.\n",sort_name,change_fail_rate);
		printf("\t\t\tFinal Penalty: %d\n",-final_penalty);
		score -= final_penalty;
	}
	return score;
}

/*The big test checks for correctness on one large vector.*/
int big_test(void (*sort_fn)(vector*),const char* sort_name,const int size) {
	int score = 10;
	printf("Checking %s on %d elements ...\n",sort_name,size);
	int err_code = single_test(sort_fn,size);
	if (err_code == 0) {
		printf("\t... %s sorted correctly.\n",sort_name);
	} else {
		if (err_code == 1 || err_code == 3) {
			printf("\t... %s did not put elements in ascending order.\n",sort_name);
		}
		if (err_code == 2 || err_code == 3) {
			printf("\t... %s changed the original values.\n",sort_name);
		}
		printf("\t\t\tPenalty: -10\n");
		score -= 10;
	}
	return score;
}

/*This is a silent run of a single test.*/
int single_test(void (*sort_fn)(vector*),const int size) {
	vector* to_sort_ptr = new_vector(size);
	vector_random_fill(to_sort_ptr,-1000,1000);
	vector* correct_ptr = copy_of_vector(to_sort_ptr);
	merge_sort(correct_ptr);
	sort_fn(to_sort_ptr);
	vector* backup_ptr = copy_of_vector(to_sort_ptr);
	merge_sort(backup_ptr);
	int err_code = 0;
	int i;
	for (i = 0; i < correct_ptr->size; i++) {
		if (i >= backup_ptr->size || backup_ptr->values[i] != correct_ptr->values[i]) {
			err_code += 2;
			break;
		}
	}
	for (i=1; i < to_sort_ptr->size; i++) {
		if (to_sort_ptr->values[i] < to_sort_ptr->values[i-1]) {
			err_code++;
			break;
		}
	}
	return err_code;
}
