#include "Game.h"

//Defulat Constructor
Game::Game()
{

}

//Destructor
Game::~Game()
{

}

//Functions
void Game::makeFloor(int numFloors)
{
	currentMaze.initializeBoard(numFloors);
}

void Game::print()
{
	currentMaze.printBoard();
}

void Game::makePlayer()
{
	user = new Player(currentMaze.getPlayerX(), currentMaze.getPlayerY());
}

void Game::makeSwan(int count)
{	
	Enemies = new Swan[count];
}

void Game::cleanActors(int count)
{
	if(count < 30)
	{
		delete user;
	}
	else
	{
		delete user;
		delete Enemies;
	}
}

void Game::play(int floorNum)
{
	//Floor Stuff
	currentMaze.initializeBoard(floorNum);
	currentMaze.printBoard();

	//Player Stuff
	int counter = 0;
	int swanCount = 0;

	int row = currentMaze.getRow();
	int col = currentMaze.getCol();
	makePlayer();
	
	bool levelComplete = false;
	
	while(levelComplete == false)	
	{
		levelComplete = user -> action(currentMaze.getBoard());
		counter++;
		cout << counter << endl;
		if(counter % 30 == 0)
		{
			Enemies = new Swan(row, col, currentMaze.getBoard());
		}
		currentMaze.printBoard();
	}
	currentMaze.clean();
	cleanActors(counter);
}
	
