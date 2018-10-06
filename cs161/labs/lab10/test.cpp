#include <iostream>

using namespace std;

int main(){
	int *test_array, number; 
	cout << "What size? ";
	cin >> number;
	test_array = new int[number];

	for(int i=0; i<number; ++i){
		cout << "what is in slot " << i << " ? "; 
		cin >> test_array[i];
}
	cout << endl;

	for(int k=0; k<number; ++k){
		cout << test_array[k] << " ";
}

return 0;
}
