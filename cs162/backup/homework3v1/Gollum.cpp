#include "Gollum.h"

Gollum::Gollum()
{
	armor = 1;
	strength = 8;
}

Gollum::~Gollum()
{

}

int Gollum::attack(int detect)
{
	int atkVal = 0;
	int chance;
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
}

int Gollum::defend(int Value)
{
	int defVal = 0;
	int armor = getArmor();
	int atkVal = Value - armor;
	for(int j = 0; j < 2; j++)
	{
		defVal = defVal + (rand()%6 + 1);
	}

	if(defVal >= atkVal)
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
