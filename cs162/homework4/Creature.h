#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>

using namespace std;

class Creature
{
	public:
		//Virtual Functions
		virtual int attack(int, int) = 0;
		virtual int defend() = 0;
		virtual void heal() = 0;
		//Accessors
		int getStrength();
		int getArmor();
		string getName();
		//Mutators
		void setStrength(int);
		int takeDamage(int);
	protected:
		int armor; 
		int strength;
		int damage;
		string name;
};

#endif
