#include "Stacknode.h"

Stacknode::Stacknode(Creature *data, int num, Stacknode *head)
{
	fighter = data;
	index = num;	
	next = head;
}		
