#include "iterator.h"
#include "tree.h"

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

	/* Private Fields */
typedef struct iter_node {
	generic element;
	struct iter_node* next;
} iter_node;

typedef struct iterator {
	iter_node* front;
	iter_node* back;
} iterator;
	/* End Private Fields */

	/* Private Function Prototypes */
iterator* new_iterator();
void add_to_iterator(iterator* itr, generic el);
void add_preorder(tree_node* t, iterator* itr);
void add_inorder(tree_node* t, iterator* itr);
void add_postorder(tree_node* t, iterator* itr);
	/* End Private Function Prototypes */

/*NOTE: This module contains a lot of the functionality for producing and
 * using iterators built from your tree. What is not filled in are recursive
 * private functions meant to fill in an iterator with a specified tree
 * traversal.
 *
 * These iterators are not ideal, but are meant to be easy to understand and
 * use. They work by simply filling up a queue with copies of each element.
 * As you would guess, this is not memory efficient, but it is a
 * straightforward way to ask you to code up each of the three commonly used
 * traversals.
 *
 * If you are really ambitious you may rewrite this entire module to be
 * more memory efficient as long as the public traversal functions return the
 * correct traversals, but I felt doing this correctly was beyond the
 * scope of the assignment.*/




	/* Memory Management */

/* This private constructor reveals that the iterator is to be a simple
 * queue that holds a copy of the original data.*/
iterator* new_iterator() {
	iterator* rval = malloc(sizeof(iterator));
	rval->front = NULL;
	rval->back = NULL;
	return rval;
}

/* This function frees up all memory associated with an iterator.*/
void free_iterator(iterator* itr) {
	if (itr != NULL) {
		iter_node* current = itr->front;
		while (current != NULL) {
			iter_node* to_free = current;
			current = current->next;
			free(to_free);
		}
		free(itr);
	}
}
	/* End Memory Management */




	/* Iterator ADT */

/* The has_next function is implemented here as a simple is_empty check on
 *	the queue.*/
bool has_next(iterator* itr) {
	assert(itr!=NULL);
	return itr->front != NULL;
}

/* The next function here is implemented as the remove_front function on a
 *	queue would be.*/
generic next(iterator* itr) {
	assert(has_next(itr));
	generic rval = itr->front->element;
	iter_node* to_free = itr->front;
	itr->front = itr->front->next;
	free(to_free);
	return rval;
}

/* This is a PRIVATE function that you may use here. It is identical to
 *	an add_back function on the iterator's queue. Use this function in
 *	the other functions below to fill up your iterators.*/
void add_to_iterator(iterator* itr, generic el) {
	assert(itr!=NULL);
	iter_node* next_node = malloc(sizeof(iter_node));
	next_node->element = el;
	next_node->next = NULL;
	if (itr->front == NULL) {
		itr->front = next_node;
	} else {
		itr->back->next = next_node;
	}
	itr->back = next_node;
}
	/* End Iterator ADT */




	/* Traversals */

/* This function is to return an iterator of the tree where the order the
 *	elements come out of the iterator are the preorder traversal of the
 *	tree.
 *
 *	This function is more or less finished for you, however it calls
 *	the function add_preorder which you must finish and works through
 *	most of the logic of the traversal.*/
iterator* tree_preorder_traversal(tree_node* t) {
	iterator* trav = new_iterator();
	add_preorder(t,trav);
	return trav;
}

/* This function is to fill up the given iterator with the elements from the
 *	given tree in a preorder traversal. It is expected that this function
 *	will work recursively; this is not a requirement, but it is likely to be
 *	MORE difficult to complete without recursion.*/
void add_preorder(tree_node* t, iterator* itr) {
	/*ASSIGN*/
	if(t == NULL)
	{
		return;
	}
	add_to_iterator(itr, t -> element);
	add_preorder(t -> left, itr);
	add_preorder(t -> right, itr);
}

/* This function is to return an iterator of the tree where the order the
 *	elements come out of the iterator are the inorder traversal of the
 *	tree.
 *
 *	This function is more or less finished for you, however it calls
 *	the function add_inorder which you must finish and works through
 *	most of the logic of the traversal.*/
iterator* tree_inorder_traversal(tree_node* t) {
	iterator* trav = new_iterator();
	add_inorder(t,trav);
	return trav;
}

/* This function is to fill up the given iterator with the elements from the
 *	given tree in an inorder traversal. It is expected that this function
 *	will work recursively; this is not a requirement, but it is likely to be
 *	MORE difficult to complete without recursion.*/
void add_inorder(tree_node* t, iterator* itr) {
	/*ASSIGN*/
	if(t == NULL)
	{
		return;
	}
	add_inorder(t -> left, itr);
	add_to_iterator(itr, t -> element);
	add_inorder(t -> right, itr);
}

/* This function is to return an iterator of the tree where the order the
 *	elements come out of the iterator are the postorder traversal of the
 *	tree.
 *
 *	This function is more or less finished for you, however it calls
 *	the function add_postorder which you must finish and works through
 *	most of the logic of the traversal.*/
iterator* tree_postorder_traversal(tree_node* t) {
	iterator* trav = new_iterator();
	add_postorder(t,trav);
	return trav;
}

/* This function is to fill up the given iterator with the elements from the
 *	given tree in a postorder traversal. It is expected that this function
 *	will work recursively; this is not a requirement, but it is likely to be
 *	MORE difficult to complete without recursion.*/
void add_postorder(tree_node* t, iterator* itr) {
	/*ASSIGN*/
	if(t == NULL)
	{
		return;
	}
	add_postorder(t -> left, itr);
	add_postorder(t -> right, itr);
	add_to_iterator(itr, t -> element);
}
	/* End Traversals */
