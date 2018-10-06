/******************************************************************************
 * Program Filename: hw4_part2
 * Author: Brian Huang
 * Date 11/11/15
 * Description: Prints out a fractal
 * Input: The user inputs a power of 2.
 * Output: The program outputs a fractal.
******************************************************************************/

#include <iostream> 

using std::cout;
using std::cin;
using std::endl;

//Function Prototypes
void fractal(int, int);

int main(){
	
	int n;
	cout << "Enter a number that is a power of two: ";
	cin >> n;
	fractal(n,0); 

	return 0;
}

/*****************************************************************************
 * Function: fractal
 * Description: creates the fractal pattern.
 * Parameters: A power of n and 0.
 * Return: The Correct number of *
*****************************************************************************/

void fractal(int n, int x)
{
	if(n > 0){
		fractal(n/2, x);
		for(int k = 1; k <= x; k++)
			cout << " ";
		for(int k= 1; k <=n; k++)
			cout << "* ";
		cout << endl;
		fractal(n/2, x+n);
}
}
