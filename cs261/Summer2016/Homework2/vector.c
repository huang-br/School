#include "vector.h"
#include <stdlib.h>
#include <time.h>

/*We can write functions the behave similar to constructors. This function
 * will return a pointer to a new vector of the given size.*/
vector* new_vector(int size) {
	vector* to_return = malloc(sizeof(vector));
	to_return->values = malloc(sizeof(TYPE)*size);
	to_return->size = size;
	return to_return;
}

/*We can write functions that behave like class methods, we just need to
 * pass in the pointer to the object in question as an additional argument.
 * */

/*eg: This function might have been vector::random_fill(min,max) in C++
 * This funtions fills in the vector with random values in the range
 * [min,max].*/
void vector_random_fill(vector* to_fill_ptr,TYPE min,TYPE max) {
	srandom(time(NULL));
	TYPE range = max-min;
	TYPE factor = range/RAND_MAX;
	int i;
	for (i=0; i < to_fill_ptr->size; i++) {
		to_fill_ptr->values[i] = min + factor*random();
	}
}

/*eg: This function might have been vector::copy() in C++
 * This function returns a pointer to a new vector that is a copy of the
 * first one.*/
vector* copy_of_vector(vector* to_copy_ptr) {
	return copy_of_sub_vector(to_copy_ptr,0,to_copy_ptr->size);
}

/*eg: This function might have been vector::sub_copy(begin,end) in C++
 * This function returns a pointer to a new vector that is a copy of the
 * values from indices [begin,end).*/
vector* copy_of_sub_vector(vector* to_copy_ptr,int begin,int end) {
	int i;
	vector* to_return = new_vector(end-begin);
	for (i = 0; i < to_return->size; i++) {
		to_return->values[i] = to_copy_ptr->values[begin+i];
	}
	return to_return;
}

/*This function behaves similar to a destructor in C++*/
void free_vector(vector* to_delete_ptr) {
	if (to_delete_ptr != NULL) {
		free(to_delete_ptr->values);
		free(to_delete_ptr);
	}
}
