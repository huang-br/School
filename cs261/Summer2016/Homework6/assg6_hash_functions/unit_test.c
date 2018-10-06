#include "unit_test.h"

#include <stdbool.h>
#include <stdio.h>

void _unit_test_(const char* code_str,bool test,int pts,int* total_p,int* poss_p) {
	*poss_p += pts;
	printf("Testing:\t%30s\t",code_str);
	if (test) {
		*total_p+=pts;
		printf("PASS\t(+%d)",pts);
	} else {
		printf("FAIL\t(+0)");
	}
	printf("\t%d/%d\n",*total_p,*poss_p);
}

void _unit_test_equals_(const char* code_str,int actual,int expected,int pts,int* total_p,int* poss_p) {
	*poss_p += pts;
	printf("Value:\t%30s\t==\t%d\n",code_str,actual);
	printf("Value:\t%30s\t==\t%d\n","expected",expected);
	printf("Testing:\t%s==expected\t",code_str);
	if (actual==expected) {
		*total_p+=pts;
		printf("PASS\t(+%d)",pts);
	} else {
		printf("FAIL\t(+0)");
	}
	printf("\t%d/%d\n",*total_p,*poss_p);
}
