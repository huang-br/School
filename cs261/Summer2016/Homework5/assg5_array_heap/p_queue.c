#include "p_queue.h"

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>




	/* Public Struct */
/* POSTED IN COMMENTS FOR REFERENCE */
//typedef struct {
//	generic* heap;		/*An array implementation of a heap binary tree.*/
//	int capacity;		/*Knowledge of the heap's maximum size.*/
//	int open_index;		/*Track the index of the next available node location.*/
//	bool is_min_heap;	/*Flag true if this is a min-heap, false for max-heap.*/
//} p_queue;
//
//typedef struct {
//	generic* array;		/*Should point to the same array inside the parent priority queue.*/
//	int size;			/*Indicates how many elements are in the queue.*/
//	int cursor;			/*A cursor for indicating which element is next.*/
//} iterator;
	/* End Public Struct */




	/* Suggested Private Function Prototypes */
void grow_heap_array(p_queue* pq);
int left_child_index(int i);
int right_child_index(int i);
int parent_index(int i);
	/* End Suggested Private Function Prototypes */




	/* Memory Management */

/* This function should return a pointer to a new heap / priority queue.
 *	The boolean argument indicates whether the internal heap should be a
 *	min-heap (true) or a max-heap (false). This function must complete in
 *	constant time.
 *
 *	NOTE: This function has been completed for you.*/
p_queue* new_p_queue(bool is_min_heap) {
	p_queue* pq = malloc(sizeof(p_queue));
	pq->heap = malloc(7*sizeof(generic));
	pq->capacity = 7;
	pq->open_index = 0;
	pq->is_min_heap = is_min_heap;
	return pq;
}

/* This function should build a new iterator from the given parent priority
 * queue. The iterator should use the cursor strategy and constructing the
 * iterator must complete in constant time.*/
iterator* get_pq_iterator(p_queue* pq) {
	assert(pq != NULL);
	/*TODO: Complete this function.*/
	iterator *itr = malloc(sizeof(iterator));
	itr -> array = pq -> heap;
	itr -> size = pq -> capacity;
	itr -> cursor = pq -> open_index;
	return itr;
}

/* This function should make sure all memory associated with a priority
 * queue is freed. This function must complete in constant time.*/
void free_p_queue(p_queue* pq) {
	/*TODO: Complete this function.*/
	free(pq -> heap);
	free(pq);
}

/* This function should make sure all memory associated with an iterator is
 * freed. This function must complete in constant time.*/
void free_iterator(iterator* itr) {
	/*TODO: Complete this function.*/
	free(itr -> array);
	free(itr);
}
	/* End Memory Management */




	/* Priority Queue ADT */

/* Should return true if the given priority queue has size 0. Is not expected
 * to handle a NULL priority queue. This function must run in constant time.*/
