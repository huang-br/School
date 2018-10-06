#include "tree.h"
#include "set.h"
#include "iterator.h"

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>




	/* Memory Management */

/* This function allcates memory for a new set struct, initializes the root
 * 	pointer to NULL, and returns a pointer to the new set.*/
set* new_set() {
	set* rval = malloc(sizeof(set));
	rval->root = NULL;
	return rval;
}

/* This function frees all memory related to the given set.*/
void free_set(set* S) {
	if (S != NULL) {
		free_tree(S->root);
		free(S);
	}
}
	/* End Memory Management */




	/* Set ADT */

/* This function returns true if the given set contains the given element.
 * 	It determines this by checking if the tree rooted at root contains
 * 	the element.*/
bool set_contains(set* S, generic e) {
	assert(S != NULL);
	return tree_contains(S->root, e);
}

/* TODO: Complete this function!*/
/* This function will add the given element to the given set.
 * 	Further, this function is to return true or false depending on whether
 * 	the tree already contained the element. Specifically, return true if
 * 	the set is changed by adding the element and false if it is not,
 * 	(because it already contained the element).
 *
 * 	NOTE: Observe how the set updates its root by setting it to the return
 * 	value of tree_add. By extension, notice that tree_add returns a pointer
 * 	to a node. This means tree_add is expected to return the root of the
 * 	tree that results from adding the element.*/
bool set_add(set* S, generic e) {
	assert(S != NULL);
	/*TODO: Change this function so that it returns false if the tree already
	 *	contained the incoming element, and true otherwise.*/
	if((set_contains(S,e)))
	{
		return false;
	}
	else
	{
		S->root = tree_add(S->root,e);
		return true;
	}
}

/* TODO: Complete this function!*/
/* This function will remove the given element from the given set.
 * 	Further, this function is to return true or false depending on whether
 * 	the tree already contained the element. Specifically, return true if
 * 	the set is changed by removing the element and false if it is not,
 * 	(because it didn't contain the element anyway).
 *
 * 	NOTE: Observe how the set updates its root by setting it to the return
 * 	value of tree_add. By extension, notice that tree_add returns a pointer
 * 	to a node. This means tree_add is expected to return the root of the
 * 	tree that results from adding the element.*/
bool set_remove(set* S, generic e) {
	assert(S != NULL);
	/*TODO: Change this function so that it returns true if the tree
	 *	contained the outcoming element, and false otherwise.*/
	if(set_contains(S, e))
	{	
		S->root = tree_remove(S->root,e);
		return true;
	}
	else
	{	
		return false;
	}
}

/* This function returns the size of the set. It determines this by calling
 *	the function tree_size on its root.*/
int set_size(set* S) {
	assert(S != NULL);
	return tree_size(S->root);
}

/* This function returns an iterator for the set.
 * 	By default this function returns an iterator defined by the preorder
 * 	traversal as defined in iterator.c.
 *
 * 	NOTE: If you can't implement the preorder traversal but can get one of
 * 	the other traversals to work, you might want to change this function
 * 	to return that one instead.*/
iterator* set_get_iterator(set* S) {
	assert(S != NULL);
	return tree_preorder_traversal(S->root);
}
	/* End Set ADT */




	/* Set Operations */

/*TODO: Fill in this function!*/
/* This function is to allocate a NEW set and leave the given sets unchanged.
 * 	A pointer to this new set is returned. The new set is expected to
 * 	contain the union of the two given sets. (The union includes all elements
 * 	in both sets).*/
set* set_union(set* A, set* B) {
	assert(A != NULL && B != NULL);
	/*TODO: Fill in this function!*/
	set *C = new_set();
	iterator *a = set_get_iterator(A);
	iterator *b = set_get_iterator(B);

	while(has_next(a))
	{
		set_add(C,next(a));
	}
	while(has_next(b))
	{
		generic add = next(b);
		if(!(set_contains(C, add)))
		{
			set_add(C,add);
		}
	}

	return C;
}

/*TODO: Fill in this function!*/
/* This function is to allocate a NEW set and leave the given sets unchanged.
 * 	A pointer to this new set is returned. The new set is expected to
 * 	contain the intersection of the two given sets. (The intersection includes
 * 	only the elements both sets have in common).*/
set* set_intersection(set* A, set* B) {
	assert(A != NULL && B != NULL);
	/*TODO: Fill in this function!*/
	set *C = new_set();
	iterator *a = set_get_iterator(A);

	while(has_next(a))
	{
		iterator *b = set_get_iterator(B);
		generic compare = next(a);
		while(has_next(b))
		{
			generic compare2 = next(b);
			if(compare == compare2)
			{
				set_add(C,compare);
			}
		}
	}

	return C;
}

/*TODO: Fill in this function!*/
/* This function is to allocate a NEW set and leave the given sets unchanged.
 * 	A pointer to this new set is returned. The new set is expected to
 * 	contain the difference of the first set minus the second. (The 
 * 	difference is all the elements in the first set that are not in the
 * 	second set.).
 *
 * 	NOTE: Unlike the previous two functions, this operation is NOT
 * 	commutative; the order of the arguments matter!*/
set* set_difference(set* A, set* B) {
	assert(A != NULL && B != NULL);
	/*TODO: Fill in this function!*/
	set *C = new_set();
	iterator *a = set_get_iterator(A);

	while(has_next(a))
	{
		iterator *b = set_get_iterator(B);
		generic compare = next(a);
		while(has_next(b))
		{
			generic compare2 = next(b);
			if(compare != compare2)
			{
				set_add(C,compare);
			}
		}
	}

	iterator *b = set_get_iterator(B);
	while(has_next(b))
	{
		generic compare3 = next(b);
		if(!(set_contains(C,compare3)))
		{
			set_add(C,compare3);
		}
	}
	return C;
}

/*TODO: Fill in this function!*/
/* This function returns true if the first set is a subset of the second set.
 *	(A set is a subset of another if all of its elements are in the other
 *	set).
 *
 *	Put another way, this function should return true if ALL the elements in
 *	the first set are in the second set, and false otherwise.*/
bool set_is_subset(set* A, set* B) {
	assert(A != NULL && B != NULL);
	/*TODO: Fill in this function!*/
	/*iterator *a = set_get_iterator(A);
	generic compare = next(a);

	while(has_next(a))
	{
		iterator *b = set_get_iterator(B);
		generic compare2 = next(b);
		while(has_next(b))
		{
			compare2 = next(b);
			if(compare == compare2)
			{	
				compare = next(a);
				b = set_get_iterator(B);
			}
		}
		return false;
	}*/
	return true;
}
	/* End Set Operations */
