#ifndef GAME_H
#define GAME_H

#include "Actor.h"
#include "Player.h"
#include "Swan.h"
#include "Floor.h"

class Game
{
	public:
		//Defualt Constructor
		Game();
		//Destructor
		~Game();
		//Functions
		void makeFloor();
		void print();
		void makeSwan();
		void makePlayer();

	private:
		Floor currentMaze;
		Actor *entities;
};

#endif
