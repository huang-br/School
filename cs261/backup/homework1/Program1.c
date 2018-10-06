/* CS261- HW1 - Program1.c */
/* Name:Brian Huang
 * Date:4/8/2016
 * Solution description: uses various print statemtns to print the address and
 * 			 the value of the data.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value of iptr*/
     printf("The Value of iptr is: %d\n", *iptr); 
     /*Print the address pointed to by iptr*/
     printf("The adress pointed to by iptr is: %d\n",iptr);
     /*Print the address of iptr itself*/
     printf("The addres of iptr is: %d\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 1;
    /*print the address of x*/
    printf("The address of x is: %d\n",&x);
    /*Call fooA() with the address of x*/
    fooA(&x); 
    /*print the value of x*/
    printf("The vaule of x is: %d\n",x);
    return 0;
}
