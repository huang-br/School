#include "basic_test.h"
#include "../p_queue.h"
#include "unit_test.h"

/*This is a series of unit tests meant to test basic functionality of
 * the priority queue.*/
int main(int argc, char** argv) {
	new_tests();
	announce_code(p_queue* pq = new_p_queue(true));
	unit_test(pq != NULL, 1);
	unit_test(is_empty(pq), 1);
	announce_code(pq_add(pq,17.0f));
	unit_test(!is_empty(pq), 1);
	unit_test(pq_front(pq) == 17.0f, 1);
	unit_test(!is_empty(pq), 1);
	unit_test(pq_front(pq) == 17.0f, 1);
	unit_test(pq_remove_front(pq) == 17.0f, 1);
	unit_test(is_empty(pq), 1);
	announce_code(pq_add(pq,45.0f));
	announce_code(pq_add(pq,25.0f));
	announce_code(pq_add(pq,15.0f));
	announce_code(pq_add(pq,75.0f));
	announce_code(pq_add(pq,55.0f));
	announce_code(pq_add(pq,35.0f));
	unit_test(pq_remove_front(pq) == 15.0f, 1);
	unit_test(pq_remove_front(pq) == 25.0f, 1);
	unit_test(pq_remove_front(pq) == 35.0f, 1);
	unit_test(!is_empty(pq), 1);
	announce_code(pq_add(pq,5.0f));
	announce_code(pq_add(pq,65.0f));
	unit_test(pq_remove_front(pq) == 5.0f, 1);
	unit_test(pq_remove_front(pq) == 45.0f, 1);
	unit_test(pq_remove_front(pq) == 55.0f, 1);
	unit_test(pq_remove_front(pq) == 65.0f, 1);
	unit_test(pq_remove_front(pq) == 75.0f, 1);
	unit_test(is_empty(pq), 1);
	announce_code(free_p_queue(pq));
	announce_code(pq = new_p_queue(false));
	announce_code(pq_add(pq,45.0f));
	announce_code(pq_add(pq,15.0f));
	announce_code(pq_add(pq,65.0f));
	announce_code(pq_add(pq,35.0f));
	announce_code(pq_add(pq,75.0f));
	announce_code(pq_add(pq,55.0f));
	announce_code(pq_add(pq,25.0f));
	unit_test(pq_remove_front(pq) == 75.0f, 1);
	unit_test(pq_remove_front(pq) == 65.0f, 1);
	unit_test(pq_remove_front(pq) == 55.0f, 1);
	unit_test(pq_remove_front(pq) == 45.0f, 1);
	unit_test(pq_remove_front(pq) == 35.0f, 1);
	unit_test(pq_remove_front(pq) == 25.0f, 1);
	unit_test(pq_remove_front(pq) == 15.0f, 1);
	announce_code(free_p_queue(pq));
	report_tests();
	return 0;
}
