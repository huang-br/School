#include "test_stack.h"
#include "stack.h"
#include "unit_test.h"

/*This is a series of unit tests meant to test correct functionality of a
 * stack.*/
int main(int argc, char** argv) {
	new_tests();
	announce_code(stack* stack_p = new_stack());
	unit_test(stack_p != NULL,1);
	unit_test(is_empty(stack_p),1);
	announce_code(push(stack_p,'a'));
	unit_test(!is_empty(stack_p),1);
	unit_test(top(stack_p)=='a',1);
	unit_test(pop(stack_p)=='a',1);
	unit_test(is_empty(stack_p),1);
	announce_code(push(stack_p,' '));
	announce_code(push(stack_p,'E'));
	announce_code(push(stack_p,'S'));
	announce_code(push(stack_p,'R'));
	announce_code(push(stack_p,'E'));
	announce_code(push(stack_p,'V'));
	announce_code(push(stack_p,'E'));
	announce_code(push(stack_p,'R'));
	unit_test(!is_empty(stack_p),1);
	announce_code(pop(stack_p));
	unit_test(pop(stack_p)=='E',1);
	announce_code(pop(stack_p));
	announce_code(pop(stack_p));
	unit_test(top(stack_p)=='R',1);
	announce_code(pop(stack_p));
	announce_code(pop(stack_p));
	unit_test(pop(stack_p)=='E',1);
	unit_test(top(stack_p)==' ',1);
	unit_test(!is_empty(stack_p),1);
	announce_code(push(stack_p,'r'));
	announce_code(push(stack_p,'e'));
	announce_code(push(stack_p,'d'));
	announce_code(push(stack_p,'r'));
	announce_code(push(stack_p,'o'));
	unit_test(pop(stack_p)=='o',1);
	unit_test(pop(stack_p)=='r',1);
	unit_test(pop(stack_p)=='d',1);
	unit_test(pop(stack_p)=='e',1);
	unit_test(pop(stack_p)=='r',1);
	unit_test(!is_empty(stack_p),1);
	unit_test(pop(stack_p)==' ',1);
	unit_test(is_empty(stack_p),1);
	announce_code(free_stack(stack_p));
	announce_code(stack_p = new_stack());
	unit_test(is_empty(stack_p),1);
	announce_code(push(stack_p,'5'));
	unit_test(!is_empty(stack_p),1);
	announce_code(push(stack_p,'2'));
	announce_code(push(stack_p,'1'));
	unit_test(top(stack_p)=='1',1);
	unit_test(!is_empty(stack_p),1);
	announce_code(pop(stack_p));
	unit_test(top(stack_p)=='2',1);
	announce_code(pop(stack_p));
	announce_code(push(stack_p,'3'));
	unit_test(top(stack_p)=='3',1);
	announce_code(pop(stack_p));
	announce_code(push(stack_p,'4'));
	unit_test(pop(stack_p)=='4',1);
	unit_test(!is_empty(stack_p),1);
	unit_test(top(stack_p)=='5',1);
	announce_code(pop(stack_p));
	unit_test(is_empty(stack_p),1);
	announce_code(free_stack(stack_p));
	report_tests();
	return 0;
}