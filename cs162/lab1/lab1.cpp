#include<iostream>
#include"average.h"
#include"summation.h"

using namespace std;

int main(){
	int arraysize,num,*array;
	cout <<"How many numbers in the array? ";
	cin >> arraysize;

	array = new int[arraysize];
	for(int k=0; k<arraysize; ++k){
		cout << "What are these numbers? " ;
		cin >> num;
		array[k]=num;
	}
	
	
return 0;
}
	
