#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include "Floor.h"
#include "Actor.h"
#include "Player.h"

using namespace std;

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout << "Not enough arguments" << endl;
	}
	else
	{
		int floorNum = atoi(argv[1]);
		
		//Floor Stuff
		Floor maze;
		maze.initializeBoard(floorNum);
		maze.printBoard();

		//Player Stuff
		Actor *player;
		int x = maze.getPlayerX();
		int y = maze.getPlayerY();
		player = new Player(x,y);
		
		for(int x = 0; x < 10; ++x)
		{
			player -> action(maze.getBoard());
			maze.printBoard();
		}
		
	}
		


return 0;
}
