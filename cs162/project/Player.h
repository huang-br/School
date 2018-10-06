#ifndef PLAYER_H
#define PLAYER_H

#include "Actor.h"
#include <iostream>
#include <cstdlib>
#include <string>

class Player : public Actor
{
	public:
		//Defualt Constructor
		Player();
		//Overloaded Constructor
		Player(int, int);
		//Destructor
		~Player();
		//Functions
		bool action(char**);
		void addApples();
		void addKeys();
		bool moveCheck(char);
		void move(char**);
		void sendBack(char**);
		bool goodInput(char);
	private:
		int numApples;
		int numKeys;
		char nextCharBuffer;
};

#endif



