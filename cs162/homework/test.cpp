#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void printBoard(int row, int col, char *board[]);
void initializeBoard(int, int, char *[]);
int main(int argc, char *argv[])
{
	int row = atoi(argv[1]);
	int column = atoi(argv[2]);
	
	//Creating the game board.
	char *board[row];
	for(int i=0; i < row; ++i)
	{
		board[i] = new char[column];
	}	
	
	initializeBoard(row, column, board);
	printBoard(row, column, board);
	return 0;
}

void initializeBoard(int row, int col, char *board[])
{
	for(int i=0; i < row; ++i)
	{
		for(int j=0; j < col; ++j)
		{
			board[i][j] = '*';
		}
	}
}

void printBoard(int row, int col, char *board[])
{
	for(int i=0; i < row; ++i)
	{
		for(int j=0; j < col; ++j)
		{	
			cout << '[' << board[i][j] << ']';
		}
		cout << endl;
	}
}
