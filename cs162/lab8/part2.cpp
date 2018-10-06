#include <iostream>
#include <string>

using namespace std;

int main()
{
	string first, second;
	string combine;

	cout << "First string: " ;
	getline(cin,first);
	
	cout << "Second string: ";
	getline(cin,second);
	
	combine = first + ' ' + second;
	cout << combine << endl; 
}
