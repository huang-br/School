#include <iostream>

using namespace std;

void smallSort(int&, int&, int&);

/*int main()
{	
	int a = 100;
	int b = 0;
	int c = -100;

	smallSort(a,b,c);

	cout << a << " " << b << " " << c << endl;
	return 0;
}*/

void smallSort(int &a, int &b, int&c)
{
	int array[3] = {a,b,c};
	int hold;

	//implementing bubble sort
	for(int k=0; k < 2; k++)
	{
		for(int j=0; j < 3-k-1; j++)
		{
			if(array[j] > array[j+1])
			{
				hold = array[j];
				array[j] = array[j+1];
				array[j+1] = hold;
			}
		}
	}
	a = array[0];
	b = array[1];
	c = array[2];
}




