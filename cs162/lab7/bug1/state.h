/*
 * state.h
 *
 *  Created on: Apr 25, 2014
 *      Author: eecs162
 */

#ifndef STATE_H_
#define STATE_H_

#include<string>

using namespace std; 

class state {
private:
	char *name;
	int pop;
	string fixedName;
public:
	void set_name(char []);
	void setName();
	void display_pop();
	void set_pop(int);
	state();
	virtual ~state();
};

#endif /* STATE_H_ */
