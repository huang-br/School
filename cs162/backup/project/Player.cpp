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
	numApples = 0;
	numKeys = 0;
	nextX = x;
	nextY = y;
}

//Destructor
Player::~Player()
{

}

void Player::action(char **board)
{
	char choice;
	bool goodMove;
	cout << "Input: ";
	cin >> choice;
	
	if(choice =='w')	
	{
		prevX = nextX;
		prevY = nextY;
		goodMove = moveCheck(board[nextX-1][nextY]);
		if(goodMove == true)
		{
			nextX = nextX - 1;
			board[prevX][prevY] = ' ';
			board[nextX][nextY] = 'P';
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
			nextY = nextY - 1;
			board[prevX][prevY] = ' ';
			board[nextX][nextY] = 'P';
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
			nextY = nextY + 1;
			board[prevX][prevY] = ' ';
			board[nextX][nextY] = 'P';
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
			nextX = nextX + 1;
			board[prevX][prevY] = ' ';
			board[nextX][nextY] = 'P';
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
}

void Player::addApples()
{
	if(numApples == 2)
	{
		cout << "You already have 2 apples. " << endl;
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
	else
	{
		return true;
	}
}
	
