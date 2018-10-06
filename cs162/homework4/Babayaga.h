#ifndef BABAYAGA_H
#define BABAYAGA_H

#include "Creature.h"
#include <iostream>
#include <cstdlib>
#include <string>

class Babayaga : public Creature
{
	public:
		//Defualt Constructor
		Babayaga();
		//Destructor
		~Babayaga();
		//Function
		int attack(int, int);
		int defend();
		void heal();
	private:
};

#endif

