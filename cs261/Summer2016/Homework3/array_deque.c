#include "deque.h"


#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/*The array version of the deque only needs an array, a record of the array's
 * size, and indices indicatinf the front and back.*/
typedef struct deque {
	TYPE* values;
	int capacity;
	int front_idx;
	int back_idx;
} deque;

/*Dynamically allocate memory to a deque*, initialiaze whatever fields you
 * need to, (including dynamically allocating more memory if you need to),
 * and return the pointer.*/
deque* new_deque() {
	deque* to_return = malloc(sizeof(deque));
	to_return->values = malloc(20*sizeof(TYPE));
	to_return->capacity = 20;
	(*to_return).front_idx = 9;
	to_return->back_idx = 10;
	return to_return;
}

/*Return true if the deque pointed to by 'deque_p' has no elements in it,
 * false otherwise.*/
bool is_empty(deque* deque_p) {
	assert(deque_p != NULL);
	return (deque_p->back_idx - deque_p->front_idx) <= 1;
}

/*Put element 'to_add' at the front of the deque pointed to by 'deque_p'*/
void add_front(deque* deque_p, TYPE to_add) {
	assert(deque_p != NULL);
	if (deque_p->front_idx < 0) {/*We need to grow our array.*/
		int new_capacity = 2*deque_p->capacity;
		TYPE* new_values = malloc(new_capacity*sizeof(TYPE));
		int i;
		for (i=0; i<deque_p->back_idx; i++) {
			new_values[i+deque_p->capacity] = deque_p->values[i];
		}
		free(deque_p->values);
		deque_p->values = new_values;
		deque_p->front_idx += deque_p->capacity;
		deque_p->back_idx += deque_p->capacity;
		deque_p->capacity = new_capacity;
	}
	/*Typical case. If the array needed to be expanded, the above code should
	 * have set everything so that the basic add operation now succeeds.*/
	deque_p->values[deque_p->front_idx] = to_add;
	deque_p->front_idx -= 1;
}

/*Return the element at the front of the deque pointed to by 'deque_p'*/
TYPE front(deque* deque_p) {
	assert(!is_empty(deque_p));
	return deque_p->values[deque_p->front_idx+1];
}

/*Remove the element at the front of the deque pointed to by 'deque_p' and return
 * it.*/
TYPE remove_front(deque* deque_p) {
	TYPE to_return = front(deque_p);
	deque_p->front_idx += 1;
	return to_return;
}

/*Put element 'to_add' at the back of the deque pointed to by 'deque_p'*/
void add_back(deque* deque_p, TYPE to_add) {
	assert(deque_p != NULL);
	if (deque_p->back_idx >= deque_p->capacity) {/*We need to grow our array.*/
		int new_capacity = 2*deque_p->capacity;
		TYPE* new_values = malloc(new_capacity*sizeof(TYPE));
		int i;
		for (i=(deque_p->front_idx)+1; i<deque_p->back_idx; i++) {
			new_values[i] = deque_p->values[i];
		}
		free(deque_p->values);
		deque_p->values = new_values;
		deque_p->capacity = new_capacity;
	}
	/*Typical case. If the array needed to be expanded, the above code should
	 * have set everything so that the basic add operation now succeeds.*/
	deque_p->values[deque_p->back_idx] = to_add;
	deque_p->back_idx += 1;
}

/*Return the element at the back of the deque pointed to by 'deque_p'*/
TYPE back(deque* deque_p) {
	assert(!is_empty(deque_p));
	return deque_p->values[deque_p->back_idx - 1];
}

/*Remove the element at the back of the deque pointed to by 'deque_p' and return
 * it.*/
TYPE remove_back(deque* deque_p) {
	TYPE to_return = back(deque_p);
	deque_p->back_idx -= 1;
	return to_return;
}

/*Free all dynamically allocated memory associated with the deque pointed to
 * by 'deque_p' : YOU MAY LEAVE THIS BLANK FOR FULL CREDIT.
 * Doing this correctly will yield extra credit.*/
void free_deque(deque* deque_p) {
	if (deque_p != NULL) {
		free(deque_p->values);
	}
	free(deque_p);
}
