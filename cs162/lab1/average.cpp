#include<iostream>
#include"average.h"

double avg(int values[], int size)
{
	int sum;
	double average;

	for(int k=0; k < size; ++k){
		sum += values[k];
	}
	average = sum/size;

return average;
}
