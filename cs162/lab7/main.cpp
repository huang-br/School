#include<iostream>

using namespace std;

int main()
{
	#ifdef DEBUG
		cout << "You are running the debug feature." << endl;
	#else
		cout << "You are running the normal program." << endl;
	#endif

return 0;

}

