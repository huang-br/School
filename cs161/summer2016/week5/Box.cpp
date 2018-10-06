/*************************************************************
 * Author: Brian Huang
 * Date: 7/13/2016
 * Description: The implementation file for the Box class.
*************************************************************/

#include "Box.hpp"

Box::Box()
{
}

Box::~Box()
{
}

Box::Box(double h, double w, double l)
{
	height = h;
	width = w;
	length = l;
}

double Box::getVolume()
{
	double volume = height * width * length;
	return volume;
}

double Box::getSurfaceArea()
{
	double SurfaceArea = 2*(height * width) + 2*(height * length) + 2*(width * length);
	return SurfaceArea;
}

void Box::setHeight(double h)
{
	height = h;
}

void Box::setWidth(double w)
{
	width = w;
}

void Box::setLength(double l)
{
	length = l;
}



