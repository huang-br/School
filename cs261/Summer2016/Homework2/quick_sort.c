#include "quick_sort.h"
#include "vector.h"

void quick_sort(vector* to_sort_ptr) {
	/*TODO: You are to implement the Quick Sort algorithm here. (See course
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
	 *
	 * You almost certainly will need to write other functions to complete this
	 * task. Any additional functions you write MUST have prototypes in
	 * "quick_sort.h"
	 * */
	sort(to_sort_ptr -> values, 0, to_sort_ptr -> size-1);
}

void sort(TYPE *array, int first, int last)
{
	int pivot,i,j;
	TYPE hold;

	if(first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while(i < j)
		{
			while(array[i] <= array[pivot] && i < first)
			{
				i++;
			}
			while(array[j] > array[pivot])
			{
				j--;
			}
			if(i < j)
			{
				hold = array[i];
				array[i] = array[j];
				array[j] = hold;
			}
		}

		hold = array[pivot];
		array[pivot] = array[j];
		array[j] = hold;

		sort(array, first, j-1);
		sort(array, j+1, last);
	}
}

