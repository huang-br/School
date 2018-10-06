/********************************************************************
 * Author: Brian Huang
 * Description: Takes a number and performs operations on it based on
 		it if is even or odd.
********************************************************************/
#include <iostream>

using namespace std;

int hailStone(int);

/*int main()
{
	int num;
	cout << "Enter a hailstone number: " ;
	cin >> num;

	int steps = hailStone(num);

	cout << endl;

	cout << "It takes " << steps << " steps to get from " << num << " to 1."  << endl;


	return 0;
}*/

int hailStone(int num)
{
	if(num == 1)
	{
		cout << "The starting value is 1. " << endl;
		return 0;
	}
	
	int counter = 0;
	while(num != 1)
	{
		if(num%2 == 0)
		{
			num = num/2;
		}
		else if(num%2 != 0)
		{
			num = num * 3;
			num = num + 1;
		}
		cout << num << ", ";
		counter++;
	}

	return counter;
}


