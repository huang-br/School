#include "Stacknode.h"

Stacknode::Stacknode(Creature *data, Stacknode *head)
{
	fighter = data;
	next = head;
}		
