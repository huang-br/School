#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
#include <string>

class Actor
{
	public:
		//Virtual Functions
		virtual bool action(char**) = 0;
		
	protected:
		int startX;
		int startY;
		int nextX;
		int nextY;
		int prevX;
		int prevY;
};

#endif
