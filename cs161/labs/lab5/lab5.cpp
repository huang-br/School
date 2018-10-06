#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

void get_sentence(string &s){
	cout <<"enter a string: ";
	getline(cin,s);
}

void get_search_replace_strings(string &search, string &replace){
	cout<<"enter a search string: ";
	getline(cin,search);
	cout<<"enter a replace string: ";
	getline(cin,replace);
}

bool determine_palindrome(string s){
	for(int k=0; k <= s.length(); ++k){
		if(s.at(k) == s.at(s.length() - k)){
			return 1;
}
			return 0;
}
} 
int search_replace(string &s, string &search, string &replace){
	s.replace(s.find(search), search.length(), replace);
	cout << s << endl;
	return 0;
}

int main (){
	//strings
	string s;
	string replace;
	string search;
	//bool check;

	//running the functions
	get_sentence(s);

/*	check = determine_palindrome(s);
		if(check == 1){
			cout << "This is a palindrome." << endl;
}
		else if(check == 0){
			cout << "this is not a palindrome." <<endl;
} */

	get_search_replace_strings(search,replace);
 	search_replace(s, search, replace);
	return 0;
}

