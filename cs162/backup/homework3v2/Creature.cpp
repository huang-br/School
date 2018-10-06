#include "Creature.h"

int Creature::getStrength()
{
	return strength;
}
	
void Creature::setStrength(int value)
{
	strength = value;
}

int Creature::takeDamage(int value)
{
	strength = strength - value;
	return strength;
}

int Creature::getArmor()
{
	return armor;
}


