#include "Item.h"

Item::Item(string name, string unit, int amt, double price)
{
	newName=name;
	newUnit=unit;
	newAmt=amt;
	newPrice=price;
}

int Item::totalprice(int amt, double price)
{
	int total;
	total = amt * price;
	return total;
}

string Item::getname(string name)
{
	return name;
}

string Item::getunit(string unit)	
{
	return unit;
}
