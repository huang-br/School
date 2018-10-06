#include <iostream>
#include <string>

using namespace std;

int main () {
   int i; //loop counter
   int num; 
   int prime;

   cout <<"Enter a number thats greater than 3: " ;
   cin >> num;
   prime = 0;

      for(i = 2 ; i <= num/2  ; ++i){
	if(num%i == 0){
	   prime=1;
	   break;
	}
      }      
      if(prime == 0){
	cout << "The number is prime." << endl;
      }
      else if(prime == 1){
	cout << "The number is not prime." << endl;
      }
      
      return 0;
}
