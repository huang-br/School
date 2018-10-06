#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "skipList.h"
#include <time.h>	


/* ************************************************************************
Main Function
 ************************************************************************ */
/* Test function:
 param: no parameters
 pre:	no parameres
 post: prints out the contents of the skip list */

void test()
{
	int i;
	srand(time(NULL));
	
	/*  FIX ME */
	
	/*  Initialize the skip list */
	struct skipList *sL = (struct skipList*)malloc(sizeof(struct skipList));
	initSkipList(sL);

	/*  Add to the skip list  M = 20 random integers in [0,100] */
	for(i = 0; i < 20; i++)
	{
		addSkipList(sL, rand() %101);
	}

	addSkipList(sL, 50);
	
	/*  Print out the contents of the skip list in the breadth-first order, starting from top. 
	 While printing the elements, move to a new line every time you reach the end of one level, 
	 and move down to the lower level of the skip list. 
	 For example, the print out of a skip list with 5 elements should look like
	
	 7
	 7 14 29
	 3 7 9 14 20
	 
	 */
	printSkipList(sL);
	
	/* Develop test cases for evaluating the following functions:  
	 int containsSkipList(struct skipList *slst, TYPE e) 
	 int removeSkipList(struct skipList *slst, TYPE e)
	 */

	/*Testing contains*/
	int test = containsSkipList(sL, 50);
	if(test == 1)
	{
		printf("This list contains 50.\n");
	}

	printf("\n"); 
	/*After removing*/
	removeSkipList(sL, 50);
	printf("After removing the number 50.\n");
	test = containsSkipList(sL, 50);
	if(test == 0)
	{
		printf("This list does not contain 50.\n");
	}

	printSkipList(sL);
	
}


/* ************************************************************************
Internal Functions
 ************************************************************************ */

/* Coin toss function:
 param: no parameters
 pre:	no parameres
 post: output is a random intiger number in {0,1} */
int flipSkipLink(void)
{
	/*  FIX ME */
	int flip;
	flip = rand() %2;
	return flip;	
}

/* Move to the right as long as the next element is smaller than the input value:
 param: current -- pointer to a place in the list from where we need to slide to the right
 param:	e --  input value
 pre:	current is not NULL
 post: returns one link before the link that contains the input value e */
struct skipLink * slideRightSkipList(struct skipLink *current, TYPE e)
{
	assert(current);
	while ((current->next != 0) && LT(current->next->value, e))
	{
		current = current->next;
	}

	return current;
	/* FIX ME */
}


/* Create a new skip link for a value
	param: e	 -- the value to create a link for
	param: nextLnk	 -- the new link's next should point to nextLnk
	param: downLnk -- the new link's down should point to downLnk
	pre:	none
	post:	a link to store the value */
struct skipLink* newSkipLink(TYPE e, struct skipLink * nextLnk, struct skipLink* downLnk) {
	struct skipLink * tmp = (struct skipLink *) malloc(sizeof(struct skipLink));
	assert(tmp != 0);
	tmp->value = e;
	tmp->next = nextLnk;
	tmp->down = downLnk;
	return tmp;
}


/* Add a new skip link recursively
 param: current -- pointer to a place in the list where the new element should be inserted
 param: e	 -- the value to create a link for
 pre:	current is not NULL
 post: a link to store the value */
struct skipLink* skipLinkAdd(struct skipLink * current, TYPE e) {
	struct skipLink *newLink, *downLink;
	newLink = 0;
	if (current->down == 0) {
		newLink = newSkipLink(e, current->next, 0);
		current->next = newLink;
	}
	else {
		downLink = skipLinkAdd(slideRightSkipList(current->down, e), e);
		if (downLink != 0 && flipSkipLink()) {
			newLink = newSkipLink(e, current->next, downLink);
			current->next = newLink;
		}
	}
	return newLink;
}


/* ************************************************************************
Public Functions
 ************************************************************************ */

/* Initialize skip list:
 param:  slst -- pointer to the skip list
 pre:	slst is not null
 post: the sentinels are allocated, the pointers are set, and the list size equals zero */
