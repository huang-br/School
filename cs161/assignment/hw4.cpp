#include<iostream>
#include<string>
#include<cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

void get_word(string &);
string lines(string&);
int checker(string, string &, string);
void guessmessage(string, string &);
void message(string &, int &, string &); 
void get_guess(string &, string, int &, string &, int &, string &);


void get_word(string &word)
{
	cout << "What is your word? " ;
	getline(cin, word);
	system("clear");
}
	
string lines(string &l)
{
	for(int k = 0; k < l.length(); k++){
		if(l.at(k) != ' '){
			l.at(k) = '_';
}
}
	return l;
}

int checker(string word, string&l, string guess)
{
	int find = 0;
	for(int k = 0; k < word.length(); k++){
		if(word.at(k) == guess.at(0)){
			l.at(k) = guess.at(0);
			find ++;
}
}
	return find;
}

void guessmessage(string word, string &l)
{
	string guess;
	string guessed;
	int find=0;
	get_guess(guess, word, find, guessed, l);
	if(word = l){
		cout << "You win." <<endl;
}
}

void message(string &guess, int &find, string &guessed)
{
	if(find > 0){
		cout << "There are " << find << " " << guess << endl;
}
	else{
		cout << "There is no " << guess << endl;
}
}

void get_guess(string &guess, string word, int &find, string &guessed, int &wrong, string &l)
{
	cout << l << endl;
	cout << "Guess a letter: " ;
	cin >> guess;
	find = checker(word, l, guess);
	guessed = guess;
	message(guess, find, guessed);
}

	
int main(){
	//Strings
	string word,guess,l;
	get_word(word);
	
	l=word;
	
	lines(l);
	guessmessage(word, l);
	cout << "The message is: " << word << endl;

return 0;
}


