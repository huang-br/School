#include "Gollum.h"

Gollum::Gollum()
{
	armor = 1;
	strength = 8;
}

Gollum::~Gollum()
{

}

int Gollum::attack(int detect, int defVal)
{
	int atkVal = 0;
	int chance;
	int damage;
	chance = rand()%20 + 1;
	if(chance == 1)
	{
		for(int k=0; k < 3; k++)
		{
			atkVal = atkVal + (rand()%6 +1);
		}
	}
	else
	{
		atkVal = rand()%6 + 1;	
	}

	if(defVal >= atkVal)
	{
		return 0;
	}

	else if(atkVal > defVal)
	{
		damage = atkVal - defVal;
		return damage;
	}
}

int Gollum::defend()
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

