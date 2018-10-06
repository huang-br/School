#include <iostream>
#include <cmath>

using namespace std;

float fallDistance(int);

/*int main()
{
	int seconds = 0;
	cout << "Enter a time for an object to fall: " ;
	cin >> seconds;

	float distance = fallDistance(seconds);

	cout << "The distance fallen is " << distance << "meters." << endl;

	return 0;
}*/

float fallDistance(int time)
{
	float distance = 0;
	float gravity = 9.8;

	distance = (1.0/2.0) * gravity * pow(time,2);
	
	return distance;
}	

