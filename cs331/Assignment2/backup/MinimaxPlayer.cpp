/*
 * MinimaxPlayer.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: wong
 */
#include <iostream>
#include <assert.h>
#include "MinimaxPlayer.h"
#define BOARD_SIZE 4

MinimaxPlayer::MinimaxPlayer(char symb) :
		Player(symb) {

}

MinimaxPlayer::~MinimaxPlayer() {

}

int MinimaxPlayer::Utility(OthelloBoard *b)
{
	int p1Score = b -> count_score(b -> get_p1_symbol());					//Getting the Score for player 1
	int p2Score = b -> count_score(b -> get_p2_symbol());					//Getting the Score for player 2

	return p1Score - p2Score;								//Returning the utility which is p1 score - p2 score
}

std::vector<OthelloBoard*> MinimaxPlayer::Successors(char player, OthelloBoard *b)
{
	std::vector<OthelloBoard*> successorStates;						//Creating a vector to store all the successors.
	int row = 0;
	int col = 0;
	for(col=0; col < BOARD_SIZE; col++)							//Iterating through the columns.
	{
		for(row=0; row < BOARD_SIZE; row++)						//Iterating through the rows.
		{
			if(b -> is_legal_move(col, row, player))
			{
				successorStates.push_back(new OthelloBoard(*b));		//Creating a new board for the successor state.
				successorStates.back() -> play_move(col, row, player);		//Making the move.
				successorStates.back() -> setColumn(col);			//Remembering the move.
				successorStates.back() -> setRow(row);
			}
		}
	}
	
	return successorStates;

}

int MinimaxPlayer::minimum(int &row, int &col, char player, OthelloBoard *b)
{
	int i =0;										//Initializing variables.
	int v = 32767;										//Creating the minimum value, starts at the largest value an Int can be.
	int minimumRow;										
	int minimumCol;
	std::vector<OthelloBoard*> successorBoards;						//Creating a list of successorBoards
	successorBoards = Successors(player, b);
	if(successorBoards.size() == 0)								//Basecase
	{
		return Utility(b);
	}

	for(i=0; i < successorBoards.size(); i++)						//Minimax algorithm
	{
		if(maximum(row, col, player, successorBoards[i]) > v)
		{
			minimumRow = successorBoards[i] -> getRow();
			minimumCol = successorBoards[i] -> getCol();
			v = maximum(row, col, player, successorBoards[i]);
		}
	}

	row = minimumRow;
	col = minimumCol;

	return v;

}

int MinimaxPlayer::maximum(int &row, int &col, char player, OthelloBoard *b)
{
	int i = 0;
	int v = -32767;
	int maximumRow;
	int maximumCol;
	std::vector<OthelloBoard*> successorBoards;
	successorBoards = Successors(player, b);
	if(successorBoards.size() == 0)
	{
		return Utility(b);
	}

	for(i=0; i < successorBoards.size(); i++)
	{
		if(maximum(row, col, player, successorBoards[i]) > v)
		{
			maximumRow = successorBoards[i] -> getRow();
			maximumCol = successorBoards[i] -> getCol();
			v = maximum(row, col, player, successorBoards[i]);
		}
	}

	row = maximumRow;
	col = maximumCol;

	return v;

}



void MinimaxPlayer::get_move(OthelloBoard* b, int& col, int& row) {
    // To be filled in by you
    if('X' == symbol)
    {
	    maximum(row, col, 'X', b);
    }
    else if('O' == symbol)
    {
	    maximum(row, col, 'O', b);
    }
}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}
