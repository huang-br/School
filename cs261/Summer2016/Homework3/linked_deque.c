#include "deque.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

typedef struct deque {
	/*TODO: declare what member fields you need to implement a linked deque.*/
	TYPE value;
	int size;
	struct deque *next;
	struct deque *prev;

} deque;

/*Dynamically allocate memory to a deque*, initialiaze whatever fields you
 * need to, (including dynamically allocating more memory if you need to),
 * and return the pointer.*/
deque* new_deque() {
	struct deque *dq = (deque *)malloc(sizeof(struct deque));
	dq -> size = 0;
	
	return dq;
}

/*Return true if the deque pointed to by 'deque_p' has no elements in it,
 * false otherwise.*/
bool is_empty(deque* deque_p) {
	/*TODO: Implement this function.*/
	if(deque_p -> size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*Put element 'to_add' at the front of the deque pointed to by 'deque_p'*/
void add_front(deque* deque_p, TYPE to_add) {
	/*TODO: Implement this function.*/
	struct deque *link = malloc(sizeof(struct deque));
	assert(link != 0);
	link -> value = to_add;

	if(is_empty(deque_p))
	{
		deque_p -> next = link;
		deque_p -> prev = link;
		deque_p -> size++;
	}
	else
	{
		deque_p -> next -> next = link;
		link -> prev = deque_p -> next;
		deque_p -> next = link;
		deque_p -> size++;
	}
}

/*Return the element at the front of the deque pointed to by 'deque_p'*/
TYPE front(deque* deque_p) {
	/*TODO: Implement this function.*/
	return deque_p -> next -> value;
}

/*Remove the element at the front of the deque pointed to by 'deque_p' and return
 * it.*/
TYPE remove_front(deque* deque_p) {
	/*TODO: Implement this function.*/
	TYPE val = deque_p -> next -> value;
	struct deque *temp = deque_p -> next;

	deque_p -> next = deque_p -> next -> prev;
	deque_p -> size--;

	free(temp);

	return val;
}

/*Put element 'to_add' at the back of the deque pointed to by 'deque_p'*/
void add_back(deque* deque_p, TYPE to_add) {
	/*TODO: Implement this function.*/
	struct deque *link = malloc(sizeof(struct deque));
	assert(link != 0);
	link -> value = to_add;

	if(is_empty(deque_p))
	{
		deque_p -> next = link;
		deque_p -> prev = link;
		deque_p -> size++;
	}
	else
	{
		deque_p -> prev -> prev = link;
		link -> next = deque_p -> prev;
		deque_p -> prev = link;
		deque_p -> size++;
	}
}

/*Return the element at the back of the deque pointed to by 'deque_p'*/
TYPE back(deque* deque_p) {
	/*TODO: Implement this function.*/
	return deque_p -> prev -> value;
}

/*Remove the element at the back of the deque pointed to by 'deque_p' and return
 * it.*/
TYPE remove_back(deque* deque_p) {
	/*TODO: Implement this function.*/
	TYPE val = deque_p -> prev -> value;
	struct deque *temp = deque_p -> prev;

	deque_p -> prev = deque_p -> prev -> next;
	deque_p -> size--;

	free(temp);

	return val;
}

/*Free all dynamically allocated memory associated with the deque pointed to
 * by 'deque_p' : YOU MAY LEAVE THIS BLANK FOR FULL CREDIT.
 * Doing this correctly will yield extra credit.*/
void free_deque(deque* deque_p) {
	/*TODO: Implement this function.*/

	bool check = is_empty(deque_p);
	while(check == false)
	{
		remove_front(deque_p);
		check = is_empty(deque_p);
	}

	free(deque_p);
}
