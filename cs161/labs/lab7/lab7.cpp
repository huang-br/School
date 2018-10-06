#include <iostream>
#include <string>

using namespace std;

void get_sentence(char s[]){
	cout << "enter a sentence: ";
	cin >> s; 
}

void create_sentence(char *r[]){
	int num;
	cout << "How many characters are in your word? ";
	cin >> num;
	*r = new char [num+1];
}

int main(){
	char sentence[20];
	char *sentence2;

	get_sentence(sentence);	
	cout << sentence << endl;
	
	create_sentence(&sentence2);
	get_sentence(sentence2);
	cout << sentence2 << endl;

	return 0;
}
