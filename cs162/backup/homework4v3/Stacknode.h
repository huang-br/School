#ifndef STACKNODE_H
#define STACKNODE_H

#include "Creature.h"

class Stacknode
{
	public:
		Stacknode(Creature*, int, Stacknode*);
		Creature *fighter;
		int index;
		Stacknode *next;
	private:
};

#endif
