#include "test_deque.h"
#include "deque.h"
#include "unit_test.h"

/*This is a series of unit tests meant to test correct functionality of a
 * deque.*/
int main(int argc, char** argv) {
	new_tests();
	announce_code(deque* dqp = new_deque());
	announce_code(add_front(dqp,99));
	announce_code(add_front(dqp,1));
	unit_test(remove_back(dqp)==99,1);
	unit_test(remove_back(dqp)==1,1);
	announce_code(add_back(dqp,3072));
	announce_code(add_back(dqp,-5));
	unit_test(remove_front(dqp)==3072,1);
	unit_test(front(dqp)==-5,1);
	unit_test(!is_empty(dqp),1);
	announce_code(free_deque(dqp));
	announce_code(dqp = new_deque());
	unit_test(is_empty(dqp),1);
	announce_code(add_back(dqp,11));
	unit_test(!is_empty(dqp),1);
	unit_test(back(dqp)==11,1);
	unit_test(front(dqp)==11,1);
	announce_code(add_back(dqp,7));
	unit_test(back(dqp)==7,1);
	unit_test(front(dqp)==11,1);
	announce_code(add_back(dqp,128));
	announce_code(add_back(dqp,42));
	announce_code(add_back(dqp,14));
	unit_test(remove_front(dqp)==11,1);
	unit_test(!is_empty(dqp),1);
	unit_test(remove_front(dqp)==7,1);
	unit_test(remove_front(dqp)==128,1);
	unit_test(remove_back(dqp)==14,1);
	unit_test(remove_back(dqp)==42,1);
	unit_test(is_empty(dqp),1);
	announce_code(add_front(dqp,1));
	announce_code(add_front(dqp,2));
	announce_code(add_front(dqp,3));
	announce_code(add_front(dqp,4));
	announce_code(add_front(dqp,5));
	unit_test(remove_back(dqp)==1,1);
	unit_test(remove_back(dqp)==2,1);
	unit_test(remove_back(dqp)==3,1);
	announce_code(free_deque(dqp));
	announce_code(dqp = new_deque());
	unit_test(is_empty(dqp),1);
	announce_code(add_front(dqp,38));
	announce_code(add_front(dqp,56));
	announce_code(add_back(dqp,17));
	unit_test(front(dqp)==56,1);
	unit_test(remove_front(dqp)==56,1);
	announce_code(add_front(dqp,88));
	announce_code(add_back(dqp,2000));
	unit_test(remove_front(dqp)==88,1);
	unit_test(remove_back(dqp)==2000,1);
	announce_code(add_back(dqp,2));
	unit_test(remove_back(dqp)==2,1);
	unit_test(remove_back(dqp)==17,1);
	unit_test(remove_back(dqp)==38,1);
	unit_test(is_empty(dqp),1);
	announce_code(free_deque(dqp));
	report_tests();
	return 0;
}
