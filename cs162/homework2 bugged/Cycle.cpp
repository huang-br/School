#include "Cycle.h"

//Defualt Constructor
Cycle::Cycle()
{
}

//Destructor
Cycle::~Cycle()
{

}
//Accessors
string Cycle::getManual()
{
	return newManual;
}

//Mutators
void Cycle::setManual(string manual)
{
	newManual = manual;
}	

//Functions
void Cycle::getCycle()
{
	string name, model, color, manual, lot;
	double miles, mpg, price;
	
	cout << "Name: ";
	cin >> name;
	setName(name);
	
	cout << "Model: ";
	cin >> model;
	setModel(model);
	
	cout << "Color: ";
	cin >> color;
	setColor(color);

	cout << "Lot number: ";
	cin >> lot;
	setLot(lot);
	
	cout << "Miles: ";
	cin >> miles;
	setMiles(miles);
	
	cout << "mpg: ";
	cin >> mpg;
	setMpg(mpg);
	
	cout << "Price: ";
	cin >> price;
	setPrice(price);

	cout << "What kind of transmission (automatic or manual)";
	cin >> manual;
	setManual(manual);
}

void Cycle::print()
{
	cout << "Name: " << getName() << endl; 
	cout << "Model: " << getModel() << endl; 
	cout << "Color: " << getColor() << endl; 
	cout << "Lot Number: " << getLot() << endl; 
	cout << "Miles: " << getMiles() << endl; 
	cout << "MPG: " << getMpg() << endl; 
	cout << "Price: " << getPrice() << endl; 
	cout << "Manual Transmission: " << getManual() << endl; 

}

void Cycle::basicPrint()
{
	cout << "Name: "<< getName() << endl;
	cout << "Model: "<< getModel() << endl;
	cout << "Price: "<< getPrice() << endl;
}

void Cycle::addMiles(int num)
{
	int miles;
	miles = getMiles() + num;
	setMiles(miles);
}

















