#include "Barbarian.h"

Barbarian::Barbarian()
{
	armor = 0;
	strength = 12;
	name = "Barbarian";
}


Barbarian::~Barbarian()
{

}

int Barbarian::attack(int detect, int defVal)
{
	int atkVal = 0;
	int damage;
	for(int k = 0; k < 2; k++)
	{
		atkVal = atkVal + (rand()%6 +1);
	}

	if (defVal >= atkVal)
	{
		return 0; 
	}

	else if(atkVal > defVal)
	{
		damage = atkVal - defVal;
		return damage;
	}

}

int Barbarian::defend()
{
	int defVal = 0;
	int armor = getArmor();
	for(int j = 0; j < 2; j++)
	{
		defVal = defVal + (rand()%6 + 1);
	}
	defVal = defVal + armor;

	return defVal;	
}

void Barbarian::heal()
{
	int strength = getStrength();
	if(strength < 12)
	{
		strength = strength + 6;
		if(strength > 12)
		{
			setStrength(12);
		}
		else
		{
			setStrength(strength);
		}
	}
	else
	{
	
	}

}
		
