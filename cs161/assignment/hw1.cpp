/**************************************************
 * Program:hw1.cpp
 * Brian Huang
 * 10/4/2015
 * HW1 printing out numbers
 * Input: a number from 0-15
 * Output: The binary equivelent
 *************************************************/

#include<iostream>
#include<climits>

using namespace std;

int main( ) {
	int num, num1;
	cout << INT_MIN << endl;
	cout << INT_MAX << endl;
	cout << UINT_MAX << endl;

	num=INT_MAX;
	num=num+1;
	cout << num << endl; 

	// Variable
	cout << "enter a number thats from 0-15: ";
	cin >> num;
	
	cout << hex << num << endl; //Outputing the number as hexidecimal
	cout << oct << num << endl; //Outputting the number as octal
	
	cout <<num/8;
	num=num-(num/8)*8;
	cout <<num/4;
	num=num-(num/4)*4;
	cout <<num/2;
	num=num-(num/2)*2;
	cout <<num/1;	

	return 0;
}


