#ifndef DEQUE_H
#define DEQUE_H

#ifndef TYPE
#define TYPE int
#endif/*ndef TYPE*/

#include <stdbool.h>

/*The deque header file is agnostic to what members the deque has.*/
typedef struct deque deque;

/*Dynamically allocate memory to a deque*, initialiaze whatever fields you
 * need to, (including dynamically allocating more memory if you need to),
 * and return the pointer.*/
deque* new_deque();

/*Return true if the deque pointed to by 'deque_p' has no elements in it,
 * false otherwise.*/
bool is_empty(deque* deque_p);

/*Put element 'to_add' at the front of the deque pointed to by 'deque_p'*/
void add_front(deque* deque_p, TYPE to_add);

/*Return the element at the front of the deque pointed to by 'deque_p'*/
TYPE front(deque* deque_p);

/*Remove the element at the front of the deque pointed to by 'deque_p' and return
 * it.*/
TYPE remove_front(deque* deque_p);

/*Put element 'to_add' at the back of the deque pointed to by 'deque_p'*/
void add_back(deque* deque_p, TYPE to_add);

/*Return the element at the back of the deque pointed to by 'deque_p'*/
TYPE back(deque* deque_p);

/*Remove the element at the back of the deque pointed to by 'deque_p' and return
 * it.*/
TYPE remove_back(deque* deque_p);

/*Free all dynamically allocated memory associated with the deque pointed to
 * by 'deque_p' : YOU MAY LEAVE THIS BLANK FOR FULL CREDIT.
 * Doing this correctly will yield extra credit.*/
void free_deque(deque* deque_p);

#endif/*ndef DEQUE_H*/
