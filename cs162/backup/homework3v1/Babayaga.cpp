#include "Babayaga.h"

Babayaga::Babayaga()
{
	armor = 3;
	strength = 12;
}

Babayaga::~Babayaga()
{

}

int Babayaga::attack(int detect)
{
	int atkVal = 0;
	int defVal = 0;
	int newStrength;
	atkVal = rand()%6 + 1;

	//Gollum
	if(detect == 1)
	{
		for(int j = 0; j < 2; j++)
		{
			defVal = defVal + (rand()%6 + 1);
		}

		if(defVal >= atkVal)
		{

		}

		else if(atkVal > defVal)
		{
			defVal = atkVal - defVal - 1;
			newStrength = getStrength() + defVal;
			setStrength(newStrength);
		}	
	}
	//Barbarian
	else if(detect == 2)
	{
		for(int j = 0; j < 2; j++)
		{
			defVal = defVal + (rand()%6 + 1);
		}

		if (defVal >= atkVal)
		{

		}

		else if(atkVal > defVal)
		{
			defVal = atkVal - defVal;
			newStrength = getStrength() + defVal;
			setStrength(newStrength);
		}
	}
	//Baba Yaga
	else if(detect == 3)
	{
		defVal = rand()%10 + 1;

		if(defVal >= atkVal)
		{

		}

		else if(atkVal > defVal)
		{
			defVal = atkVal - defVal - 3;
			newStrength = getStrength() + defVal;
			setStrength(newStrength);
		}
	}
	//Unicorn
	else if(detect == 5)
	{
		for(int j = 0; j < 2; j++)
		{
			defVal = defVal + (rand()%6 + 1);
		}

		if (defVal >= atkVal)
		{

		}

		else if(atkVal > defVal)
		{
			defVal = atkVal - defVal - 3;
			newStrength = getStrength() + defVal;
			setStrength(newStrength);
		}

	}
	else
	{

	}
	return atkVal;
}

	int Babayaga::defend(int Value)
	{
		int defVal = 0;
		int armor = getArmor();
		int atkVal = Value - armor;

		defVal = rand()%10 + 1;

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

