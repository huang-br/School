/*********************************************************************8
 * Author: Brian Huang
 * Date: 8/2/2016
 * Description: The implementation file for the Board class.
***********************************************************************/

#include "Board.hpp"

Board::Board()
{
	for(int k =0; k < 3; k++)
	{
		for(int j = 0; j < 3; j++)
		{
			board[j][k] = ' ';
		}
	}
}

Board::~Board()
{
}

void Board::makeMove(int turn)
{
	int x, y;
	bool check = false;
	while(check == false)
	{
		cout << "What Column: ";
		y = moveCheck() - 1; 
		cout << "What Row: ";
		x = moveCheck() - 1;
		if(board[x][y] == ' ')
		{
			if(turn%2 != 0)
			{
				board[x][y] = 'X';
			}
			else
			{
				board[x][y] = 'O';
			}
			check = true;
		}
		else
		{
			cout << "That space has already been taken. Please try again. " << endl;
		}
	}
}

int Board::moveCheck()
{
	bool good = false;
	int spot;
	while(good == false)
	{
		cin >> spot;
		if((spot == 1) || (spot == 2) || (spot == 3))
		{
			good = true;
		}
		else
		{
			cout << "Invalid Spot. Try again. " ;
		}
	}
	return spot;
}




State Board::gameState(int counter)
{
	for(int k=0; k < 3; k++)
	{
		//Row Check
		if(board[k][0] == 'X' && board[k][1] =='X' && board[k][2] == 'X')
		{
			return X_WINS;
		}
		else if(board[k][0] == 'O' && board[k][1] =='O' && board[k][2] == 'O')
		{
			return O_WINS;
		}

		//Column Check	
		if(board[0][k] == 'X' && board[1][k] =='X' && board[2][k] == 'X')
		{
			return X_WINS;
		}
		else if(board[0][k] == 'O' && board[1][k] =='O' && board[2][k] == 'O')
		{
			return O_WINS;
		}
	}

	if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
	{
		return X_WINS;
	}
	else if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
	{
		return X_WINS;
	}
	else if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
	{
		return O_WINS;
	}
	else if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
	{
		return O_WINS;
	}
	else if(counter == 9)
	{
		return DRAW;
	}
	else
	{
		return UNFINISHED;
	}
}


void Board::print()
{
	cout << "  " << " 1 " << "  2 " << "  3" << endl;
	for(int k=0; k < 3; k++)
	{
		cout << k+1;
		for(int j=0; j < 3; j++)
		{
			cout << " " << "[" << board[k][j] << "]";
		}
		cout << endl;
	}
}

	
		

