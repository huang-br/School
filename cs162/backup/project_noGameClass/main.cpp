#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Floor.h"
#include "Actor.h"
#include "Player.h"
#include "Swan.h"

using namespace std;

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout << "Not enough arguments" << endl;
	}
	else
	{
		srand(time(NULL));
		int floorNum = atoi(argv[1]);
		for(int k = 0; k < atoi(argv[1]); ++k)
		{
			//Floor Stuff
			Floor maze;
			maze.initializeBoard(floorNum);
			maze.printBoard();

			//Player Stuff
			Actor *player;
			Actor *player2;
			int counter = 0;
			int swanCount = 0;
			int x = maze.getPlayerX();
			int y = maze.getPlayerY();
			int row = maze.getRow();
			int col = maze.getCol();
			player = new Player(x,y);
			bool levelComplete = false;
	
			while(levelComplete == false)	
			{
				levelComplete = player -> action(maze.getBoard());
				counter++;
				if(counter % 30 == 0)
				{
					player2 = new Swan(row, col, maze.getBoard());
				}
				maze.printBoard();
			}
			maze.clean();
			floorNum--;
		}
		cout << "You have escaped!" << endl;	
	}
		


return 0;
}
