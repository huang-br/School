#include <iostream>

using namespace std; 

int main()
{
	int array[10];
	for(int k=0; k <= 20; k++)
	{
		array[k] = k;
	}

	for(int j=0; j <= 20; j++)
	{
		cout << array[j] << endl;
	}

	return 0;
}


