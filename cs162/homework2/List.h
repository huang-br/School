#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <cmath>
#include "Auto.h" 

using namespace std;

class List
{
	public:
		//Dedault Constructor
		List();
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
