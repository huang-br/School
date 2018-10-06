/*************************************************************************
 * Author: Brian Huang
 * Date: 6/28/2016
 * Description: The user inputs a integer. The user then inputs that
 		amount of integers. The program then finds the min and
		the max of the numbers input.
*************************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int numInts = 0;
	int numbers;
	int min, max;

	cout << "How many integers would you like to enter? " ;
	cin >> numInts;
	
	if(numInts == 0 || numInts < 0)
	{
		cout << "You entered zero or a negative number. Please try again." << endl;
	}

	else
	{
		cout << "Please enter " << numInts << " integers." << endl;
	
		for(int k=0; k < numInts; k++)
		{
			cin >> numbers;
			if(k == 0)
			{
				max = numbers;
				min = numbers;
			}
			else if(numbers > max)
			{
				max = numbers;
			}
			else if(numbers < min)
			{
				min = numbers;
			}
		}
	
		cout << "Min: " << min << endl;
		cout << "Max: " << max << endl;
	}

	return 0;
}


