#include "listbag.h"
#include <assert.h>
#include "type.h"
#include <stdlib.h>

/*Bag interface*/
/* Function to initialize bag:
	Pre: b is not null
	Post: list implementing the bag is initialized, size = 0
*/
void initBag(struct bag* b){
	assert( b != NULL);
	b->l = (struct list*)malloc(sizeof(struct list));/*Allocate for the list implementing the bag*/
	initList(b->l);/*Initialize list*/
}

/* Function to add an element to the bag:
	Pre: b is not null
	Post: val is added to the bag ie the list implementing the bag*/
void addToBag(struct bag* b, TYPE val){
 	/*FIX ME*/
	addFrontList(b -> l, val);
}

/* Function to remove an element from the bag:
	Pre: b is not null
	Post: Element (if found) removed from bag/list
*/
void removeFromBag(struct bag* b, TYPE val){
	/*FIX ME*/
	listRemove(b -> l, val);
}

/*Function to test if an element exists in the bag
	Pre: b is not null
*/
int bagContains(struct bag* b, TYPE val){
	/* FIX ME*/
	return listContains(b -> l, val);
}

/*Function to test if the bag is empty
	Pre: b is not null
*/

int isEmptyBag(struct bag* b){
	/* FIX ME*/
	if(b -> l -> size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

void freeBag(struct bag *b)
{
    /* FIX ME*/
	free(b);
}

