/************************************************************************************
 * Program Filename: Connectfour
 * Author: Brian Huang
 * Date: 11/22/2015
 * Description: Plays the connect four game.
 * Input: Which column the player want to put their piece in.
 * Output: The board with the modified position.
************************************************************************************/
#include <iostream>
#include <string.h>

#define ROWS 7
#define COLS 6

using namespace std;

//Function Prototypes
void initialize_board(int**[ROWS][COLS]);
int get_turn();
bool input_checker(int);
void change_board(int **[ROWS][COLS], int);
int turn_counter(int*);
void print_board(int **[ROWS][COLS]);


int main(){
	int **board[ROWS][COLS];
	int turn;
	initialize_board(board);
	turn=get_turn(); 
	//change_board(board, turn);
	print_board(board);
return 0;
}

//Functions

/****************************************************
 * Function: initialze_board
 * Description: Prints the board in defualt state
 * Return: Prints the board in defualt state
*****************************************************/
void initialize_board(int **board[ROWS][COLS])
{
	for (int k = 0; k<ROWS; k++){
		for(int i=0; i<COLS; i++){
			board[k][i]=0;
			cout << board[k][i];
		}
		cout <<endl;
	}

}

/***********************************************************************
 * Function: get_turn
 * Description:gets the column the player wants to put the piece in.
 * Return: The Column number.
***********************************************************************/
int get_turn()
{
	int num;
	bool check = false;
	while(check == false){
		cout << "What column do you want to place your tile on? ";
		cin >> num;
		check=input_checker(num);
	}
	return num; 	
}

/*************************************************************
 * Function:input_checker
 * Description: checks if the input from the user is good. 
 * Return: A true or false value.
*************************************************************/
bool input_checker(int input)
{
		if((input-1==0)||(input-1==1)||(input-1==2)||(input-1==3)||(input-1==4)||(input-1==5)||(input-1==6)||(input-1==7)){
			return true;
		}	
		else{
			cout << "Bad Input, try again." << endl;
			return false; 
		}
}
/*******************************************************************
 * Function: change_board
 * Description: changes the board based on the input of the player.
 * Return: board positions.
*******************************************************************/
void change_board(int **board[ROWS][COLS], int col)
{
	//create a counter for each column starting at 6 and couting down
	//one each time a column is picked. Based on the turn place a 1 or
	//a 2 in the column that was selected, if the column reaches 0, and
	//gets picked again output a error.
}	

/***************************************************************************
 * Function: turn_counter
 * Decription:increments a counter each turn to output the correct message
 * 	      to indicate whos turn it is.
 * Return: returns a value.
***************************************************************************/		
int turn_counter(int *turncounter)
{	
	if(*turncounter == 0){
		cout <<"Player 1"<<endl;
	}
	else if(*turncounter == 1){
		cout <<"Player 2" <<endl;
	}
	else if(*turncounter%2==0){
		cout <<"Player 1" <<endl;
	}
	else if(*turncounter%2!=0){
		cout <<"Player 2" <<endl;
	}
	*turncounter++;
}
		
/*****************************************************************
 * Function: print_board
 * Description: Prints the modified board.
 * Return: prints the board.
*****************************************************************/
void print_board(int **board[ROWS][COLS])
{
	for (int k = 0; k<ROWS; k++){
		for(int i=0; i<COLS; i++){
			cout << board[k][i];
		}
		cout <<endl;
	}
}
			
