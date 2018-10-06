#ifndef GOLLUM_H
#define GOLLUM_H

#include "Creature.h"
#include <iostream>
#include <cstdlib>
#include <string>

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
		void heal();
	private:
};

#endif
