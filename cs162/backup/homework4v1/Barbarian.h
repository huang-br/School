#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Creature.h"
#include <iostream>
#include <cstdlib>
#include <string>

class Barbarian : public Creature
{
	public:
		//Default Constructor
		Barbarian();
		//Destructor
		~Barbarian();
		//Function
		int attack(int, int);
		int defend();
	private:
};

#endif
