#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
#include <string>

class Actor
{
	public:
		//Virtual Functions
		virtual void action(char**) = 0;
		
	protected:
		int nextX;
		int nextY;
		int prevX;
		int prevY;
};

#endif
