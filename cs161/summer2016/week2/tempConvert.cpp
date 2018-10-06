/*****************************************************************************
 * Author: Brian Huang
 * Date: 6/28/2016
 * Description: Converts Celsius to Fahrenheit
*****************************************************************************/

#include <iostream>

using namespace std;

int main() 
{
	double F,C;

	cout << "Please enter a Celsius temperature: ";
	cin >> C;

	F = (9.0/5.0)*C + 32;

	cout << " The equivalent Fahrenheit temperature is: " << F << endl;

	return 0;
}

