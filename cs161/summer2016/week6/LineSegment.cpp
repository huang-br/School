/*****************************************************************88
 * Author: Brian Huang
 * Date: 7/18/2016
 * Description: The Implementation file for the LineSegment Class.
********************************************************************/

#include "LineSegment.hpp"

LineSegment::LineSegment()
{
}

LineSegment::LineSegment(Point end1, Point end2)
{
	End1 = end1;
	End2 = end2;
}

LineSegment::~LineSegment()
{
}


Point LineSegment::getEnd1()
{
	return End1;
}

Point LineSegment::getEnd2()
{
	return End2;
}

void LineSegment::setEnd1(Point end1)
{
	End1 = end1;
}

void LineSegment::setEnd2(Point end2)
{
	End2 = end2;
}

double LineSegment::length()
{
	double length;
	length = End1.distanceTo(End2);
	return length;
}

double LineSegment::slope()
{
	double xVal, yVal, m;
	yVal = End2.getYCoord() - End1.getYCoord();
	xVal = End2.getXCoord() - End1.getXCoord();
	m = yVal/xVal;
	return m;
}

