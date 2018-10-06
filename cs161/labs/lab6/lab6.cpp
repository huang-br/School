#include <sys/time.h>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int fib_iter(int n){
	int zeroth = 0;
	int first = 1;
	int next = zeroth + first;
	for(int k = 0; k < n-1; k++){
		next = zeroth + first;
		zeroth = first;
		first = next;
}
	return next;
}

int fib_recurs(int n){
	if(n==0) 
		return 0;
	else if(n==1) 
		return 1;
	else if(n > 1)
		return (fib_recurs(n-1) + fib_recurs(n-2));
}
	


		
	
		
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout << "Need another argument." << endl;
	}
	else
	{

		int n;
		int choice = atoi(argv[1]);
		cout << "Which term of the sequence? " ;
		cin >> n;

		typedef struct timeval time;
		time stop, start;

		gettimeofday(&start, NULL);
		
		if(choice == 1)
		{	
			cout << "The fibonacci number by iter is: " << fib_iter(n) << endl;
		}
		else if(choice == 2)
		{
			cout << "The fibonacci number by recurs is: " << fib_recurs(n) << endl;
		}
		gettimeofday(&stop, NULL);

		if(stop.tv_sec > start.tv_sec)
			cout << "Seconds: " << stop.tv_sec-start.tv_sec << endl;
		else
			cout << "Micro: " << stop.tv_usec-start.tv_usec << endl;
		return 0;
	}
}
//1st number: 1 micro
//5th number: 30 micro
//15th number: 55 micro
//25th number: 3321 micro
//45th number: 32 seconds
