#include "Queuenode.h"

Queuenode::Queuenode(Creature *data, Queuenode *p, Queuenode *n, int creatureType, int num)
{
	fighter = data;
	prev = p;
	next = n;
	index = num;
	type = creatureType;
}
