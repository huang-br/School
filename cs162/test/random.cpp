#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
srand(10);
 
for(int k = 0; k <= 9; ++k)
{
	int randomint;
	randomint =rand() %6 + 1;
	cout << randomint << endl;
}

cout << endl;

srand(10);
for(int k = 0; k <= 9; ++k)
{
	int randomint;
	randomint =rand() %6 + 1;
	cout << randomint << endl;
}

return 0;
}
