#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<string>
#include"Item.h"

using namespace std;

class list{

private:
	Item *x;
	int size;
public:
	void additem(Item*);
};

#endif
