#include "Item.hpp"

Item::Item()
{
	name = "";
	price = 0.0;
	quantity = 0;
}

Item::Item(string n, double p, int q)
{
	setName(n);
	setPrice(p);
	setQuantity(q);
}

Item::~Item()
{
}

string Item::getName()
{
	return name;
}

double Item::getPrice()
{
	return price;
}

int Item::getQuantity()
{
	return quantity;
}

void Item::setName(string n)
{
	name = n;
}

void Item::setPrice(double p)
{
	price = p;
}

void Item::setQuantity(int q)
{
	quantity = q;
}

