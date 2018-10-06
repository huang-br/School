#include <iostream>
#include <cmath>

using namespace std;

int main (){
   int weight;
   int radius;
   int volume;
   int b_force;
   double pi;
   pi == 3.14159265;

   cout << "Enter a weight: " ;
   cin >> weight;

   cout << "Enter a radius: ";
   cin >> radius;

   volume = 4/3 * pi * pow(radius, 3);

   b_force = volume * weight;

   if(b_force >= weight)
	cout << "The shpere will float!" << endl;

   else;
  	cout << "The shpere will sink!" << endl;
  
return 0;
}


