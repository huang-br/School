#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <stdbool.h>
#include <stdio.h>

#define new_tests() int _total_=0; int _possible_=0

#define announce_code(code) \
	printf("Running:\t%s;\n",#code);\
	code;\

#define unit_test(code,pts) _unit_test_(#code,code,pts,&_total_,&_possible_)

#define report_tests() printf("\n\tFinal Score:\t%d/%d\n",_total_,_possible_)

void _unit_test_(const char*,bool,int,int*,int*);

#endif/*ndef UNIT_TEST_H*/