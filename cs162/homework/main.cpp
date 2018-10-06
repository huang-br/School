/**********************************************************************************
 * Program: Homework1
 * Author: Brian Huang
 * Date: 1/15/2016
 * Description: Plays a game of tic-tac-toe.
**********************************************************************************/

#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

//Function Declarations
void initialize(int rows, int cols, char board[][]);
void PrintBoard(char board[][]);
bool BoardCheck(int row, int col,char board[][]);
void GetInput(int &row, int &col, int counter, char board[][]);
bool WinCheck(char board[][]);
bool InputCheck(int check);

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		cout <<"Enter your board size. rows then columns. "<< endl;
	}
	else
	{
		int row = atoi(argv[1]);
		int column = atoi(argv[2]);	
		char board[rows][columns];
		bool win = false;
		bool cont = true;

		while(cont == true){
			initialize(row,column,board);
			PrintBoard(board);
			for(int m=0; m <= 8; ++m){
				GetInput(row, column, m, board);
				win=WinCheck(board);
				if(win == true){
					cout << "Play again? (1 for yes - 0 for no) " ;
					cin >> cont;
					if( cont == true){
						break;
					}
					else if( cont == false){
						exit(0);
					}
				}
				else if(m == 8){
					cout << "Tie! Play again? " << endl;
					cout << "Play again? (1 for yes - 0 for no) " ;
					cin >> cont;
				}
			}
		}
	}
	return 0;
}



//Functions


/******************************************************************************
 * Function: initialize
 * Description: Fills the board with *
******************************************************************************/
void initialize(int rows, int cols, char board[][])
{
	for(int k=0; k < rows; ++k){
		for(int j=0; j < cols; ++j){
			board[k][j]='*';
		}
	}
}
/*****************************************************************************
 * Function: PrintBoard
 * Description: Prints out the current state of the board.
*****************************************************************************/
void PrintBoard(char board [][])
{	
	for(int k=0; k < 3; ++k)
	{
		for(int l=0; l < 3; ++l)
		{
			cout << " [" << board[k][l] << "] ";
		}
		cout << endl;
	}
}
/******************************************************************************
 * Function: BoardCheck
 * Description: Checks if the selected spot is empty. If the spot has anything
 		other than a * in it that means it is empty.
******************************************************************************/
bool BoardCheck(int row, int col, char board[][3])
{
	if(board[row][col] != '*'){
		cout << "That spot has already been taken! " << endl;
		return false;
	}
	else{
		return true;
	}
}
/*******************************************************************************
 * Function: GetInput
 * Description: Gets the input from the player. The input is determined by a
 		counter which determines the turn and which symbol is placed.
		This function also runs 2 error checking functions to make
		sure the input is good and the spot is empty.
*******************************************************************************/
void GetInput(int &row, int &col, int counter, char board[][3])
{
	bool SpotFree = false;

		if(counter%2 == 0){
			cout << "Player 1, where do you want to go? " << endl;
		}
		else{
			cout << "Player 2, where do you want to go? " << endl;
		}

		while(SpotFree == false){
			bool GoodInput_row = false;
			while(GoodInput_row == false){
				cout << "Row: " ;
				cin >> row;
				GoodInput_row = InputCheck(row);
			}
			row = row-1;
			bool GoodInput_col = false;
			while(GoodInput_col == false){
				cout << "Column: ";
				cin >> col;
				GoodInput_col = InputCheck(col);		
			}
			col = col-1;
			SpotFree = BoardCheck(row, col, board); 
			
		}

		if(counter%2 == 0){	
			board[row][col] = 'X';
		}
		else{
			board[row][col] = 'O';
		}
		PrintBoard(board);
}
/********************************************************************************
 * Function: WinCheck
 * Description: Determines the winner based on the current condition of the board.
 		There is one loop that checks both rows and columns. After the 
		loop diagonals are checked.
********************************************************************************/
bool WinCheck(char board[][3])
{
	for(int i=0; i <= 2; ++i){
		//Check Rows
		if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X'){
			cout << "Player 1 wins! " << endl; 
			return true;
		}

		else if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O'){
			cout << "Player 2 wins! " << endl;
			return true; 
		}

		//Check Columns
		else if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X'){
			cout << "Player 1 wins! " << endl; 
			return true;
		}

		else if(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O'){
			cout << "Player 2 wins! " << endl;
			return true; 
		}
	}
	
		//Check Diagnoals
		if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
			cout << "Player 1 wins! " << endl;
			return true;
		}
	
		else if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
			cout << "Player 1 wins! " << endl;
			return true;
		}
	
		else if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
			cout << "Player 2 wins! " << endl;
			return true;
		}
	
		else if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
			cout << "Player 2 wins! " << endl;
			return true;
		}
	
		else{
			return false;
		}


}
/***********************************************************************************
 * Function: InputCheck
 * Description: Checks for a proper input for a row and column. If the input number
 		is not 1, 2 or 3 the function will return false and will loop the 
		user back to ask for an input again.
***********************************************************************************/
bool InputCheck(int check)
{
	if(check == 1 || check == 2 || check == 3){
		return true;
	}
	else{
		cout << "Please put 1, 2 or 3. " << endl;
		return false;
	}
}	

