#include "Bluemen.h"

Bluemen::Bluemen()
{
	armor = 3;
	strength = 12;
}

Bluemen::~Bluemen()
{

}

int Bluemen::attack(int detect)
{
	int atkVal = 0;
	for(int k=0; k < 2; k++)
	{
		atkVal = atkVal + (rand()%10 + 1);
	}
	
	return atkVal;
}

int Bluemen::defend(int Value)
{
	int defVal = 0;
	int armor = getArmor();
	int atkVal = Value - armor;
	int Strength = getStrength();

	if(Strength >= 9 && Strength <= 12)
	{
		for(int j = 0; j < 3; j++)
		{
			defVal = defVal + (rand()%6 +1);	
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
	else if(Strength >= 5 && Strength <= 8)
	{
		for(int j = 0; j < 2; j++)
		{
			defVal = defVal + (rand()%6 +1);	
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
	else if(Strength >= 4 && Strength <= 1)
	{
	
		defVal = defVal + (rand()%6 +1);	
	
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
}
