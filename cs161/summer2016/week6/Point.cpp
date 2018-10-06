/************************************************************
 * Author: Brian Huang
 * Date: 7/18/2016
 * Description: The implementation file for the Point class
************************************************************/

#include "Point.hpp"

Point::Point()
{
}

Point::Point(double x, double y)
{
	X = x;
	Y = y;
}

Point::~Point()
{
}

double Point::getXCoord()
{
	return X;
}

double Point::getYCoord()
{
	return Y;
}

void Point::setXCoord(double x)
{
	X = x;
}

void Point::setYCoord(double y)
{
	Y = y;
}

double Point::distanceTo(Point &next)
{
	double xVal, yVal, total;

	xVal = next.getXCoord() - X;
	yVal = next.getYCoord() - Y;

	xVal = pow(xVal,2);
	yVal = pow(yVal,2);

	total = xVal + yVal;

	return sqrt(total);
}









