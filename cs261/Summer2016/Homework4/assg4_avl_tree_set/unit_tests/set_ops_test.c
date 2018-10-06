#include "set_ops_test.h"
#include "../tree.h"
#include "../iterator.h"
#include "../set.h"
#include "unit_test.h"

/*This is a series of unit tests meant to test correct functionality of
 * set operations.*/
int main(int argc, char** argv) {
	new_tests();
	announce_code(set* A = new_set());
	announce_code(set_add(A,-11.11f));
	unit_test(!set_add(A,-11.11f),1);
	unit_test(set_add(A,50.0f),1);
	announce_code(set_add(A,-2.0f));
	announce_code(set_add(A,50.0f));
	unit_test(set_size(A) == 3,1);
	unit_test(!set_remove(A,13.0f),1);
	unit_test(set_remove(A,-11.11f),1);
	unit_test(!set_remove(A,-11.11f),1);
	unit_test(set_size(A) == 2,1);
	unit_test(set_contains(A,50.0f),1);
	unit_test(set_contains(A,-2.0f),1);
	unit_test(!set_contains(A,-11.11f),1);
	announce_code(free_set(A));
	announce_code(A = new_set());
	summarize_code("Adding elements [31,50] to set A.");
		generic a;
		for (a = 31.0f; a <= 50.0f; a += 1.0f) {
			set_add(A,a);
		}
	announce_code(set* B = new_set());
	summarize_code("Adding elements [41,60] to set B.");
		for (a = 41.0f; a <= 60.0f; a += 1.0f) {
			set_add(B,a);
		}
	announce_code(set* C = new_set());
	summarize_code("Adding elements [51,60] to set C.");
		for (a = 51.0f; a <= 60.0f; a += 1.0f) {
			set_add(C,a);
		}
	announce_code(set* AuB = set_union(A,B));
	summarize_code("Checking that AuB == [31,60]");
		bool AuB_is_31to60 = true;
		for (a = 31.0f; a <= 60.0f; a += 1.0f) {
			AuB_is_31to60 = set_contains(AuB,a);
			if (!AuB_is_31to60) {
				break;
			}
		}
	unit_test(AuB_is_31to60,1);
	unit_test(set_is_subset(A,AuB),1);
	unit_test(!set_is_subset(AuB,B),1);
	announce_code(set* AnB = set_intersection(B,A));
	summarize_code("Checking that AnB == [41,50]");
		bool AnB_is_41to50 = true;
		for (a = 41.0f; a <= 50.0f; a += 1.0f) {
			AnB_is_41to50 = set_contains(AnB,a);
			if (!AnB_is_41to50) {
				break;
			}
		}
	unit_test(AnB_is_41to50,1);
	announce_code(set* AlessB = set_difference(A,B));
	summarize_code("Checking that AlessB == [31,40]");
		bool AlessB_is_31to40 = true;
		for (a = 31.0f; a <= 40.0f; a += 1.0f) {
			AlessB_is_31to40 = set_contains(AlessB,a);
			if (!AlessB_is_31to40) {
				break;
			}
		}
	unit_test(AlessB_is_31to40,1);
	announce_code(set* BlessA = set_difference(B,A));
	summarize_code("Checking that BlessA == [51,60]");
		bool BlessA_is_51to60 = true;
		for (a = 51.0f; a <= 60.0f; a += 1.0f) {
			BlessA_is_51to60 = set_contains(BlessA,a);
			if (!BlessA_is_51to60) {
				break;
			}
		}
	unit_test(BlessA_is_51to60,1);
	announce_code(set* CnA = set_intersection(C,A));
	unit_test(set_size(CnA)==0,1);
	announce_code(set* ClessB = set_difference(C,B));
	unit_test(set_size(ClessB)==0,1);
	unit_test(set_is_subset(C,BlessA),1);
	unit_test(set_is_subset(BlessA,C),1);
	announce_code(free_set(AuB));
	announce_code(free_set(AnB));
	announce_code(free_set(AlessB));
	announce_code(free_set(BlessA));
	announce_code(free_set(CnA));
	announce_code(free_set(ClessB));
	announce_code(free_set(A));
	announce_code(free_set(B));
	announce_code(free_set(C));
	report_tests();
	return 0;
}
