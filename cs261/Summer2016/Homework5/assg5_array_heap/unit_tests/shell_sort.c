#include "shell_sort.h"

void shell_sort(generic* to_sort, int size) {
	int gaps[32] = {1073741827,
					536870923,
					268435459,
					134217757,
					67108879,
					33554467,
					16777259,
					8388617,
					4194319,
					2097169,
					1048583,
					524309,
					262147,
					131101,
					65537,
					32771,
					16411,
					8209,
					4099,
					2053,
					1031,
					521,
					257,
					131,
					67,
					37,
					17,
					11,
					5,
					3,
					1,
					0};
	int gap_idx = 0;
	while (gaps[gap_idx] > (size)/2) {
		gap_idx++;
	}
	while (gap_idx < 32) {
		int gap = gaps[gap_idx];
		int i,j,k;
		for (i = 0; i < gap; i++) {
			for (j = i; j+gap < size; j+=gap) {
				k = j + gap;
				while (k-gap >= i && to_sort[k] < to_sort[k-gap]) {
					TYPE swap = to_sort[k];
					to_sort[k] = to_sort[k-gap];
					to_sort[k-gap] = swap;
					k-=gap;
				}
			}
		}
		gap_idx++;
	}
}
