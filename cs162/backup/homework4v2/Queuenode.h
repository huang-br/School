#ifndef QUEUENODE_H
#define QUEUENODE_H

#include "Creature.h"

class Queuenode
{
	public:
		//Constructor
		Queuenode(Creature*, Queuenode*, Queuenode*, int, int);
		//Data
		Creature *fighter;
		Queuenode *prev; 
		Queuenode *next;
		int index;
		int type;
	private:

};

#endif
