#include <iostream>
#include <string>

using namespace std;
/**************************************************************
 * Decription: Checks for prime numbers.
 * Precondition: Nothing
 * PostConditions:either a 1 or 0
 * return 1 or 0
**************************************************************/
bool primechecker(int num){
	for(int i = 2 ; i <= num  ; ++i){
		if(num%i == 0)
			return 1;
		else;
			return 0;
	}
}
/**************************************************************
 * Description :Loops the prime number checker.
 * Precondition: Nothing
 * PostCondition: outputs the list of numbers.
 * Returns a list of numbers.
**************************************************************/
int looper(int upper){;
	for(int k = 3; k <= upper; ++k){
		bool check = primechecker(k);
		if(check == 1)
			cout << " " << k;
}
	return 0;	

}
int main () {

	int num; 
	int prime;
	cout <<"Enter a number thats greater than 3: " ;
	cin >> num;

	prime = looper(num);

	return 0;
}
