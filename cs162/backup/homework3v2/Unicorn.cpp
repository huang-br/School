#include "Unicorn.h"
#include <iostream>

Unicorn::Unicorn()
{
	armor = 3;
	strength = 18;
}

Unicorn::~Unicorn()
{

}

int Unicorn::attack(int detect, int defVal)
{
	int atkVal = 0;
	int damage;
	int StrengthCheck = getStrength();
	
	if(StrengthCheck < 18 || detect == 5)
	{
		cout << "Unicorn is enraged!" << endl;
		for(int k = 0; k < 2; k++)
		{
			atkVal = atkVal + rand()%6 + 1;
		}
	
		atkVal = atkVal + rand()%20 + 1;
	}
	
	
	else
	{	
		cout << "Unicorn is calm, does nothing." << endl;
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

int Unicorn::defend()
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
