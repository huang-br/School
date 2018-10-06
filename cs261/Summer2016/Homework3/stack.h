#ifndef STACK_H
#define STACK_H

#ifndef TYPE
#define TYPE int
#endif/*ndef TYPE*/

#include <stdbool.h>

/*The stack header file is agnostic to what members the stack has.*/
typedef struct stack stack;

/*Dynamically allocate memory to a stack*, initialiaze whatever fields you
 * need to, (including dynamically allocating more memory if you need to),
 * and return the pointer.*/
stack* new_stack();

/*Return true if the stack pointed to by 'stack_p' has no elements in it,
 * false otherwise.*/
bool is_empty(stack* stack_p);

/*Put element 'to_push' on top of the stack pointed to by 'stack_p'*/
void push(stack* stack_p, TYPE to_push);

/*Return the element on top of the stack pointed to by 'stack_p'*/
TYPE top(stack* stack_p);

/*Remove the element on top of the stack pointed to by 'stack_p' and return
 * it.*/
TYPE pop(stack* stack_p);

/*Free all dynamically allocated memory associated with the stack pointed to
 * by 'stack_p' : YOU MAY LEAVE THIS BLANK FOR FULL CREDIT.
 * Doing this correctly will yield extra credit.*/
void free_stack(stack* stack_p);

#endif/*ndef STACK_H*/
