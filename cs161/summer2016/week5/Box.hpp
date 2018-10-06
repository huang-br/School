/*****************************************************************
 * Author:Brian Huang
 * Date:7/13/2016
 * Description: The header file for the box class.
*****************************************************************/


#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>
#include <cmath>

using namespace std;

class Box
{
	public:
		//Defualt Constructor
		Box();
		//destructor
		~Box();
		//Overloaded Constructor
		Box(double, double, double);
		//functions
		double getVolume();
		double getSurfaceArea();
		//Mutators
		void setHeight(double);
		void setWidth(double);
		void setLength(double);
	private:
		double height;
		double width;
		double length;
};

#endif
