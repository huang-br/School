#include "ShoppingCart.hpp"

ShoppingCart::ShoppingCart()
{
	cart = new Item*[100];
	for(int k=0; k < 100; k++)
	{
		cart[k] = 0;
	}

	int arrayEnd = 0;
}

ShoppingCart::~ShoppingCart()
{
	delete cart;
}

void ShoppingCart::addItem(Item *newItem)
{
	Item *hold;
	hold -> setName(newItem -> getName());
	hold -> setPrice(newItem -> getPrice());
	hold -> setQuantity(newItem -> getQuantity());
	if(cart[arrayEnd] != NULL)
	{
		cart[arrayEnd] = hold;
	}
	arrayEnd++;
}

double ShoppingCart::totalPrice()
{
	double price = 0.0;
	for(int k=0; k < arrayEnd; k++)
	{
		price += cart[k] -> getPrice();
	}

	return price;
}

