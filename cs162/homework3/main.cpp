/**************************************************************************************************
 * Program: Homework3
 * Author: Brian Huang
 * Date 2/12/16
**************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Creature.h"
#include "Gollum.h"
#include "Barbarian.h"
#include "Babayaga.h"
#include "Bluemen.h"
#include "Unicorn.h"

using namespace std;

//Functions
int menu();
void fight(Creature*, int, Creature*, int);
int select(Creature*&);
void clean(Creature*&, Creature*&);

int main(){
	srand(time(0));
	int choice1, choice2;
	Creature *fighter1;
	Creature *fighter2;

	cout << "Select The First Fighter" << endl;
	choice1 = select(fighter1);
	
	cout << "Select The Second Fighter" << endl;
	choice2 = select(fighter2);
	
	fight(fighter1, choice1, fighter2, choice2);
	clean(fighter1, fighter2);
return 0;
}

/*******************************************************************
 Function: menu
 Description: Makes a menu to select a fighter.
*******************************************************************/
int menu()
{
	int choice;
	
	cout << "1. Gollum" << endl << "2. Barbarian" << endl << "3. Baba Yaga" << endl << "4. Blue Men" << endl << "5. Unicorn" << endl;
	cin >> choice;

	return choice;
}

/*********************************************************************
 Function: fight
 Description: Calls the two fighters attack and defend functions.
              The first fighter always attacks first, then the 
	      second fighter's defend function is called.
*********************************************************************/
void fight(Creature *fighter1, int CreatureType1, Creature *fighter2, int CreatureType2)
{
	int damage;
	int defVal;
	int strength1 = fighter1 -> getStrength();
	int strength2 = fighter2 -> getStrength();
	string name1 = fighter1 -> getName();
	string name2 = fighter2 -> getName();

	while(strength1 > 0 && strength2 > 0)
	{
		defVal = fighter2 -> defend();	
		damage = fighter1 -> attack(CreatureType2, defVal);
		strength2 = fighter2 -> takeDamage(damage);
		cout << name1 << " has done " << damage << " points of damage to " << name2 << "!" << endl;
		cout << name2 << " has " << strength2 << " health left!" << endl;
		cout << endl;
		
		defVal = fighter1 -> defend();
		damage = fighter2 -> attack(CreatureType1, defVal);
		strength1 = fighter1 -> takeDamage(damage);
		cout << name2 << " has done " << damage << " points of damage to " << name1 << "!" << endl;
		cout << name1 << " has " << strength1 << " health left!" << endl;
		cout << endl;
	
		if(strength1 <= 0)
		{
			cout << "Fighter 2 Wins! " << endl;
		}
		else if(strength2 <= 0)
		{
			cout << "Fighter 1 Wins! " << endl;
		}

	}	
}

/********************************************************************
 Function: Select
 Description: Selects and creates the fighters
*********************************************************************/
int select(Creature *&fighter)
{
	int choice = menu();
	if(choice == 1)
	{
		fighter = new Gollum;
	}

	else if(choice == 2)
	{
		fighter = new Barbarian;
	}

	else if(choice == 3)
	{
		fighter = new Babayaga;
	}

	else if(choice == 4)
	{
		fighter = new Babayaga;
	}

	else if(choice == 5)
	{
		fighter = new Unicorn;
	}
	
	return choice;
}

/*****************************************************************
 Function: Clean
 Description: deletes the fighters.
****************************************************************/
void clean(Creature *&fighter1, Creature *&fighter2)
{
	delete fighter1;
	delete fighter2;
}
