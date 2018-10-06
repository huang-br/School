#ifndef STACK_H
#define STACK_H

#include <iostream>

class stack
{
	private:
		char data;
		int n;
	public:
		//Defualt Constructor
		stack();
		void add(char Value);
		char remove();
};

#endif
