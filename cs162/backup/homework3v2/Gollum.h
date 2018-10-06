#ifndef GOLLUM_H
#define GOLLUM_H

#include "Creature.h"
#include <iostream>
#include <cstdlib>

class Gollum : public Creature
{
	public:
		//Defualt Constructor
		Gollum();
		//Destructor
		~Gollum();
		//Function
		int attack(int, int);
		int defend();
	private:
};

#endif
