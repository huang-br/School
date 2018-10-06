/*****************************************************************************
 * Author: Brian Huang
 * Date: 7/23/2016
 * Description: Creates an array based on a length given by the user. It then 
 * 		fills the array based on the method chosedn by the user. Then
 * 		Finds the modes of that array and prints them out in order.
******************************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> findMode(int array[], int size);

int main()
{
	srand(time(NULL));
	int length;
	int choice;

	cout << "Enter a length: ";
	cin >> length;

	int array[length];

	cout << "Select your choice" << endl;
	cout << "1. Randomly fill the array. " << endl;
	cout << "2. Manually fill the array. " << endl;

	cin >> choice;
	
	//Randomly fills the array.
	if(choice == 1)
	{
		for(int k=0; k < length; k++)
		{
			array[k] = rand() % 10;
		}
	}
	//Manually fills the array.
	else if(choice == 2)
	{
		cout << "Fill the array with numbers. " << endl;
		for(int k=0; k < length; k++)
		{
			cin >> array[k];
		}
	}
	else
	{
		cout << "Incorrect Choice, please try again." << endl;
		return 0;
	}

	vector<int> modeVector = findMode(array, length);

	//Prints the random array.
	if(choice == 1)
	{
		for(int j=0; j < length; j++)
		{
			cout << array[j] << endl;
		}
	}

	cout << "The mode of the array is: ";
	for(int j=0; j < modeVector.size(); j++)
	{
		cout << modeVector.at(j) << " " ;
	}
	cout << endl;

	return 0;
}

vector<int> findMode(int array[], int size)
{
	vector<int> myVector;
	int count;
	int maxCount = 0;

	for(int k=0; k < size; k++)
	{
		count = 0;
		for(int j=k; j < size; j++)
		{
			if(array[k] == array[j])
			{
				count++;
			}
		}
		if(count > maxCount)
		{
			if(myVector.size() == 0)
			{
				myVector.push_back(array[k]);
				maxCount = count;
			}
			else
			{
				myVector.pop_back();
				myVector.push_back(array[k]);
				maxCount = count;
			}
		}
		else if(count == maxCount)
		{
			myVector.push_back(array[k]);
		}
	}
	return myVector;
}





