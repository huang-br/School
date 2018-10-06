#include <iostream>
#include <cmath>
#include "AutoList.h"
#include "CycleList.h"
#include "Auto.h"
#include "Cycle.h"

using namespace std;

int main(){
	int choice;
	string type;
	bool cont = true;	
	AutoList Auto;
	CycleList Cycle;

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
			Cycle.PrintList();
		}
	
		else if(choice == 2)
		{
			cout << "car or bike?" ;
			cin >> type;
			if(type == "car")
			{
				Auto.PrintBasic();
				Auto.adjustMiles();
			}
			else if(type == "bike")
			{
				Cycle.PrintBasic();
				Cycle.adjustMiles();
			}	
				
		}		

		else if(choice == 3)
		{
			cout << "car or bike?" ;
			cin >> type;
			if(type == "car")
			{
				Auto.Search();
			}
			else if(type == "bike")
			{
				Cycle.Search();
			}
		}
		
	
		else if(choice == 4)
		{
			cout << "car or bike" ;
			cin >> type;
			if(type == "car")
			{
				Auto.addAuto();
			}	
			else if(type == "bike")
			{
				Cycle.addCycle();
			}	
		}
	
		else if(choice == 5)
		{
			cout << "car or bike" ;
			cin >> type;
			if(type == "car")
			{
				Auto.PrintBasic();
				Auto.removeAuto();	
			}	
			else if(type == "bike")
			{
				Cycle.PrintBasic();
				Cycle.removeCycle();	
			}	
				
				
		}
		
		else if(choice == 6)
		{
			cout << "car or bike" ;
			cin >> type;
			if(type == "car")
			{
				Auto.PrintBasic();
				Auto.buyCar();
			}	
			else if(type == "bike")
			{
				Cycle.PrintBasic();
				Cycle.buyCycle();
			}	
					
			
		}

		else if(choice == 7)
		{
			cont = false;
		}
		cout << endl;
	}	
return 0;
}
