#include "Swan.h"
#include "Floor.h"

//Defualt Constructor
Swan::Swan()
{

}

//Overloaded Constructor
Swan::Swan(int row, int col, char **board)
{
	bool goodSpawn = false;
	while(goodSpawn == false)
	{
		int SpawnX = rand()%row + 1;
		int SpawnY = rand()%col + 1;
		if(board[SpawnX][SpawnY] == ' ')
		{
			board[SpawnX][SpawnY] = 'S';
			goodSpawn = true;
		}
	}
}

//Destructor
Swan::~Swan()
{

}

//Functions
bool Swan::action(char **board)
{
	int direction;
	direction = rand()% 4 + 1;
}
