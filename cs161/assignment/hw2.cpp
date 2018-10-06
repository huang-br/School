/******************************************************************
 * Program:hw2.cpp
 * Brian Huang
 * 10/11/2015
 * HW2 printing out numbers better
 * Input: a number from 0-15
 * Output: Bad input, or the correct input in binary, hex or octal
 *****************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main( ) { 
	int num;
	string input;
	string choice;
	bool cont=true;
	while(cont==true){
		cout << "enter a number from 0-15: " ;
		cin >> input;

		// Handling inputs that are larger than two digits.
		if (input.size() > 2) 
			cout << "Bad Input)" << endl;

		// Handling bad one character inputs.
		else if(input.at(0) < 48 || input.at(0) > 57)
			cout << "Bad Input" << endl;

		// Handling bad two character inputs.

		else if (input.size() == 2)
			if (input.at(0) != '1' || input.at(1) < 48 || input.at(1) > 53) 
				cout << "Bad Input" << endl;

		else
			cout << input << endl;
		// Coverting
		cout << "Convert to binary, octal or hexadecimal? " ;	
		cin >> choice;
		num=atoi(input.c_str());
		cout << num << endl;

		if (choice == "binary"){
			cout << num/8;
			num=num - (num/8)*8;
			cout << num/4;
			num=num - (num/4)*4;
			cout << num/2;
			num=num - (num/2)*2;
			cout <<num/1; 
		}
		else if (choice == "octal")
			cout << oct << num << endl;
		else if (choice == "hexadecimal")
			cout << hex << num << endl;

		cout << " Do this again? (1 for yes. 0 for no.) " ;
		cin >> cont;
	}	

	return 0;
}


