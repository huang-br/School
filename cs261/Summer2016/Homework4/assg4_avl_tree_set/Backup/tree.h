#ifndef TREE_H
#define TREE_H

#ifndef TYPE
#define TYPE float
#endif/*ndef TYPE*/
typedef TYPE generic;

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

/* Public Fields */
typedef struct tree_node {
	generic element;
	struct tree_node* left;
	struct tree_node* right;
	/*These fields are provided so you can store this info about each
	 * node. Efficient implementation will keep these figures accurate
	 * for each note each time the tree changes.*/
	int size;
	int height;
} tree_node;
/* End Public Fields */

/* Memory Management */
tree_node* new_tree_node(generic e);
void free_tree(tree_node* t);
/* End Memory Management */

/* Tree Storage and Access */
bool tree_contains(tree_node* t, generic e);
tree_node* tree_add(tree_node* t, generic e);
tree_node* tree_remove(tree_node* t, generic e);
/* End Tree Storage and Access */

/* Size and Index */
int tree_size(tree_node* t);
generic tree_get_at_index(tree_node* t, int index);
/* End Size and Index */

/* AVL Balancing Functions */
int tree_height(tree_node* t);
tree_node* rebalance(tree_node* t);
tree_node* rotate_left(tree_node* t);
tree_node* rotate_right(tree_node* t);
bool left_is_heavy(tree_node* t);
bool right_is_heavy(tree_node* t);
/* End AVL Balancing Functions */

#endif/*ndef TREE_H*/
