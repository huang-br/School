#include "basic_test.h"
#include "../p_queue.h"
#include "unit_test.h"

/*This is a series of unit tests meant to test correct functionality of
 * the priority queue iterator and heap array resizing.*/
int main(int argc, char** argv) {
	new_tests();
	announce_code(p_queue* min_heap = new_p_queue(true));
	announce_code(p_queue* max_heap = new_p_queue(false));
	summarize_code("Placing numbers 1-1023 in max_heap.");
	generic a;
	for (a=1.0f; a < 1024.0f; a += 1.0f) {
		pq_add(max_heap,a);
	}
	unit_test(pq_front(max_heap)==1023.0f,5);
	summarize_code("Iterating over max_heap and inserting elements into min_heap.");
	iterator* itr = get_pq_iterator(max_heap);
	while (has_next(itr)) {
		pq_add(min_heap,next(itr));
	}
	unit_test(pq_front(min_heap)==1.0f,5);
	announce_code(free_iterator(itr));
	summarize_code("Summing up elements in both heaps.");
	generic sum = 0.0f;
	while (!is_empty(min_heap)) {
		sum += pq_remove_front(min_heap);
	}
	while (!is_empty(max_heap)) {
		sum += pq_remove_front(max_heap);
	}
	unit_test(sum==1047552.0f,10);	
	announce_code(free_p_queue(min_heap));
	announce_code(free_p_queue(max_heap));
	report_tests();
	return 0;
}
