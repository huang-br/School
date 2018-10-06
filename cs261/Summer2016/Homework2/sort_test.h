#ifndef SORT_TEST_H
#define SORT_TEST_H

#include "vector.h"

/*Below is a simple macro that defaults to bubble_sort but is guarded by 
 * #ifndef so that the compiler might specify a different sorting
 * algorithm to compile with.*/
#ifndef SORT_FN
#define SORT_FN bubble_sort
#endif /*ndef SORT_FN*/

/*This macro allows for the easy stringification of other macros.*/
#define macstr(x) str(x)
#define str(x) #x

/*A prototype for the sorting algorithm defined by our macro.*/
void SORT_FN(vector* to_sort_ptr);

/*This program expects up to three arguments which get converted into the
 * size, min and max variables below. If unspecified the default is used.
 * 'size' random elements ranging from 'min' to 'max' are given to a
 * sorting algorithm. The algorithm is timed and checked for correctness.*/
int main(int argc, char** argv);

#endif /*ndef SORT_TEST_H*/
