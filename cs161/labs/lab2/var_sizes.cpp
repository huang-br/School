#include<iostream>
#include<string>

using namespace std;

int main ( ) {
	string input;
	cout << "What do you want to find the size of?" << endl;
	cin >> input;
	
	if (input=="char")
		cout << " The length of char is: " << sizeof(char) << endl;
	else if(input=="int")
		cout << "The length of int is: " << sizeof(int) << endl;
	else if(input=="long")
		cout << "The length of long is: " << sizeof(long) << endl;
	else if(input=="short")
		cout << "The length of short is: " << sizeof(short) << endl;
	else if(input=="bool")
		cout << "The length of bool is: " << sizeof(bool) << endl;
	else if(input=="float")
		cout << "The length of float is: " << sizeof(float) << endl;
	else if(input=="double")
		cout << "The length of double is: " << sizeof(double) << endl;
	else if(input!="char" || "int" || "long" || "short" || "bool" || "float" || "double") 
		cout << "Not a right input." << endl;
return 0; 
}

