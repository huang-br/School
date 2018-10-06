#include "List.h"
#include "Item.h"

void List::additem(Item *x, Item y)
{
	int size;
	size = sizeof(x)+1;
	x = new Item[size];
	x[size]= y;
}
	
	
