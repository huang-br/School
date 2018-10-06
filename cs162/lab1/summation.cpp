#include<iostream>
#include"summation.h"

double sum(int values[], int size)
{
	double sum;
	for(int k=0; k < size ; ++k){
		sum += values[k];
		
	}

return sum;
}
