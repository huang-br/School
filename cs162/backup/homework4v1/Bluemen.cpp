#include "Bluemen.h"

Bluemen::Bluemen()
{
	armor = 3;
	strength = 12;
	name = "Bluemen";
}

Bluemen::~Bluemen()
{

}

int Bluemen::attack(int detect, int defVal)
{
	int atkVal = 0;
	int damage;
	for(int k=0; k < 2; k++)
	{
		atkVal = atkVal + (rand()%10 + 1);
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

int Bluemen::defend()
{
	int defVal = 0;
	int armor = getArmor();
	int Strength = getStrength();

	if(Strength >= 9 && Strength <= 12)
	{
		for(int j = 0; j < 3; j++)
		{
			defVal = defVal + (rand()%6 +1);	
		}
		defVal = defVal + armor;
		return defVal;
	}
	
	else if(Strength >= 5 && Strength <= 8)
	{
		for(int j = 0; j < 2; j++)
		{
			defVal = defVal + (rand()%6 +1);	
		}
		defVal = defVal + armor;	
		return defVal;
	}

	else if(Strength >= 4 && Strength <= 1)
	{	
		defVal = defVal + (rand()%6 +1);
		defVal = defVal + armor;	
		return defVal;
	}
}

