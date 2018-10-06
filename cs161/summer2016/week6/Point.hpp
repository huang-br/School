/************************************************************
 * Author: Brian Huang
 * Date 7/18/2016
 * Description: The Header file for the Point class.
***********************************************************/

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

class Point
{
	public:
		//Defualt Constructor
		Point();
		//Overloaded Constructor
		Point(double, double);
		//Destructor
		~Point();
		//Accessors
		double getXCoord();
		double getYCoord();
		//Mutators
		void setXCoord(double);
		void setYCoord(double);
		//Functions
		double distanceTo(Point&);
	private:
		double X;
		double Y;
};

#endif
