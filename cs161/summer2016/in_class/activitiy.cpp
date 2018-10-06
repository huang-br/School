#include <iostream>
#include <cstdlib>

using namespace std;

int SumRow(int[4][4]);
void fillArray(int[4][4]);
void arrayPrint(int[4][4]);

int main()
{
	srand(time(NULL));
	int array[4][4];
	fillArray(array);
	arrayPrint(array);
	int row = SumRow(array);

	cout << "The row with the biggest sum is: " << row << endl; 

	return 0;
}

int SumRow(int array[4][4])
{
	int sum = 0;
	int biggestSum = 0;
	int rowNum = 0;
	for(int k=0; k < 4; k++)
	{
		for(int j=0; j < 4; j++)
		{
			sum += array[k][j];
		}
		cout << sum << endl;
		if(sum > biggestSum)
		{
			biggestSum = sum;
			rowNum = k;
		}
		sum = 0;

	}

	return rowNum;
}

void fillArray(int array[4][4])
{
	for(int k=0; k < 4; k++)
	{
		for(int j=0; j < 4; j++)
		{
			array[k][j] = rand() %100 + 1;
		}
	}
}

void arrayPrint(int array[4][4])
{
	for(int k=0; k < 4; k++)
	{
		cout << k << "| " ;
		for(int j=0; j < 4; j++)
		{
			cout << array[k][j] << " ";
		}
		cout << endl;
	}
}






