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
#include "Stack.h"
#include "Queue.h"
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
void tournament(Queue*, Queue*, int);

int main(){
	srand(time(0));
	int choice,size;
	Creature *fighter;
	Queue *team1;
	Queue *team2;
	
	cout << "What is the team size? " ;
	cin >> size;
	cout << endl;
	
	team1 = new Queue();
	team2 = new Queue();
	
	cout << "Team 1 make your team." << endl;
	for(int k = 0; k < size; ++k)
	{
		cout <<"Select a fighter type" << endl;
		choice = select(fighter);
		team1 -> add(fighter, choice, k+1);
	}
	cout << endl; 
	
	cout << "Team 2 make your team." << endl;
	for(int k = 0; k < size; ++k)
	{
	
		cout <<"Select a fighter type" << endl;
		choice = select(fighter);
		team2 -> add(fighter, choice, k+1);
	}
	
	tournament(team1, team2, size);
	
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

void tournament(Queue *team1, Queue *team2, int size)
{
	Creature *fighter1;
	Creature *fighter2;
	int type1;
	int type2;
	int damage;
	int defVal;
	for(int k = 0; k < size; ++k)
	{
		//Getting the fighter information
		type1 = team1 -> head -> type;
		type2 = team2 -> head -> type;
		fighter1 = team1 -> head -> fighter;
		fighter2 = team2 -> head -> fighter;
		int index1 = team1 -> head -> index;
		int index2 = team2 -> head -> index;
		int strength1 = fighter1 -> getStrength();
		int strength2 = fighter2 -> getStrength();
		string name1 = fighter1 -> getName();
		string name2 = fighter2 -> getName();

		while(strength1 > 0 && strength2 > 0)
		{
			defVal = fighter2 -> defend();	
			damage = fighter1 -> attack(type2, defVal);
			strength2 = fighter2 -> takeDamage(damage);
			cout << name1 << index1 << " has done " << damage << " points of damage to " << name2 << index2 << "!" << endl;
			cout << name2  << index2 << " has " << strength2 << " health left!" << endl;
			cout << endl;

			if(strength2 <= 0)
			{
				cout << "Fighter 1 Wins! " << endl;
				break;
			}
		
			defVal = fighter1 -> defend();
			damage = fighter2 -> attack(type1, defVal);
			strength1 = fighter1 -> takeDamage(damage);
			cout << name2 << index2 << " has done " << damage << " points of damage to " << name1 << index1 << "!" << endl;
			cout << name1 << index1 <<  " has " << strength1 << " health left!" << endl;
			cout << endl;
	
			if(strength1 <= 0)
			{
				cout << "Fighter 2 Wins! " << endl;
				break; 
			}

		}	
	}
		

}


