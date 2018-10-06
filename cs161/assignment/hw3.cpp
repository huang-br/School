/**********************************************************************************
   Program: my_math.cpp
   Author: Brian Huang
   Date: 10/25/15
   Description: Finds the sum of a function from a to b, and finds the area of the
   function using two different types of riemann sums.
 
   Input:-Mathmatical operation to perform
  	 -Starting and ending points. 
  	 -Funtion to calculate.
  	 -Area under the function.
  	 -Number of rectangles.
 
   Output:-The Function being evaluated.
  	  -Starting and ending points for the riemann sum.
  	  -For the integration, the number of rectangles/trapezoids.
  	  -Area under the curve.
 **********************************************************************************/

#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>

using namespace std; 

/***********************************************************************************
   Function: Function Select
   Description: Chooses a function based on the value given.
   Parameters: func is the value that chooses the function, and value is the value
               of the function when it is evaluated at that number
   Pre-Conditions: N/A
   Post-Conditions: A number
   Return: A number based on the equation.
************************************************************************************/
int function(int func, int value){
	int select = func;
	int num;
	int x = value;
	if(select == 1)
		num = 2*(pow(x,5)) + pow(x,3) - 10*x + 2;
	else if(select == 2)
		num = 6*(pow(x,2)) - x + 10;
	else if(select == 3) 
		num = 5*x + 3;
	else if(select == 4)
		num = x*(pow(x,3)) + 120;
	else if(select == 5) 
		num = 2 * (pow(x,2));
	return num;
}

/***************************************************************************************
   Function: summation
   Description: Sums of the function between the bounds given.
   Parameters: It takes in 3 values, 2 of them are the bounds and the third is used for 
               selecting the function.
   Pre-Conditions: N/A
   Post-Conditions: A value.
   Return: A value based on the equation.
***************************************************************************************/
int summation(int lower, int upper, int func){
	int sum = 0;
	for(int i = lower; i <= upper; ++i){
		int num;
		int select = func;
		num = function(select, i);
		sum = num + sum;
		if(i == upper)
			cout <<"The sum from " << lower << " to " << upper << " is " << sum << endl;
	}
	return 0;
}


/******************************************************************************************
   Function: rec
   Description: Riemann sums using rectangles.
   Parameters: It takes 3 floats and 1 int. 2 floats are used as bounds and the third is
               used as the number of rectangles. The int value chooses the function.
   Pre-Conditions: N/A
   Post-Conditions: A value.
   Return: A value based on the equations and the riemann sum.
******************************************************************************************/
int rec(float lower, float upper, float n, int func){
	float h;
	float w;
	float area;
	for(int k = lower ; k <= n; ++k){
		w = (upper - lower)/n ;
		h =  function(func, lower + w*k);
		area = (w*h) + area;
		if(k == n){
			cout << "The area from " << lower << " to " << upper << " is " << area << endl;
		}
	}
	return 0;
}
/******************************************************************************************
   Function: trap
   Description: Riemann sums using trapezoids.
   Parameters: Takes 3 float values and 1 int. 2 floats are used as bounds and the third is
	       used as the number of trapezoids. The int value chooses the function.
   Pre-Conditions: N/A
   Post-Conditions: A value.
   Return: A value based on the equations and the riemann sum.
******************************************************************************************/
int trap(float lower, float upper, float n, int func){
	float h;
	float w;
	float area;
	for (int k = lower; k <= n; ++k){
		w = ((upper - lower)/n);
		h = ((function(func, (k*w)+1) + function(func, (k*w)+2))/2);
		area = ((w*h) + area);
		if(k == n){
			cout << "The area from " << lower << " to " << upper << " is " << area << endl;
		}
	}
	return 0;
}

/******************************************************************************************
    Function: riemann
    Description: Chooses the method of riemann sum.
    Parameters: Takes in the bounds and a int value to choose the function.
    Pre-Conditions:N/A
    Post-Conditions: The value of the rectangular riemann sum or the trapezoid riemann sum
                     or both.
    Return: Nothing.
******************************************************************************************/
int riemann(int lower, int upper, int func){
	int choice;
	float n;
	float value;
	cout << "1. Rectangles" << endl;
	cout << "2. Trapezoids" << endl;
	cout << "3. Both" << endl;
	cout << "Choose one by entering the corresponding number: " ;
	cin >> choice;

	cout << "Number of rectangles/trapezoids: " ;
	cin >> n;

	if(choice == 1)
		value = rec(lower, upper, n, func);
	else if(choice == 2)
		value = trap(lower, upper, n, func);
	else if (choice ==3){
		value = rec(lower, upper, n, func);
		value = trap(lower,upper, n, func);
		return 0;
	}
}
int main (){

	//Creating the variables.
	int upper;
	int lower;
	int value;
	int select;
	int operation;
	bool cont=true;

	while(cont == true){

		//Taking the selection.
		cout << "1. 2x^5 + x^3 - 10x + 2 " << endl;
		cout << "2. 6x^2 - x + 10" << endl;
		cout << "3. 5x + 3" << endl;
		cout << "4. 2x^3 + 120" << endl;
		cout << "5. 2x^2" << endl;

		cout << "Choose a function by entering the coresponding number: " ;
		cin >> select;

		//Taking in the bounds.
		cout << "Enter a lower bound: " ; 
		cin >> lower;

		cout << "Enter a upper bound: ";
		cin >> upper;

		//Taking the choice
		cout << "Sum or Integrate? (1 for Sum 2 for Integrate)" ;
		cin >> operation;

		if(operation == 1)
			value = summation(lower, upper, select);
		else if(operation == 2)
			value = riemann(lower, upper, select);

		cout << "Do you want to continue? (1 for yes 0 for no)" ;
		cin >> cont;
	}
	return 0; 
}
