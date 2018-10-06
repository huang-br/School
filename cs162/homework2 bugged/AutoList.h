#ifndef AUTOLIST_H
#define AUTOLIST_H

#include <iostream>
#include <string>
#include <cmath>
#include "Auto.h" 

using namespace std;

class AutoList
{
	public:
		//Dedault Constructor
		AutoList();
		//Functions
		void addAuto();
		void PrintList();
		void PrintBasic();
		void removeAuto();
		void adjustMiles();
		void Search();
		void buyCar();
	private:
		Auto *cars;
		int index;
};

#endif
