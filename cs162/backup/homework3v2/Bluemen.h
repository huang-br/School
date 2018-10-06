#ifndef BLUEMEN_H
#define BLUEMEN_H

#include "Creature.h"
#include <iostream>
#include <cstdlib>

class Bluemen : public Creature
{
	public:
		//Default Constructor
		Bluemen();
		//Destructor
		~Bluemen();
		//Function
		int attack(int, int);
		int defend();
	private:
};

#endif
