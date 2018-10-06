/*****************************************************************************
 * Author: Brian Huang
 * Date: 6/28/2016
 * Description: Takes 5 numbers from the user, displays them to the screen and
 * 		averages them.
******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
	double numArray[5];
	double sum = 0;
	double average = 0;

	cout << "Please enter five numbers." << endl;
	for(int k=0; k < 5; k++)
	{
		cin >> numArray[k];
		sum = sum + numArray[k];
	}

	average = sum/5;

	cout << "The average of those numbers is: " << average << endl;

	return 0;
}
		
