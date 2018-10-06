#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cirListDeque.h"

/* internal functions interface */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, struct DLink *newLnk);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);

/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void initCirListDeque (struct cirListDeque *q) 
{
	/* FIX ME*/
	struct DLink *sentinel = (struct DLink*)malloc(sizeof(struct DLink));

	assert(sentinel != 0);

	sentinel -> next = sentinel;
	sentinel -> prev = sentinel;
	q -> Sentinel = sentinel;
	q -> size = 0;
	q -> Sentinel -> value = NULL;

}

/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/* FIX ME*/
	struct DLink *lnk = malloc(sizeof(struct DLink));
	assert(lnk != 0);
	lnk -> value = val;

	return lnk;
}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	newLnk	pointer to the new link to add after the existing link
	pre:	q is not null
	pre: 	lnk and newLnk are not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, struct DLink *newLnk)
{
	/* FIX ME */
	newLnk -> next = lnk -> next;
	lnk -> next -> prev = newLnk;
	newLnk -> prev = lnk;
	lnk -> next = newLnk;
	q -> size++;
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	/* FIX ME*/
	_addLinkAfter(q, q -> Sentinel -> prev, _createLink(val));

}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	/* FIX ME*/
	_addLinkAfter(q, q -> Sentinel, _createLink(val));
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	/* FIX ME*/
	TYPE val = q -> Sentinel -> next -> value;
	return val;
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	/* FIX ME*/
	TYPE val = q -> Sentinel -> prev -> value;
	return val;
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	pre:	lnk is in the deque 
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	/* FIX ME*/
	lnk -> prev -> next = lnk -> next;
	lnk -> next -> prev = lnk -> prev;
	free(lnk);

	q -> size--;
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIX ME*/
	_removeLink(q, q -> Sentinel -> next);
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
	/* FIX ME*/
	_removeLink(q, q -> Sentinel -> prev);
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including backSentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	/* FIX ME*/
	struct DLink *lnk;
	assert(!isEmptyCirListDeque(q));
	int check = isEmptyCirListDeque(q);

	while(check == 0)
	{
		removeFrontCirListDeque(q);
		check = isEmptyCirListDeque(q);
	}
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
	/* FIX ME*/
	if(q -> size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	/* FIX ME*/
	struct DLink *temp = q -> Sentinel;
	while(temp -> next -> value != q -> Sentinel -> value)
	{
		temp = temp -> next;
		printf("The number is %d.\n", temp -> value);
	}

}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	/* FIX ME*/
	struct DLink *var1, *var2;
	var1 = q -> Sentinel -> next;
	q -> Sentinel -> prev = var1;
		
	while(var1 != q -> Sentinel)
	{
		var2 = var1 -> next;
		if(var2 -> next == q -> Sentinel)
		{
			q -> Sentinel -> next = var2;
		}
		var1 -> next = var1 -> prev;
		var1 -> prev = var2;
		var1 = var2;
	}

}
