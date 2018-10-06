#ifndef SORT_TEST_H
#define SORT_TEST_H

#include "../p_queue.h"
#include "unit_test.h"
#include "shell_sort.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/*This is a series of unit tests meant to test correct functionality of
 * the inplace heapsort function.*/
int main(int argc, char** argv);
void array_random_fill(generic* to_fill, int size, generic min, generic max);
generic* copy_of_array(generic* to_copy, int size);

#endif /*ndef SORT_TEST_H*/
