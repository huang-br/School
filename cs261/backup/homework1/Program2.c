/* CS261- HW1 - Program2.c*/
/* Name:Brian Huang
 * Date:4/8/2016
 * Solution description: Created a function which increments and decrements values passed into it and subtracts them.
 * 			 The function returns this value. Main prints all these values.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /* Increment a */
    ++*a;
    /* Decrement  b */
    --*b;
    /* Assign a-b to c */
    c = *a-*b;
    /* Return c */
    return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
	int x = 5;
	int y = 6;
	int z = 7;
	int newVal;
    /* Print the values of x, y and z */
	printf("The value of x is: %d\nThe value of y is: %d\nThe value of z is: %d\n",x,y,z);
    /* Call foo() appropriately, passing x,y,z as parameters */
   	newVal = foo(&x,&y,z); 
    /* Print the values of x, y and z */	
	printf("After calling foo once the new values are\nThe value of x is: %d\nThe value of y is: %d\nThe value of z is: %d\n",x,y,z);
    /* Print the value returned by foo */
	printf("The new value returned by foo is: %d\n", newVal); 
    /* Is the return value different than the value of z?  Why? */
	/*The value is different because the value of z is not modified in anyway.
	The function does pass z by reference so the value of z remains
	unmodified. The return value is also the difference between a and b, so
	the value would not be the same anyway.*/
    return 0;
}
    
    
