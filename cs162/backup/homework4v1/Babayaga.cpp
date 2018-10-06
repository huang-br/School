#include "Babayaga.h"

Babayaga::Babayaga()
{
	armor = 3;
	strength = 12;
	name = "Babayaga";
}

Babayaga::~Babayaga()
{

}

int Babayaga::attack(int detect, int defVal)
{
	int atkVal = 0;
	int strength = getStrength();
	int newStrength;
	int damage;
	atkVal = rand()%6 + 1;

	if(defVal >= atkVal)
	{
		return 0;
	}
	else if(atkVal > defVal)
	{
		damage = atkVal - defVal;
		newStrength = strength + damage;
		setStrength(newStrength);
		cout << "Babayaga has drained " << damage << " point of life." << endl;
		return damage;
	}	
}



int Babayaga::defend()
{
	int defVal = 0;
	int armor = getArmor();

	defVal = rand()%10 + 1;
	defVal = defVal + armor;

	return defVal;
}

