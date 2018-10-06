#include "Auto.h"

//Defualt Constructor
Auto::Auto()
{
}

//Destructor
Auto::~Auto()
{

}
//Accessors
string Auto::getWindows()
{
	return newWindows;
}

int Auto::getDoors()
{
	return newDoors;
}

string Auto::getManual()
{
	return newManual;
}

//Mutators
void Auto::setWindows(string windows)
{
	newWindows = windows;
}	

void Auto::setDoors(int doors)
{
	newDoors = doors;
}	

void Auto::setManual(string manual)
{
	newManual = manual;
}	

//Functions
void Auto::getAuto()
{
	string name, model, color, windows, manual, lot;
	int doors;
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

	cout << "Automatic Windows? (yes or no) ";
	cin >> windows;
	setWindows(windows);

	cout << "What kind of transmission (automatic or manual)";
	cin >> manual;
	setManual(manual);

	cout << "How many doors? ";
	cin >> doors;
	setDoors(doors);
}

void Auto::print()
{
	cout << "Name: " << getName() << endl; 
	cout << "Model: " << getModel() << endl; 
	cout << "Color: " << getColor() << endl; 
	cout << "Lot Number: " << getLot() << endl; 
	cout << "Miles: " << getMiles() << endl; 
	cout << "MPG: " << getMpg() << endl; 
	cout << "Price: " << getPrice() << endl; 
	cout << "Automatic Windows: " << getWindows() << endl; 
	cout << "Number of Doors: " << getDoors() << endl; 
	cout << "Manual Transmission: " << getManual() << endl; 

}

void Auto::basicPrint()
{
	cout << "Name: "<< getName() << endl;
	cout << "Model: "<< getModel() << endl;
	cout << "Price: "<< getPrice() << endl;
}

void Auto::addMiles(int num)
{
	int miles;
	miles = getMiles() + num;
	setMiles(miles);
}

















