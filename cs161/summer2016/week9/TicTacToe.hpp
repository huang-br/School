/**********************************************************************
 * Author: Brian Huang
 * Date: 8/2/2016
 * Description: The header file for the TicTacToe Class.
*********************************************************************/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"

class TicTacToe
{
	public:
		//Constructor
		TicTacToe();
		//Overloaded Constructor
		TicTacToe(char);
		//Destructor
		~TicTacToe();
		//Functions;
		void play();
	private:
		Board board;
		int turn;
};

#endif
