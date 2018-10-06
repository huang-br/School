#include "hash_fn_test.h"

/*This is a series of unit tests meant to test your hash functions.*/
int main(int argc, char** argv) {
	new_tests();

	unit_test_equals(hash_by_length("leap"),4,1);
	unit_test_equals(hash_by_length("peal"),4,1);
	unit_test_equals(hash_by_length("pale"),4,1);
	unit_test_equals(hash_by_length("LEAP"),4,1);
	unit_test_equals(hash_by_length("FROG"),4,1);
	unit_test_equals(hash_by_length("computer"),8,1);
	unit_test_equals(hash_by_length("language"),8,1);
	unit_test_equals(hash_by_length(""),0,1);
	unit_test_equals(hash_by_length("small"),5,1);
	unit_test_equals(hash_by_length("all"),3,1);

	unit_test_equals(hash_by_sum("leap"),418,1);
	unit_test_equals(hash_by_sum("peal"),418,1);
	unit_test_equals(hash_by_sum("pale"),418,1);
	unit_test_equals(hash_by_sum("LEAP"),290,1);
	unit_test_equals(hash_by_sum("FROG"),302,1);
	unit_test_equals(hash_by_sum("computer"),879,1);
	unit_test_equals(hash_by_sum("language"),836,1);
	unit_test_equals(hash_by_sum(""),0,1);
	unit_test_equals(hash_by_sum("small"),537,1);
	unit_test_equals(hash_by_sum("all"),313,1);

	unit_test_equals(hash_by_shifted_sum("leap"),1594,1);
	unit_test_equals(hash_by_shifted_sum("peal"),1566,1);
	unit_test_equals(hash_by_shifted_sum("pale"),1546,1);
	unit_test_equals(hash_by_shifted_sum("LEAP"),1114,1);
	unit_test_equals(hash_by_shifted_sum("FROG"),1118,1);
	unit_test_equals(hash_by_shifted_sum("computer"),28293,1);
	unit_test_equals(hash_by_shifted_sum("language"),26062,1);
	unit_test_equals(hash_by_shifted_sum(""),0,1);
	unit_test_equals(hash_by_shifted_sum("small"),3313,1);
	unit_test_equals(hash_by_shifted_sum("all"),745,1);

	report_tests();
	return 0;
}