void initSkipList (struct skipList *slst) 
{
	/* FIX ME*/
	struct skipLink *frontSentinel = (struct skipLink*) malloc(sizeof(struct skipLink));
	struct skipLink *backSentinel = (struct skipLink*) malloc(sizeof(struct skipLink));

	slst -> topSentinel = frontSentinel;
	slst -> size = 0;
	frontSentinel -> next = backSentinel;
	frontSentinel -> down = NULL;
	backSentinel -> next = NULL;
}

/* Checks if an element is in the skip list:
 param: slst -- pointer to the skip list
 param: e -- element to be checked
 pre:	slst is not null
 post: returns true or false  */
int containsSkipList(struct skipList *slst, TYPE e)
{
	/* FIX ME*/
	assert(slst);
	struct skipLink *current = slst->topSentinel;

	while(current)
	{
		current = slideRightSkipList(current, e);
		if(current -> next != 0 && EQ(current -> next -> value, e))
		{
			return 1;
		}

		current = current -> down;
	}
	return 0;
}


/* Remove an element from the skip list:
 param: slst -- pointer to the skip list
 param: e -- element to be removed
 pre:	slst is not null
 post: the new element is removed from all internal sorted lists */
void removeSkipList(struct skipList *slst, TYPE e)
{
	/* FIX ME*/
	assert(slst);
	struct skipLink *current, *temp;
	current = slst -> topSentinel;

	while(current)
	{
		current = slideRightSkipList(current, e);
		if(current -> next != 0 && EQ(current -> next -> value, e))
		{
			temp = current -> next;
			current -> next = current -> next -> next;
			free(temp);
			if(current -> down == NULL)
			{
				slst -> size--;
			}
		}
		current = current -> down;
	}
}


/* Add a new element to the skip list:
	param: slst -- pointer to the skip list
	param: e -- element to be added
	pre:	slst is not null
	post:	the new element is added to the lowest list and randomly to higher-level lists */
void addSkipList(struct skipList *slst, TYPE e)
{
	struct skipLink *downLink, *newLink;
	downLink = skipLinkAdd(slideRightSkipList(slst->topSentinel,e),e);

	if(downLink && flipSkipLink())
	{
		/*making the new link*/
		newLink = newSkipLink(e, 0, downLink);

		/*making the new top sentinel*/
		slst -> topSentinel = newSkipLink(0, newLink, slst->topSentinel);
	}
	slst -> size++;		
	/* FIX ME*/

}



/* Find the number of elements in the skip list:
 param: slst -- pointer to the skip list
 pre:	slst is not null
 post: the number of elements */
int sizeSkipList(struct skipList *slst)
{	
	/* FIX ME*/
	return slst -> size;	
}

/* Print the links in the skip list:
	param: slst -- pointer to the skip list
	pre:	slst is not null and slst is not empty
	post: the
       	links in the skip list are printed breadth-first, top-down */
void printSkipList(struct skipList *slst)
{
	/* FIX ME*/
	struct skipLink *top = slst -> topSentinel;
	struct skipLink *current;

	while(top != NULL)
	{
		current = top -> next;
		while(current -> next != NULL)
		{
			printf("%g ", current -> value);
			current = current -> next;
		}
		printf("\n");
		top = top -> down;
	}
}

/* Merge two skip lists, by adding elements of skip list 2 to skip list 1 
   that are not already contained in skip list 1. 
   The function is also supposed to remove the entire skip list 2 from the memory.
   param: slst1 -- pointer to the skip list 1
   param: slst2 -- pointer to the skip list 2
   pre: slst1 and slst2 are not null, and skip list 1 and skip list 2 are not empty
   post: slst1 points to the merger skip list,  slst2 is null*/
void mergeSkipList(struct skipList *slst1, struct skipList *slst2)
{
	/* FIX ME*/
	struct skipLink *current = slst2 -> topSentinel;
	while(current -> down != NULL)
	{
		current = current -> down;
	}

	while(current -> next != NULL)
	{
		if(!containsSkipList(slst1, current -> next -> value))
		{
			addSkipList(slst1, current -> next -> value);
			current = current -> next;
		}
		else
		{
			current = current -> next;
		}
	}
}
