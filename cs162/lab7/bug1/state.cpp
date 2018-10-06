/*
 * state.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: eecs162
 */
#include <iostream>
#include <cstring>
#include <string>
#include "state.h"

using namespace std;

void state::setName()
{
	fixedName = "Oregon"; 
}

void state::set_name(char n[]) {
	strcpy(name, n);
}

void state::set_pop(int n){
    this->pop=n;
}

#ifdef DEBUG
void state::display_pop() {
	cout << "state, " << fixedName << ", pop: " << pop << endl;
}
#else
void state::display_pop() {
	cout << "state, " << name << ", pop: " << pop << endl;
}
#endif

state::state() {
	pop=0;
	name=NULL;
}

state::~state() {

}

