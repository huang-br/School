#include "bubble_sort.h"
#include "vector.h"

void bubble_sort(vector* to_sort_ptr) {
	/*TODO: You are to implement the Bubble Sort algorithm here. (See course
	 * notes for algorithm details).
	 *
	 * This function does not return anything, instead you are to rearrange the
	 * elements in 'to_sort_ptr->values' into ascending order.
	 * 
	 * You may check the size of the vector with 'to_sort_ptr->size'.
	 * 
	 * The values are of type 'TYPE', which is a macro to be defined by the
	 * compiler, but you may assume it is numeric.
	 *
	 * The fields 'values' and 'size' may also be accessed with
	 * 		(*to_sort_ptr).values
	 * 			and
	 * 		(*to_sort_ptr).size
	 * respectively.
	 *
	 * You may also prefer to save the dereferenced pointer as a variable, eg:
	 * 		vector to_sort = *to_sort_ptr;
	 * at which point you may get to the needed fields with
	 * 		to_sort.values
	 * 			and
	 * 		to_sort.size
	 * respectively.
	 * */
	int x,y;
	int size = to_sort_ptr -> size;

	for(x=0; x<size; x++)
	{
		for(y=0; y<size-1; y++)
		{
			if(to_sort_ptr -> values[y] > to_sort_ptr -> values [y+1])
			{
				TYPE hold = to_sort_ptr -> values[y+1];
				to_sort_ptr -> values[y+1] = to_sort_ptr -> values[y];
				to_sort_ptr -> values[y] = hold;
			}
		}
	}
}
/******************************************************************************************************
 * 1) The best case for bubble sort is O(n) and the best case for insertion sort is also O(n).
 * 2) Shell sort with the gap size of 1 is the same thing as insertion sort.
 * 3) The memory complextiy for merge sort is O(n). Merge sort breaks the big array to a bunch of little
 *    size 1 arrays. Each array index needs some memory, so the complexity is O(n).
 * 4) The complextiy should still be O(n log n). Although there are steps saved by dividing the data into
 *    four parts it will still have the behavior of O(n log n).
*******************************************************************************************************/
