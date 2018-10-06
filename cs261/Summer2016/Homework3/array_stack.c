#include "stack.h"

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct stack {
	/*TODO: declare what member fields you need to implement an array stack.*/
	TYPE *data;
	int size;
	int capacity;
} stack;

/*Dynamically allocate memory to a stack*, initialiaze whatever fields you
 * need to, (including dynamically allocating more memory if you need to),
 * and return the pointer.*/
stack* new_stack() {
	/*TODO: Implement this function.*/
	stack *s = (stack *)malloc(sizeof(stack));
	s -> size = 0;
	s -> capacity = 50;
	s -> data = (TYPE*)malloc(sizeof(TYPE) * s -> capacity);
	assert(s -> data != 0);

	return s;
}

/*Return true if the stack pointed to by 'stack_p' has no elements in it,
 * false otherwise.*/
bool is_empty(stack* stack_p) {
	/*TODO: Implement this function.*/
	if(stack_p -> size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*Put element 'to_push' on top of the stack pointed to by 'stack_p'*/
void push(stack* stack_p, TYPE to_push) {
	/*TODO: Implement this function.*/
	if(stack_p -> size >= stack_p -> capacity)
	{
		/*All the old data*/
		TYPE *oldbuffer = stack_p -> data;
		int oldsize = stack_p -> size;
		int newCap = 2*(stack_p -> size);
		int k;

		/*Creating Memory for double the size*/
		stack_p -> data = (TYPE*) malloc(sizeof(TYPE) * newCap);
		assert(stack_p -> data != 0);
		stack_p -> capacity = newCap;

		/*remaking the old data in the new array*/
		for(k=0; k < oldsize; k++)
		{
			stack_p -> data[k] = oldbuffer[k];
		}
		free(oldbuffer);
	}

	/*adding the new data*/
	stack_p -> data[stack_p -> size] = to_push;
	stack_p -> size++;
}

/*Return the element on top of the stack pointed to by 'stack_p'*/
TYPE top(stack* stack_p) {
	/*TODO: Implement this function.*/

	return stack_p -> data[stack_p -> size -1];
}

/*Remove the element on top of the stack pointed to by 'stack_p' and return
 * it.*/
TYPE pop(stack* stack_p) {
	/*TODO: Implement this function.*/
	TYPE hold = stack_p -> data[stack_p -> size -1];
	stack_p -> size--;
	return hold;
}

/*Free all dynamically allocated memory associated with the stack pointed to
 * by 'stack_p' : YOU MAY LEAVE THIS BLANK FOR FULL CREDIT.
 * Doing this correctly will yield extra credit.*/
void free_stack(stack* stack_p) {
	/*TODO: Implement this function.*/
	if(stack_p -> data != 0)
	{
		free(stack_p -> data);
		stack_p -> data = 0;
	}
	stack_p -> size = 0;
	stack_p -> capacity = 0;

	free(stack_p);
}
