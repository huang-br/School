#include <iostream>
#include <cmath>
#include "List.h"
#include "Auto.h"

using namespace std;

int main(){
	int choice;
	bool cont = true;	
	List Auto;

	while(cont == true)
	{
		cout << "Select a number " << endl;
		cout << "1.Display Vehicles " << endl;
		cout << "2.Adjust Mileage" << endl;
		cout << "3.Search for Vehicle " << endl;
		cout << "4.Add Vehicle " << endl;
		cout << "5.Remove Vehicle " << endl;
		cout << "6.Buy and calculate price " << endl;
		cout << "7.Exit " << endl;
		cout << "Enter your choice: " ;
		cin >> choice;
		cout << endl;

		if(choice == 1)
		{
			Auto.PrintList();
		}
	
		else if(choice == 2)
		{
			Auto.PrintBasic();
			Auto.adjustMiles();
		}		

		else if(choice == 3)
		{
			Auto.Search();
		}
	
		else if(choice == 4)
		{
			Auto.addAuto();
		}
	
		else if(choice == 5)
		{
			Auto.PrintBasic();
			Auto.removeAuto();		
		}
		
		else if(choice == 6)
		{
			Auto.PrintBasic();
			Auto.buyCar();
		}

		else if(choice == 7)
		{
			cont = false;
		}
		cout << endl;
	}	
return 0;
}
