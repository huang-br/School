#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>

class Creature
{
	public:
		//Functions
		virtual int attack(int) = 0;
		virtual int defend(int) = 0;
		//Accessors
		int getStrength();
		int getDamage();
		int getArmor();
		//Mutators
		void setStrength(int);
		void takeDamage(int);
	protected:
		int armor; 
		int strength;
		int damage;
};

#endif
