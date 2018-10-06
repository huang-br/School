#ifndef ITERATOR_H
#define ITERATOR_H

#ifndef TYPE
#define TYPE float
#endif/*ndef TYPE*/
typedef TYPE generic;

#include "tree.h"

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/* Public Fields */
typedef struct iterator iterator;
/* End Public Fields */

/* Memory Management */
void free_iterator(iterator* itr);
/* End Memory Management */

/* Iterator ADT */
TYPE next(iterator* itr);
bool has_next(iterator* itr);
/* End Iterator ADT */

/* Traversals */
iterator* tree_preorder_traversal(tree_node* t);
iterator* tree_inorder_traversal(tree_node* t);
iterator* tree_postorder_traversal(tree_node* t);
/* End Traversals */

#endif/*ndef ITERATOR_H*/
