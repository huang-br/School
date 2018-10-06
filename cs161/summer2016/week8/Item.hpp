#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>

using namespace std;

class Item
{
	public:
		//defualt constructor
		Item();
		//Overloaded constructor
		Item(string, double, int);
		//Destructor
		~Item();
		//Acsessors
		string getName();
		double getPrice();
		int getQuantity();
		//Mutators
		void setName(string);
		void setPrice(double);
		void setQuantity(int);
	private:
		string name;
		double price;
		int quantity;

};

#endif
