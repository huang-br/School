/***********************************************************************
 * Author: Brian Huang
 * Date: 7/3/2016
 * Description: The user inputs a number, then guesses that number.
***********************************************************************/

#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int num = 0;
	int guess = 0;
	int guessNum = 0;

	cout << "Enter the number for the player to guess: " ;
	cin >> num;

	system("clear");

	while(num != guess)
	{
		cout << "Enter your guess: ";
		cin >> guess;

		if(guess > num) 
		{
			cout << "Your guess is too high. Try again. " << endl;
		}
		else if(guess < num)
		{
			cout << "Your guess is too low. Try again. " << endl;
		}

		guessNum++;
	}

	cout << "You have guess correctly in " << guessNum << " tries! " << endl;

	return 0;
} 

