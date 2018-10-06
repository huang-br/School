#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Creature.h"
#include <iostream>
#include <cstdlib>

class Barbarian : public Creature
{
	public:
		//Default Constructor
		Barbarian();
		//Destructor
		~Barbarian();
		//Function
		int attack(int);
		int defend(int);
	private:
};

#endif
