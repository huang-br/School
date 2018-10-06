#ifndef QUEUE_H
#define QUEUE_H

#include <iostream> 
#include "Creature.h"
#include "Queuenode.h" 

class Queue
{
	public:
		//Defualt Constructor
		Queue();
		//Functions
		void add(Creature*, int, int);
		void cycle(Queue*&);
		Creature* remove();
		//Data
		Queuenode *head;
		Queuenode *tail;
		int count;
		int creatureType;
	private:
};

#endif
