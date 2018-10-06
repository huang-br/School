#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	int amtLevels;
	int row, col;
	char **board;
	if(argc != 2)
	{
		cout << "Enter a proper file name." << endl;
	}
	else
	{
		//Getting the level name.
		amtLevels = 1;
		stringstream level(stringstream::out | stringstream::in);
		level << "floor_" << amtLevels << ".txt";
		string name = level.str();

		ifstream inStream(name.c_str(), ifstream::in);
		if(inStream.fail())
		{
			cout << "File does not exist." << endl; 
		}
		else
		{
			char c;
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
			col = atoi(getCol.c_str());
			cout << row << endl;
			cout << col << endl;

			//Creating the board.	
			board = new char *[row];
			for(int j=0; j < row; ++j)
			{
				board[j] = new char[col];
				for(int k=0; k < col; ++k)
				{	
					c = inStream.get();
					board[j][k] = c;
				}
			}
					
			
		}
		
		//Printing the board.
		for(int j=0; j < row; ++j)
		{
			for(int k=0; k < col-1; ++k)
			{	
				cout << board[j][k];
			}
		}
		
		inStream.close();
	}


return 0;
}
