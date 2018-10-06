#ifndef STACK_H
#define STACK_H

#include <iostream> 
#include "Creature.h"
#include "Stacknode.h"

class Stack 
{
	public:
		//Defualt Constructor
		Stack();
		//Destructor
		~Stack();
		//Functions
		void add(Creature*, int);
		Creature* remove();
	protected:
		Stacknode *head;

};

#endif
