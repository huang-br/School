#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int countways(int num){
	if(num == 0)
		return 0;
	else if(num ==1)
		return 1;
	else if(num > 1)
		return (countways(num-1) + countways(num-2));
}
int main(){
	int n;
	cout << "How many number of stairs? ";
	cin >> n;

	cout << "There are " << countways(n-1) << " possible combonations." << endl;
return 0;
}
	
