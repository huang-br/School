#include "Player.h"

using std::cout;
using std::cin;
using std::endl;

//Defualt Constructor
Player::Player()
{

}

//Overloaded Constructor
Player::Player(int x, int y)
{
	startX = x;
	startY = y;
	numApples = 0;
	numKeys = 0;
	nextX = x;
	nextY = y;
	nextCharBuffer = 'E';
}

//Destructor
Player::~Player()
{

}

bool Player::action(char **board)
{
	char choice;
	bool goodMove;
	bool validInput = false;
	while(validInput == false)
	{
		cout << "Input: ";
		cin >> choice;
		validInput = goodInput(choice);
	}
		
	
	if(choice =='w')	
	{
		prevX = nextX;
		prevY = nextY;
		goodMove = moveCheck(board[nextX-1][nextY]);
		if(goodMove == true)
		{
			nextX--;
			move(board);
		}
		else
		{
		}
	}
	else if(choice == 'a')
	{
		prevX = nextX;
		prevY = nextY;
		goodMove = moveCheck(board[nextX][nextY-1]);
		if(goodMove == true)
		{
			nextY--;
			move(board);
		}
		else
		{
		}
	}
	else if(choice == 'd')
	{
		prevX = nextX;
		prevY = nextY;
		goodMove = moveCheck(board[nextX][nextY+1]);
		if(goodMove == true)
		{
			nextY++;
			move(board);
		}
		else
		{
		}

	}
	else if(choice == 's')
	{
		prevX = nextX;
		prevY = nextY;
		goodMove = moveCheck(board[nextX+1][nextY]);
		if(goodMove == true)
		{
			nextX++;
			move(board);
		}
		else
		{
		}
	}
	else if(choice == 'e')
	{
		if(numApples > 0)
		{
			cout << "You ate an apple. " << endl;
			numApples--;
		}
		else
		{
			cout <<"You have no apples." << endl;
		}
	}
	else if(choice == 'u')
	{
		if(nextCharBuffer == 'L')
		{
			cout << "You go to the next level." << endl;
			return true;
		}
		else
		{
			cout << "There is no ladder here..." << endl;
		}
	}
	else if(choice == 'q')
	{
		exit(0);
	}
	return false;
}

void Player::addApples()
{
	if(numApples == 2)
	{
		numApples++;
		cout << "You already have 2 apples. " <<endl;
	}
	else
	{
		numApples++;
		cout <<"You pick up an apple." << endl;
	}
}

void Player::addKeys()
{
	if(numKeys == 3)
	{
		numKeys++;
		cout << "You already have 3 keys. " << endl;
	}
	else
	{
		numKeys++;
		cout << "You picked up a key." << endl;
	}
}

bool Player::moveCheck(char x)
{
	if(x == '#')
	{
		cout << "There is a wall in the way. " << endl;
		return false;
	}
	else if(x == 'A')
	{
		addApples();
		return true;
	}
	else if(x == 'K')
	{
		addKeys();
		return true;
	}
	else if(x == 'D')
	{
		if(numKeys > 0)
		{
			cout << "You use a key to open the Door. " << endl;
			numKeys--;
			return true;
		}
		else
		{
			cout << "You have no keys. " << endl;
			return false;
		}
	}
	else if(x == 'L')
	{
		cout <<"Theres a ladder here." << endl;
		return true;
	}
	else if(x == 'S')
	{
		cout << "Theres a swan here. " << endl;
		return false;
	}
	else
	{
		if(x != ' ')
		{
			cout <<"wtf is this? " << endl;
		}
		return true;
	}
}

void Player::move(char **board)
{
	if(numApples > 2)
	{
		numApples--;
		board[prevX][prevY] = 'A';
		board[nextX][nextY] = 'P';
		cout << "You drop an apple. " << endl;
	}
	else if(numKeys > 3)
	{
		numKeys--;
		board[prevX][prevY] = 'K';
		board[nextX][nextY] = 'P';
		cout << "You drop a key. " << endl;
	}
	else if(nextCharBuffer == 'E')
	{
		board[prevX][prevY] = 'E';
		board[nextX][nextY] = 'P';
		nextCharBuffer = NULL;
	}
	else if(nextCharBuffer == 'L')
	{
		board[prevX][prevY] = 'L';
		board[nextX][nextY] = 'P';
		nextCharBuffer = NULL;
	}
	else
	{
		nextCharBuffer = board[nextX][nextY];
		board[prevX][prevY] = ' ';	
		board[nextX][nextY] = 'P';
	}
	
	if(board[nextX + 1][nextY] == 'S' || board[nextX - 1][nextY] == 'S' || board[nextX][nextY + 1] == 'S' || board[nextX][nextY - 1] == 'S')
	{
		sendBack(board);
	}
}

void Player::sendBack(char **board)
{
	board[nextX][nextY] = ' ';
	board[startX][startY] = 'P';
	nextX = startX;
	nextY = startY;
	nextCharBuffer = 'E';	
}

bool Player::goodInput(char x)
{
	if(x != 'w' && x != 'a' && x != 's' && x != 'd' && x!= 'e' && x != 'q' && x != 'u')
	{
		cout << "Not a valid Input. " << endl;
		return false;
	}
	else
	{
		return true;
	}
}
