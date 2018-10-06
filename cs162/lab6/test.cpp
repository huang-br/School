#include <iostream>

using namespace std;

struct node
{
	char c;;
	node *next;
};

int main(){
	node *root;
	node *temp;

	root = new node;
	root -> next = 0;
	root -> c = 'a';
	temp = root;
	if( temp !=0 )
	{
		while( temp -> next !=0 ) 
		{
			temp = temp -> next; 
		}
	}

	temp -> next = new node;
	temp = temp -> next;
	temp -> next = 0;
	temp -> c = 'b';
	
return 0;
}
