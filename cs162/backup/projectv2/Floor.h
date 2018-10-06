#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

class Floor
{
	public:
		//Accessors
		int getPlayerX();
		int getPlayerY();
		int getRow();
		int getCol();
		char**& getBoard(); 
		//Functions
		void printBoard();
		void initializeBoard(int);
		void clean();
		bool levelCompleteCheck();
		
	protected:
		int row;
		int col;
		char **board;
		string name;
		int playerXpos;
		int playerYpos;
		int ladderXpos;
		int ladderYpos;
};

#endif
