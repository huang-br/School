#ifndef STACKNODE_H
#define STACKNODE_H

#include "Creature.h"

class Stacknode
{
	public:
		Stacknode(Creature*, Stacknode*);
		Creature *fighter;
		Stacknode *next;
	private:
};

#endif
