#ifndef AUTO_H
#define AUTO_H

#include <iostream>
#include <string>
#include <cmath>
#include "Vehicle.h"

class Auto:public Vehicle
{
	public:
		//Defalut Constructor
		Auto();
		//Destructor
		~Auto();
		//Accessors
		string getWindows();
		int getDoors();
		string getManual();
		//Mutators
		void setWindows(string);
		void setDoors(int);
		void setManual(string);
		//Functions
		void getAuto();
		void print();
		void basicPrint();
		void addMiles(int);
	private:
		string newWindows;
		int newDoors;
		string newManual;
};

#endif
