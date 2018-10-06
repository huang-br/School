#ifndef SWAN_H
#define SWAN_H

#include "Actor.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

class Swan : public Actor
{
	public:
		//Defualt Constructor
		Swan();
		//Overloaded Constructor
		Swan(int, int, char**);
		//Destructor;
		~Swan();
		//Functions
		bool action(char**);
		void move(char**);
		void moveCheck(char);
		void spawn(char**, int, int);
	private:
};

#endif
