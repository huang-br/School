#ifndef UNICORN_H
#define UNICORN_H

#include "Creature.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class Unicorn : public Creature
{
	public:
		//Default Constructor
		Unicorn();
		//Destructor
		~Unicorn();
		//Functions
		int attack(int);
		int defend(int);
	private:
};

#endif
