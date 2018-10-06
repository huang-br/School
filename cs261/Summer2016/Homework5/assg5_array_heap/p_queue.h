#ifndef P_QUEUE_H
#define P_QUEUE_H

#ifndef TYPE
#define TYPE float
#endif/*ndef TYPE*/
typedef TYPE generic;

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/* Public Struct */
typedef struct {
	generic* heap;/*An array implementation of a heap binary tree.*/
	int capacity;/*Knowledge of the heap's maximum size.*/
	int open_index;/*Track the index of the next available node location.*/
	bool is_min_heap;/*Flag true if this is a min-heap, false for max-heap.*/
} p_queue;

typedef struct {
	generic* array;		/*Should point to the same array inside the parent priority queue.*/
	int size;			/*Indicates how many elements are in the queue.*/
	int cursor;			/*A cursor for indicating which element is next.*/
} iterator;
/* End Public Struct */

/* Memory Management */
p_queue* new_p_queue(bool is_min_heap);
iterator* get_pq_iterator(p_queue* pq);
void free_p_queue(p_queue* pq);
void free_iterator(iterator* itr);
/* End Memory Management */

/* Priority Queue ADT */
bool is_empty(p_queue* pq);
void pq_add(p_queue* pq, generic e);
generic pq_front(p_queue* pq);
generic pq_remove_front(p_queue* pq);
/* End Priority Queue ADT */

/* Iterator ADT */
bool has_next(iterator* itr);
generic next(iterator* itr);
/* End Iterator ADT */

/* Additional Functions */
void inplace_heap_sort(generic* to_sort, int size);
/* End Additional Functions */

#endif/*ndef P_QUEUE_H*/
