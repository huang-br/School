#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
	public:
		//Default Constructor
		Vehicle();
		//Overload Constructor
		Vehicle(string, string, string, string, double, double ,double);
		//Desturctor
		~Vehicle();
		//Accessors
		string getName();
		string getModel();
		string getColor();
		string getLot();
		double getMiles();
		double getMpg();
		double getPrice();
		//Mutators
		void setName(string);
		void setModel(string);
		void setColor(string); 
		void setLot(string);
		void setMiles(double);
		void setMpg(double);
		void setPrice(double);
	private:
		string newName;
		string newModel;
		string newColor;
		string newLot;
		double newMiles;
		double newMpg;
		double newPrice;
};

#endif
