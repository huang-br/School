#ifndef SET_H
#define SET_H

#ifndef TYPE
#define TYPE float
#endif/*ndef TYPE*/
typedef TYPE generic;

#include "tree.h"
#include "iterator.h"

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/* Public Fields */
typedef struct set {
	tree_node* root;
} set;
/* Public Fields */

/* Memory Management */
set* new_set();
void free_set(set* S);
/* End Memory Management */

/* Set ADT */
bool set_contains(set* S, generic e);
bool set_add(set* S, generic e);
bool set_remove(set* S, generic e);
int set_size(set* S);
iterator* get_set_iterator(set* S);
/* End Set ADT */

/* Set Operations */
set* set_union(set* A, set* B);
set* set_intersection(set* A, set* B);
set* set_difference(set* A, set* B);
bool set_is_subset(set* A, set* B);
/* End Set Operations */

#endif/*ndef SET_H*/
