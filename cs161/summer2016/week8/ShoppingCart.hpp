#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP
#include "Item.hpp"
#include <iostream>

class ShoppingCart
{
	public:
		//Defualt Constructor
		ShoppingCart();
		//Destructor
		~ShoppingCart();
		//Functions
		void addItem(Item*);
		double totalPrice();
	private:
		Item **cart;
		int arrayEnd;
};

#endif
