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
		void makeFloor(int);
		void print();
		void makeSwan(int);
		void makePlayer();
		void play(int);
		void cleanActors(int);

	private:
		Floor currentMaze;
		Actor *Enemies;
		Actor *user;
};

#endif
