#include "Queue.h"

Queue::Queue()
{
	count = 0;
	head = NULL;
	tail = NULL;
} 

void Queue::add(Creature *data, int type, int num)
{ 
	Queuenode *temp = tail;
	tail = new Queuenode(data, temp, NULL, type, num);
	if(count == 0)
	{
		head = tail;
	} 
	else
	{
		temp -> next = tail;
	}
		
	count++
}

Creature* Queue::remove()
{	
	if(!head)
	{
		return NULL;
	}
	
	Creature *temp = head -> fighter;
	Queuenode *queTemp;
	queTemp = head -> next;
	delete head;
	head = queTemp;
	return temp;
}