bool is_empty(p_queue* pq) {
	assert(pq != NULL);
	/*TODO: Complete this function.*/
	if(pq -> open_index == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Should add the given element to the given priority queue. Must run in
 * logarithmic time except when the heap array needs to be resized. Must
 * correctly account for the priority queue having a min or max heap.
 *
 * If the heap array is full, you must handle resizing it before you add a
 * new element.
 *
 * The algorithm you must adhere to is that the next capacity must be
 * 		1 + 2*(current capacity)
 *
 * You may write the resizing code in grow_heap_array and call it from here
 * if you wish.*/
void pq_add(p_queue* pq, generic e) {
	assert(pq != NULL);
	/*TODO: Complete this function.*/
	pq -> heap[pq -> open_index] = e;
	int pos = pq -> open_index;
	int parent;

	if(pq -> open_index > pq -> capacity)
	{
		int k;
		int newcap = (2 * pq -> capacity) + 1;
		generic *temp = malloc(newcap * sizeof(generic));
		for(k = 0; k < pq -> capacity; k++)
		{
			temp[k] = pq -> heap[k];
		}
		free(pq -> heap);
		pq -> heap = temp;
		pq -> capacity = newcap;
	}
	pq -> open_index++;

	while(pos != 0)
	{
		generic hold;
		parent = (pos-1)/2;
		if(pq -> is_min_heap == true)
		{
			if(pq -> heap[pos] < pq -> heap[parent])
			{
				hold = pq -> heap[pos];
				pq -> heap[pos] = pq -> heap[parent];
				pq -> heap[parent] = hold;
				pos = parent;
			}
			else
			{
				return;
			}
		}

		else if(pq -> is_min_heap == false)
		{
			if(pq -> heap[pos] > pq -> heap[parent])
			{
				hold = pq -> heap[pos];
				pq -> heap[pos] = pq -> heap[parent];
				pq -> heap[parent] = hold;
				pos = parent;
			}
			else
			{
				return;
			}
		}
	}
}

/* Should return the root element of the priority queue. Must not change the
 * state of the queue. Must run in constant time.*/
generic pq_front(p_queue* pq) {
	assert(!is_empty(pq));
	/*TODO: Complete this function.*/
	return pq -> heap[0];
}

/* Should return the root element of the priority queue after removing it
 * from the front of the queue. Must run in logarithmic time. Must
 * correctly account for the priority queue having a min or max heap.*/
generic pq_remove_front(p_queue* pq) {
	assert(!is_empty(pq));
	/*TODO: Complete this function.*/
	generic value = pq_front(pq);
	pq -> open_index--;
	pq -> heap[0] = pq -> heap[pq -> open_index];
	int root = 0;
	while(root < pq -> open_index)
	{
		generic hold;
		if(pq -> is_min_heap == true)
		{
			if((pq -> heap[root] < pq -> heap[left_child_index(root)]) && (pq -> heap[root] < pq -> heap[right_child_index(root)]))
			{
				return value;
			}
			else
			{
				if(pq -> heap[left_child_index(root)] < pq -> heap[right_child_index(root)])
				{
					hold = pq -> heap[root];
					pq -> heap[root] = pq -> heap[left_child_index(root)];
					pq -> heap[left_child_index(root)] = hold;
					root = left_child_index(root);
				}
				else if(pq -> heap[left_child_index(root)] > pq -> heap[right_child_index(root)])
				{
					hold = pq -> heap[root];
					pq -> heap[root] = pq -> heap[right_child_index(root)];
					pq -> heap[right_child_index(root)] = hold;
					root = right_child_index(root);
				}
				else
				{
					return value;
				}

			}
		}
		else if(pq -> is_min_heap == false)
		{	
			if((pq -> heap[root] > pq -> heap[left_child_index(root)]) && (pq -> heap[root] > pq -> heap[right_child_index(root)]))
			{
				return value;
			}
			else
			{
				if(pq -> heap[left_child_index(root)] > pq -> heap[right_child_index(root)])
				{
					hold = pq -> heap[root];
					pq -> heap[root] = pq -> heap[left_child_index(root)];
					pq -> heap[left_child_index(root)] = hold;
					root = left_child_index(root);
				}
				else if(pq -> heap[left_child_index(root)] < pq -> heap[right_child_index(root)])
				{
					hold = pq -> heap[root];
					pq -> heap[root] = pq -> heap[right_child_index(root)];
					pq -> heap[right_child_index(root)] = hold;
					root = right_child_index(root);
				}
				else
				{
					return value;
				}
			}
		}
	}
	return value;
}
	/* End Priority Queue ADT */




	/* Iterator ADT */

/* Should return true if the iterator can return at least one more element
 * with the "next" function. Must complete in constant time.*/
bool has_next(iterator* itr) {
	assert(itr != NULL);
	/*TODO: Complete this function.*/
	if(itr -> array[itr -> cursor])
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Should return the next element in the iterator and update the cursor. Must
 * complete in constant time.*/
generic next(iterator* itr) {
	assert(has_next(itr));
	/*TODO: Complete this function.*/
	generic value = itr -> array[itr -> cursor];
	itr -> cursor++;

	return value;
}
	/* End Iterator ADT */




	/* Additional Functions */

/* You must implement the inplace heapsort algorithm. You can receive partial
 * credit for a not-inplace implementation. For full credit, this function
 * must not allocate any additional memory (no new objects).
 *
 * You are to rearrange the elements in the array "to_sort".
 * You may assume you will be given the correct size.*/
void inplace_heap_sort(generic* to_sort, int size) {
	assert((size > 0 && to_sort != NULL) || size == 0);
	/*TODO: Complete this function.*/

	return;
}
	/* End Additional Functions */




	/* Suggested Private Functions */

/*You are not required to implement the functions below but they are provided
 * as suggestions for how you might organize your code.*/

void grow_heap_array(p_queue* pq) {
	/*TODO: Complete this function if you wish.*/
	return;
}

int left_child_index(int i) {
	/*TODO: Complete this function if you wish.*/
	int left = (2 * i) + 1;
	return left;
}

int right_child_index(int i) {
	/*TODO: Complete this function if you wish.*/
	int right = (2 * 1) + 2;
	return right;
}

int parent_index(int i) {
	/*TODO: Complete this function if you wish.*/
	int parent = (i-1)/2;
	return parent;
}
	/* End Suggested Private Functions */
