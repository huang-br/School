#include <iostream>
#include <string>

using namespace std;

#ifndef ITEM_H
#define ITEM_h

class Item{
	public:
		//Default Constructer
		Item();
		//overload Constructer
		Item(string name, string unit, int amnt, double price);
		
		//Functions
		int totalprice(int amt, double price);
		string getname(string name);
		string getunit(string unit);
	private:
		string newName;
		string newUnit;
		int newAmt;
		double newPrice;
};
		
#endif
