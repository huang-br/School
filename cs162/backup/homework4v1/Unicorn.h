#ifndef UNICORN_H
#define UNICORN_H

#include "Creature.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Unicorn : public Creature
{
	public:
		//Default Constructor
		Unicorn();
		//Destructor
		~Unicorn();
		//Functions
		int attack(int, int);
		int defend();
	private:
};

#endif
