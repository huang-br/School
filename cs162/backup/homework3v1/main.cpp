/**************************************************************************************************
 * Program: Homework3
 * Author: Brian Huang
 * Date 2/12/16
**************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
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
bool handleInput(int);

int main(){
	srand(time(0));
	int choice1, choice2;
	Creature *fighter1;
	Creature *fighter2;

	cout << "Select The First Fighter" << endl;
	choice1 = menu();
	
	if(choice1 == 1)
	{
		Gollum g1;
		fighter1 = &g1;
	}

	else if(choice1 == 2)
	{
		Barbarian b1;
		fighter1 = &b1;
	}

	else if(choice1 == 3)
	{
		Babayaga by1;
		fighter1 = &by1;
	}

	else if(choice1 == 4)
	{
		Bluemen bm1;
		fighter1 = &bm1;
	}

	else if(choice1 == 5)
	{
		Unicorn u1;
		fighter1 = &u1;
	}

	cout << "Select The Second Fighter" << endl;
	choice2 = menu();
	
	if(choice2 == 1)
	{
		Gollum g2;
		fighter2 = &g2;
	}

	else if(choice2 == 2)
	{
		Barbarian b2;
		fighter2 = &b2;
	}

	else if(choice2 == 3)
	{
		Babayaga by2;
		fighter2 = &by2;
	}

	else if(choice2 == 4)
	{
		Bluemen bm2;
		fighter2 = &bm2;
	}
	
	else if(choice2 == 5)
	{
		Unicorn u2;
		fighter2 = &u2;
	}

	fight(fighter1, choice1, fighter2, choice2);
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
	int atkVal;
	int damage;
	int strength1 = fighter1 -> getStrength();
	int strength2 = fighter2 -> getStrength();
	while(strength1 > 0 && strength2 > 0)
	{	
		atkVal = fighter1 -> attack(CreatureType2);
		damage = fighter2 -> defend(atkVal);
		cout << "Fighter 1 has done " << damage << " points of damage to Fighter 2!" << endl;
		strength2 = fighter2 -> getStrength();
		cout << "Fighter 2 has " << strength2 << " health left!" << endl;
		cout << endl;
		
		atkVal = fighter2 -> attack(CreatureType1);
		damage = fighter1 -> defend(atkVal);
		cout << "Fighter 2 has done " << damage << " points of damage to Fighter 1!" << endl;
		strength1 = fighter1 -> getStrength();
		cout << "Fighter 1 has " << strength1 << " health left!" << endl;
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
