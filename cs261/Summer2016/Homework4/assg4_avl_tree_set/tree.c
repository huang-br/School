#include "tree.h"
#include "iterator.h"

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/* NOTE: Many of these functions expect to encounter NULL pointers! Read
 * carefully to be sure you are treating NULL correctly!*/


	/* Memory Management */

/* This constructor returns a pointer to a new tree node that contains the
 *	given element.*/
tree_node* new_tree_node(generic e) {
	/*TODO: Complete this function!*/
	struct tree_node *new = (struct tree_node*)malloc(sizeof(struct tree_node));
	assert(new != 0);

	new -> element = e;
	new -> left = 0;
	new -> right = 0;
	new -> size = 0;
	new -> height = 0;

	return new;
}

/* This function is expected to free the memory associated with a node and all
 *	of its descendants.*/
void free_tree(tree_node* t) {
	/*TODO: Complete this function!*/
	if(t != NULL)
	{
		free_tree(t -> left);
		free_tree(t -> right);
		free(t);
	}
}
	/* End Memory Management */




	/* Tree Storage and Access */

/* This function should return true if the given node or any of its
 *	descendants contain the given element, and false otherwise.
 *	If the given node pointer is NULL then this function is to return false.
 *	(Hint: Leverage the above expectation to keep this function simple and
 *	recursive)*/
bool tree_contains(tree_node* t, generic e) {
	/*TODO: Complete this function!*/
	while(t != NULL)
	{
		if(e == t -> element)
		{
			return true;
		}
		else if(e < t -> element)
		{
			t = t -> left;
		}
		else if(e > t -> element)
		{
			t = t -> right;
		}
	}
	return false;
}

/* This function is to add the given element to the tree defined by the given
 *	node. If the tree contains the element already, the tree is to be
 *	unchanged. Many of the unit tests assume that you are structuring your
 *	tree as a true binary search tree; getting this add function correct
 *	is crucial to passing most unit tests.
 *
 *	This function is expected to be recursive. It returns a pointer to a node
 *	as a convenience. (You may prefer to use scare quotes and say
 *	"convenience"). See set_add in set.c for an idea of what this looks like
 *	from the outside.
 *
 *	You may implement this function however you want (the actual return value
 *	of this function is never tested directly) but the intended strategy with
 *	passing a pointer back works as folows:
 *
 *	1) if t is NULL: return a pointer to new node containing the element.
 *	2) otherwise: return t (with exceptions, see below)
 *
 *	When calling this function recursively on a child of t, assign that
 *	child to the return value of recursive call.
 *
 *	eg: t->left = tree_add(t->left,e);
 *
 *	If the child is NULL, then it will be set to the new node. If it is not,
 *	it will remain the same, but will recursively pass this mandate to produce
 *	a new node onto its children/descendants.
 *
 *	The exception to the rules above are when you need to restructure the
 *	tree to keep it balanced; yet another reason to use this pointer
 *	returning convention.
 *
 *	The true rule to follow is that you are to return a pointer to the root
 *	of the tree that results from adding the element. Understanding this is
 *	probably crucial to implementing the AVL algorithm successfully.
 *
 *	Please discuss this concept on the Discussion Boards if you want help so
 *	you may all gain a better understanding of it.*/
tree_node* tree_add(tree_node* t, generic e) {
	/*TODO: Complete this function!*/
	if(tree_contains(t,e) == true)
	{
		return t;
	}
	else if(t == NULL)
	{
		struct tree_node *new = new_tree_node(e);
		return new;
	}
	else if(e < t -> element)
	{
		t -> left = tree_add(t -> left, e);
	}
	else if(e > t -> element)
	{
		t -> right = tree_add(t -> right, e);
	}
	return t;

}

