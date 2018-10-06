#include "Vehicle.h"

//Default Constructor
Vehicle::Vehicle()
{
	newMiles = 0.0;
	newMpg = 0.0;
	newPrice = 0.0;
}

//Destroctor
Vehicle::~Vehicle()
{

}
//Accessors
string Vehicle::getName()
{
	return newName;
}

string Vehicle::getModel()
{
	return newModel;
}

string Vehicle::getColor()
{
	return newColor;
}

string Vehicle::getLot()
{
	return newLot;
}

double Vehicle::getMiles()
{
	return newMiles;
}

double Vehicle::getMpg()
{
	return newMpg;
}

double Vehicle::getPrice()
{
	return newPrice;
}

//Mutators
void Vehicle::setName(string name)
{
	newName = name;
}

void Vehicle::setModel(string model)
{
	newModel = model;
}

void Vehicle::setColor(string color)
{
	newColor = color;
}

void Vehicle::setLot(string lot)
{
	newLot = lot;
}

void Vehicle::setMiles(double miles)
{
	newMiles = miles;
}

void Vehicle::setMpg(double mpg)
{
	newMpg = mpg;
}

void Vehicle::setPrice(double price)
{
	newPrice = price;
}

