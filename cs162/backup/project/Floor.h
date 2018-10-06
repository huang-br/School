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
		char**& getBoard(); 
		//Mutators
		void updateBoard(char **);
		void getnewBoard(char **);
		//Functions
		void printBoard();
		void initializeBoard(int);
		void clean();
		
	protected:
		int row;
		int col;
		char **board;
		string name;
		int playerXpos;
		int playerYpos;
};

#endif
