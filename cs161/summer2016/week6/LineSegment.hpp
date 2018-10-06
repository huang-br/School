/******************************************************************88
 * Author: Brian Huang
 * Date: 7/18/2016
 * Description: The header file for the LineSegment class.
***********************************************************************/

#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

#include <iostream>
#include "Point.hpp"

class LineSegment
{
	public:
		//Defualt Constructor
		LineSegment();
		//Overloaded Constructor
		LineSegment(Point, Point);
		//Destructor
		~LineSegment();
		//Accessors
		Point getEnd1();
		Point getEnd2();
		//Mutators
		void setEnd1(Point);
		void setEnd2(Point);
		//Functions
		double length();
		double slope();
	private:
		Point End1;
		Point End2;
};

#endif
