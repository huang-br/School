#include <iostream>

using namespace std;

int main()
{

	int *num;
	int *store;

	num = new int [1];
	num[1] = 10;
	cout << num[1] << endl;

	store = new int[1];
	store[1] = num[1];
	num = new int[2];
	num[1] = store[1];
	num[2] = 20;
	delete store;
	cout << num[1] << ' ' << num[2] << endl;
	
	
return 0;
}
