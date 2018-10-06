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

int Stack::remove()
{
	if(!head)
	{
		return NULL;
	}

	Creature *loser = head -> fighter;
	int indexNum = head -> index;
	string name = loser -> getName();
	cout << name << indexNum << endl;
	Stacknode *stkTemp;
	stkTemp = head -> next;
	delete head;
	head = stkTemp;
	return 0;
}


