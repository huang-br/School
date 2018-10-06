#include "Barbarian.h"

Barbarian::Barbarian()
{
	armor = 0;
	strength = 12;
}


Barbarian::~Barbarian()
{

}

int Barbarian::attack(int detect)
{
	int atkVal = 0;
	for(int k = 0; k < 2; k++)
	{
		atkVal = atkVal + (rand()%6 +1);
	}

	return atkVal;

}

int Barbarian::defend(int Value)
{
	int defVal = 0;
	int armor = getArmor();
	int atkVal = Value - armor;
	for(int j = 0; j < 2; j++)
	{
		defVal = defVal + (rand()%6 + 1);
	}

	if (defVal >= atkVal)
	{
		return 0; 
	}

	else if(atkVal > defVal)
	{
		defVal = atkVal - defVal;
		takeDamage(defVal);
		return defVal;
	}
	
}	
