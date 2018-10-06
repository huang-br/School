/*****************************************************************
 * Author: Brian Huang
 * Date: 8/2/2016
 * Description: The header file for the Board Class.
*****************************************************************/

#ifndef BOARD_HPP
#define BOARD_CPP

#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

enum State {X_WINS, O_WINS, DRAW, UNFINISHED};

class Board
{
	public:
		//Defualt Constructor
		Board();
		//Destructor
		~Board();
		//Functions
		void makeMove(int);
		int moveCheck();
		enum State gameState(int);
		void print();
	private:
		char board[3][3];
};

#endif
