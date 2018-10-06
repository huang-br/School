#include "Stack.h"

Stack::Stack()
{
	head = NULL;
}

Stack::~Stack()
{
	delete head;
}

void Stack::add(Creature *fighter, int num)
{
	head = new Stacknode(fighter, num, head);
}

Creature* Stack::remove()
{
	if(!head)
	{
		return NULL;
	}

	Creature *temp = head -> fighter;
	Stacknode *stkTemp;
	stkTemp = head -> next;
	delete head;
	head = stkTemp;
	return temp;
}


