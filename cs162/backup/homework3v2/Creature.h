#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>

class Creature
{
	public:
		//Virtual Functions
		virtual int attack(int, int) = 0;
		virtual int defend() = 0;
		//Accessors
		int getStrength();
		int getDamage();
		int getArmor();
		//Mutators
		void setStrength(int);
		int takeDamage(int);
	protected:
		int armor; 
		int strength;
		int damage;
};

#endif
