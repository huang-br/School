#include "shell_sort.h"
#include "vector.h"

void shell_sort(vector* to_sort_ptr) {
	/*TODO: You are to implement the Shell Sort algorithm here. (See course
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
	 * You might want to write other functions to complete this task. Any
	 * additional functions you write MUST have prototypes in "shell_sort.h"
	 * */

	int i,j,k;
	TYPE hold;

	for(i = (to_sort_ptr -> size)/2; i > 0; i = i/2)
	{
		for(j = i; j < to_sort_ptr -> size; j++)
		{
			for(k = j-i; k >= 0; k = k -i)
			{
				if(to_sort_ptr -> values[k+i] >= to_sort_ptr -> values[k])
				{
					break;
				}
				else
				{
					hold = to_sort_ptr -> values[k];
					to_sort_ptr -> values[k] = to_sort_ptr -> values[k+i];
					to_sort_ptr -> values[k+i] = hold;
				}
			}
		}
	}
	
}
