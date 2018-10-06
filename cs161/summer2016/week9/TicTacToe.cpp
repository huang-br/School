/***************************************************************
 * Author: Brian Huang
 * Date: 8/2/2016
 * Description: The implementation of the TicTacToe class and
		main file that plays the game.
**************************************************************/

#include "TicTacToe.hpp"

TicTacToe::TicTacToe()
{
}

TicTacToe::~TicTacToe()
{
}

TicTacToe::TicTacToe(char symbol)
{
	if(symbol == 'X')
	{
		turn = 0;
	}
	else if(symbol =='O')
	{
		turn = 1;
	}
}

void TicTacToe::play()
{
	int counter = 0;
	State currentState = UNFINISHED;
	while(currentState == UNFINISHED)
	{
		counter++;
		system("clear");
		if((counter + turn)%2 == 0)
		{	
			cout << "O player, make your move. " << endl;
		} 
		else if((counter + turn)%2 != 0)
		{
			cout << "X player, make your move. " << endl;
		}
		else
		{
			cout << "Something went horribly wrong." << endl;
		}
		board.print();
		board.makeMove(counter + turn);
		currentState = board.gameState(counter);
	}
	if(currentState == X_WINS)
	{
		cout << "X Wins!!! " << endl;
	}
	else if(currentState == O_WINS)
	{
		cout << "O Wins!!! " << endl;
	}
	else if(currentState == DRAW)
	{
		cout << "DRAW" << endl;
	}

}

int main()
{
	char playerOne;
	bool goodPlayer = false;

	//Determining who goes first
	while(goodPlayer == false)
	{
		cout << "Who should go first? X or O? ";
		cin >> playerOne;
		if((playerOne == 'X') || (playerOne == 'O'))
		{
			goodPlayer = true;
		}
		else
		{
			cout << "Bad input. Please try again." << endl;
		}
	}

	TicTacToe newGame(playerOne);
	newGame.play();
	
	return 0;
}

