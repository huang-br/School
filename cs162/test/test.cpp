#include <iostream>

using namespace std;

int main(){
	int **array;
	
	array = new int *[2];	
	for(int k = 0; k < 2; ++k)
	{
		array[k] = new int [2];
		for(int j = 0; j < 2; ++j)
		{
			array[k][j] = (k + j);
			cout << array[k][j] << endl;
		}
	}


	int **secondarray;
	secondarray = array;	

	for(int l = 0; l < 2; ++l)
	{
		for(int p = 0; p < 2; ++p)
		{
			cout << secondarray[l][p] << endl;
		}
	}
return 0;
}
