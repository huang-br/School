#include "Creature.h"

int Creature::getStrength()
{
	return strength;
}
	
void Creature::setStrength(int value)
{
	strength = value;
}

void Creature::takeDamage(int value)
{
	strength = strength - value;
}

int Creature::getArmor()
{
	return armor;
}


