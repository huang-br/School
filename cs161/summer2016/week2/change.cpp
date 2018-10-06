/**************************************************************************
 * Author: Brian Huang
 * Date: 6/28/2016
 * Description: Finds the change using the smallest amount of coins
 * 		for a given amount.
***************************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int amount, calc;
	int coinVals[4] = {25, 10, 5, 1};
	int coins[4];
	cout << "Please enter an amount in cents less than a dollar: ";
	cin >> amount;
	calc = amount;

	for(int k=0; k < 4; k++)
	{
		amount = amount%coinVals[k];
		calc = calc - amount;
		coins[k] = calc/coinVals[k];
		calc = amount;
	}

	cout << endl;
	cout << "Your change will be: " << endl;
	cout << "Q: " << coins[0] << endl;
	cout << "D: " << coins[1] << endl;
	cout << "N: " << coins[2] << endl;
	cout << "P: " << coins[3] << endl;

	return 0;
}


