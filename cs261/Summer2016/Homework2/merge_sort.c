#include "merge_sort.h"
#include "vector.h"

void merge_sort(vector* to_sort_ptr) {
	if (to_sort_ptr->size > 1) {
		int mid = (to_sort_ptr->size+1)/2;
		int i,j,k;

		vector* left = copy_of_sub_vector(to_sort_ptr,0,mid);
		merge_sort(left);
		vector* right = copy_of_sub_vector(to_sort_ptr,mid,to_sort_ptr->size);
		merge_sort(right);

		i = j = k = 0;

		for (i = 0; i < to_sort_ptr->size; i++) {
			if (j >= left->size || (k < right->size && left->values[j] > right->values[k])) {
				to_sort_ptr->values[i] = right->values[k];
				k++;
			} else {
				to_sort_ptr->values[i] = left->values[j];
				j++;
			}
		}

		free_vector(left);
		free_vector(right);
	}
}
