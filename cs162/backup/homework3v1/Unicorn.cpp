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

int Unicorn::attack(int detect)
{
	int atkVal = 0;
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

return atkVal;
}

int Unicorn::defend(int Value)
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
