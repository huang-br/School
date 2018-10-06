#ifndef CYCLELIST_H
#define CYCLELIST_H

#include <iostream>
#include <string>
#include <cmath>
#include "Cycle.h" 

using namespace std;

class CycleList
{
	public:
		//Dedault Constructor
		CycleList();
		//Functions
		void addCycle();
		void PrintList();
		void PrintBasic();
		void removeCycle();
		void adjustMiles();
		void Search();
		void buyCycle();
	private:
		Motorcycle *bikes;
		int index;
};

#endif
