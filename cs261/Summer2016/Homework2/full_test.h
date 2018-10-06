#ifndef FULL_TEST_H
#define FULL_TEST_H

#include "vector.h"

/*This program will grade the non-written portion of this assignment.
 * There are no command line arguments used. The program performs a
 * stress test on each algorithm and then tests it against a relatively
 * large vector of values.*/
int main(int argc, char** argv);

/*The stress test checks for correctness a large number of times, but on
 * relatively small vectors. Note that you expected to handle vectors of size
 * zero and one.*/
int stress_test(void (*sort_fn)(vector*),const char* sort_name,const int size);

/*The big test checks for correctness on one large vector.*/
int big_test(void (*sort_fn)(vector*),const char* sort_name,const int size);

/*This is a silent run of a single test.*/
int single_test(void (*sort_fn)(vector*),const int size);

#endif /*ndef FULL_TEST_H*/