/* This function is to remove the given element from the tree defined by the
 *	given node. If the tree does not contain the element, the tree is to be
 *	unchanged. Consider a NULL node to be an empty tree and return NULL
 *	gracefully.
 *
 *	There are several ways to correctly remove an element from a binary search
 *	tree and so the unit tests do not make assumptions about the resulting
 *	structure of your tree when you are done.
 *
 *	This function is expected to be recursive. It returns a pointer to a node
 *	as a convenience. (You may prefer to use scare quotes and say
 *	"convenience"). See set_remove in set.c for an idea of what this looks
 *	like from the outside.
 *
 *	You may implement this function however you want (the actual return value
 *	of this function is never tested directly). To better understand how the
 *	strategy is intended to work, read the notes on tree_add. Rules about
 *	what pointer to return are not as straightforward with tree_remove, but
 *	the guiding principle is the same:
 *
 *	Assign the value of your recursive calls to the child you called them on.
 *		eg:		t->right = tree_remove(t->right,e);
 *
 *	Return a pointer to the root of the resulting subtree after you have
 *	removed the element.
 *		eg:		If you are removing a leaf, return NULL.
 *				If you are removing a node with one child, return a pointer
 *					to that child.
 *				etc.
 *
 *	This function might prove the be the most challenging part of the
 *	assignment after the AVL algorithm.*/
tree_node* tree_remove(tree_node* t, generic e) {
	/*TODO: Complete this function!*/
	struct tree_node *hold;

	if(tree_contains(t,e) == false)
	{
		return NULL;
	}

	else if(t -> element == e)
	{
		if(t -> right == NULL)
		{
			hold = t -> left;
			free(t);
			return hold;
		}
		else
		{
			hold = t -> right;
			while(hold -> left != NULL)
			{
				hold = hold -> left;
			}

			t -> element = hold -> element;
			hold -> element = 0;
			return t;
		}
	}
	else if(e > t -> element)
	{
		return t -> right = tree_remove(t -> right, e);
	}

	else if(e < t -> element)
	{
		return t -> left = tree_remove(t -> left, e);
	}
	else
	{
		return NULL;
	}
}
	/* End Tree Storage and Access */




	/* Size and Index */

/* Return the size of the tree rooted at the given node.
 *	The size of a tree is the number of nodes it contains.
 *	This function should work on subtrees, not just the root.
 *	If t is NULL, it is to be treated as an empty tree and you should
 *	return 0.
 *	A single node is a tree of size 1.*/
int tree_size(tree_node* t) {
	/*TODO: Complete this function!*/
	if(t == NULL)
	{
		return 0;
	}
	else
	{
		return tree_size(t -> left) + tree_size(t -> right) + 1;
	}	
}

/* Return the element at the given index in the given tree.
 *	To be clear, imagine the tree is a sorted array, and you are
 *	to return the element at the given index.
 *
 *	Assume indexing is zero based; if index is zero then the minimum
 *	element should be returned, for example. If index is one then
 *	the second smallest element should bereturned, and so on.*/
generic tree_get_at_index(tree_node* t, int index) {
	assert(index >=0 && index < tree_size(t));
	/*TODO: Complete this function!*/
	iterator *list = tree_inorder_traversal(t);
	int k;
	generic num = 0.0;
	for(k=0; k <= index; k++)
	{
		if(!(has_next(list)))
			break;
		num = next(list);
	}
	return num;
}
	/* End Size and Index */




	/* AVL Balancing Functions */

/* Return the height of the tree rooted at the given node.
 *	The height of a tree is the maximum path length from itself to a
 *	leaf descendant.
 *	This function should work on subtrees, not just the root.
 *	If t is NULL, it is to be treated as an empty tree and you should
 *	return -1.
 *	A single node is a tree of height 0.*/
int tree_height(tree_node* t) {
	/*TODO: Complete this function!*/
	return 0;
}

/* NOTE: The remaining functions are not required. tree_height is explicitly
 * tested by the AVL unit test, but these functions are merely suggestions
 * for how to organize your code. As such they have no documentation; either
 * you have a plan for how you might use them, or you don't.
 *
 * Passing the AVL unit test is a matter of keeping the height of your tree
 * under sqrt(2)*log(n), where n is the size of the tree.*/

tree_node* rebalance(tree_node* t) {
	/*TODO: Complete this function! Maybe!*/
	return NULL;
}

tree_node* rotate_left(tree_node* t) {
	/*TODO: Complete this function! Maybe!*/
	return NULL;
}

tree_node* rotate_right(tree_node* t) {
	/*TODO: Complete this function! Maybe!*/
	return NULL;
}

bool left_is_heavy(tree_node* t) {
	/*TODO: Complete this function! Maybe!*/
	return false;
}

bool right_is_heavy(tree_node* t) {
	/*TODO: Complete this function! Maybe!*/
	return false;
}
	/* End AVL Balancing Functions */
