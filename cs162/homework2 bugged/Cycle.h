#ifndef CYCLE_H
#define CYCLE_H

#include <iostream>
#include <string>
#include <cmath>
#include "Vehicle.h"

class Cycle:public Vehicle
{
	public:
		//Defalut Constructor
		Cycle();
		//Destructor
		~Cycle();
		//Accessors
		string getManual();
		//Mutators
		void setManual(string);
		//Functions
		void getCycle();
		void print();
		void basicPrint();
		void addMiles(int);
	private:
		string newManual;
};

#endif
