#include <iostream>

using namespace std;

struct Node
{
	Node* next;
	char value;
};

//Functions
void add(char c, Node *&n, Node *&temp, Node *&head);
char remove(Node *&n, Node *&temp, Node *&head);

int main(){
	Node *n;
	Node *temp;
	Node *head = NULL;
	char c;
	char display;
	for(int k = 0; k < 5; ++k)
	{
		cout << "Input a char: ";
		cin >> c;
		add(c, n, temp, head);	
	}
	
	for(int j = 0; j < 5; ++j)
	{
		display = remove(n, temp, head);
		cout << display << endl;
	}
	
return 0;
}

void add(char c, Node *&n, Node *&temp, Node *&head)
{
	n = new Node;
	n -> value = c;
	temp = n;
	head = n;

	temp->next = n;
	temp = temp->next;
}

char remove(Node *&n, Node *&temp, Node *&head)
{
	char val;
	val = n -> value;
	temp = n;
	delete n;

	return val;
}
	
/*void add(char c)
{
	Node* posn;
	Node* temp = new Node;
	temp -> next = posn -> next;
	posn -> next = temp;
	temp -> value = c;
}*/
