#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>

using std::cout;
using std::endl;
using namespace std;

int main() {
	int x;
	int counter;
	string input;
	int num;
	srand(time(NULL));

	x = rand() %50;

	//Establishing the loop.
	counter = 1;
	while(counter <= 5){
		cout<< "Guess the number: " ;
		cin >> input;
		
		//Handling inputs bigger than 2
		if(input.size() > 2)
			cout << "Bad input. Try again." << endl;

		else if(input.size()==1){
			if(!((input.at(0)>= '0' && input.at(0) <= '9')))
			cout<<"Bad input. Try again." << endl;
}			
		else if(input.size()==2){
			if(!(input.at(0) >='0' &&  input.at(0) <='4' && input.at(1) >= '0' && input.at(1) <= '9'))
			cout<< "Bad input. Try again." << endl;
}
		num=atoi(input.c_str());
			
		if(num < x ){
			cout << "Your number is too low, guess again. " << endl;
			counter++;
		}
		else if(num > x){
			cout << "Your number is too high, guess again. " <<endl;
			counter++;
		}
		else if(num == x){
			cout << "Your number is correct." ;
			break;
		}
	}
	if(counter == 6)
		cout <<"You are out of guesses." << endl;
}



	
