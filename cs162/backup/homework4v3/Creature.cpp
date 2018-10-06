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
	if(strength < 0)
	{
		return 0;
	}
	else
	{
		return strength;
	}
}

int Creature::getArmor()
{
	return armor;
}

string Creature::getName()
{
	return name;
}
