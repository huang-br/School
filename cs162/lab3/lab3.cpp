#include <iostream>
#include <string>
#include "Item.h"
#include "List.h"

using namespace std; 

int main(){	
	int amt;
	int price;
	int counter;
	bool cont = true;
	string name;
	string unit;
	Item myItems[]
	List mylist;
	
	while(cont == true)
	{
		++counter;
		Item = new myItmes[counter]
		cout << "What is the name of the item? ";
		cin >> name;
		cout << "What is the unit of this item? ";
		cin >> unit;
		cout << "What is the price? ";
		cin >> price;
		cout << "How many are you buying? ";
		cin >> amt;
		Item[counter] = Item(name, unit, price, amt);


return 0;
}
