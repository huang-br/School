#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

bool charCheck(string);

int main()
{
	int answer;
	string first, second;
	bool goodInt;

	try
	{
		cout << "First Number? ";
		cin >> first;
		goodInt = charCheck(first);

		if(goodInt == false)
		{
			throw "Not a number";
		}
		
		cout << "Second Number? ";
		cin >> second;
		goodInt = charCheck(second);

		if(goodInt == false)
		{
			throw "Not a number";
		}

		answer = pow(atoi(first.c_str()), atoi(second.c_str()));
	
	cout << first << " raised to the " << second << " power is " << answer << endl;

	}
	catch(char const *e)
	{
		cout << "Exception occured. " << e << endl;
	}
	

return 0;
}

bool charCheck(string checkStr)
{
	int length = checkStr.length();
	for(int k = 0; k < checkStr.length(); ++k)
	{
		if(checkStr.at(k) < 48 || checkStr.at(k) > 57)
		{
			return false;
		}
		
	}
	
	return true;
}	
