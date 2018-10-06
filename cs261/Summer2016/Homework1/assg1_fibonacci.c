#include "assg1_fibonacci.h"
/*For a given n, returns the nth fibonacci number. For full credit this
 * function must NOT make ANY function calls and compute the solution
 * iteratively. For more info see the README.*/
unsigned long iterative_fibonacci(int n) {
	/*TODO: YOUR CODE GOES HERE!*/
	int k;
	int zeroth = 0;
	int first = 1;
	int next = zeroth + first;
	for(k = 0; k < n-1; k++)
	{
		next = zeroth + first;
		zeroth = first;
		first = next;
	}
	return next;
}

/*For a given n, returns the nth fibonacci number. For full credit this
 * function must NOT make ANY function calls except to itself and compute
 * the solution recursively. For more info see the README.*/
unsigned long recursive_fibonacci(int n) {
	/*TODO: YOUR CODE GOES HERE!*/
	if(n==0)
	{
		return 0;
	} 
	else if(n==1)
	{
		return 1;
	} 
	else if(n > 1)
	{
		return (recursive_fibonacci(n-1) + recursive_fibonacci(n-2));
	}
	else
	{
		return 0;
	}

}

/* The Big-O complexity of the iterative version is O(n). It is O(n) because there is only one for loop the program only needs to loop through n elements.
 * The Big-O complexity of the recursive version is O(n^2). It is O(n^2) because for larger numbers the third else if statement is used, so it splits the number into smaller operations,
 * which then splits into even smaller operations. */