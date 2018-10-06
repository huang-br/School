#include "Floor.h"

int Floor::getPlayerX()
{
	return playerXpos;
}

int Floor::getPlayerY()
{
	return playerYpos;
}

char**& Floor::getBoard()
{
	return board;
}

int Floor::getRow()
{
	return row;
}

int Floor::getCol()
{
	return col;
}

void Floor::initializeBoard(int amtFloors)
{
	stringstream level(stringstream::out | stringstream::in);
	level << "floor_" << amtFloors << ".txt";
	string name = level.str();

	ifstream inStream(name.c_str(), ifstream::in);
	if(inStream.fail())
	{
		cout << "File does not exist." << endl;
		exit(0);
	}
	char c = 'x';
	int i = 0;
	string getRow;
	string getCol;
	//Getting the row and column numbers.
	while(c != '\n')
	{
		c = inStream.get();
		if(c == ' ')
		{
			i = 1;
		}
		
		if(i == 0)
		{
			getRow = getRow + c;
		}
		else if(i == 1)
		{
			getCol = getCol + c;
		}
	}
	row = atoi(getRow.c_str());
	col = atoi(getCol.c_str()) + 1;
	cout << row << endl;
	cout << col << endl;

	//Creating the board
	board = new char *[row];
	for(int j=0; j < row; ++j)
	{
		board[j] = new char[col];
		for(int k=0; k < col; ++k)
		{
			c = inStream.get();
			if(c == 'E')
			{
				playerXpos = j;
				playerYpos = k;
			}
			if(c == 'L')
			{
				ladderXpos = j;
				ladderYpos = k;
			}
			if(c == 'S')
			{
				c = ' ';
			}
			board[j][k] = c;
		}
	}
	cout << playerXpos << endl;
	cout << playerYpos << endl;
}

void Floor::printBoard()
{
	for(int j=0; j < row; ++j)
	{
		for(int k=0; k < col; ++k)
		{
			cout << board[j][k];
		}
	}
}

void Floor::clean()
{
	for(int k=0; k < row; ++k)
	{
		delete[] board[k];
	}
	delete[] board;
}	
