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
int select(Creature*&);
void clean(Creature*&, Creature*&);
void tournament(Queue*, Queue*);

int main(){
	srand(time(0));
	int choice,size;
	string again;
	bool cont = true;
	Creature *fighter;
	Queue *team1;
	Queue *team2;
	
	while(cont == true)
	{
		cout << "What is the team size? " ;
		cin >> size;
		cout << endl;
	
		team1 = new Queue();
		team2 = new Queue();
	
		cout << "Team 1 make your team." << endl;
		int oddTeamCounter = 1;
		for(int k = 0; k < size; ++k)
		{
			cout <<"Select a fighter type" << endl;
			choice = select(fighter);
			team1 -> add(fighter, choice, oddTeamCounter);
			oddTeamCounter += 2;
		}	
		cout << endl; 
	
		int evenTeamCounter = 2;
		cout << "Team 2 make your team." << endl;
		for(int k = 0; k < size; ++k)
		{
		
			cout <<"Select a fighter type" << endl;
			choice = select(fighter);
			team2 -> add(fighter, choice, evenTeamCounter);
			evenTeamCounter += 2;
		}
		
		tournament(team1, team2);
		cout <<"Would you like to play again? (yes or no) ";
		cin >> again;
		if(again == "yes")
		{
			cont = true;
		}
		else if(again == "no")
		{
			cont = false;
		}
	}
	
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
		fighter = new Bluemen;
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

/****************************************************************************
 Function: tournament
 Description: Has the two teams of creatures from two teams fight till a teams
	      players have all lost.
*****************************************************************************/
void tournament(Queue *team1, Queue *team2)
{
	Stack *losers = new Stack();
	Creature *fighter1;
	Creature *fighter2;
	Queuenode *storeFighter;
	int type1;
	int type2;
	int damage;
	int defVal;
	string cont;
	while((team1 -> head != NULL) && (team2 -> head != NULL))
	{
		//Getting the fighter information
		bool fighter1Dead = false;
		bool fighter2Dead = false;
		fighter1 = team1 -> head -> fighter;
		fighter2 = team2 -> head -> fighter;
		type1 = team1 -> head -> type;
		type2 = team2 -> head -> type;
		int index1 = team1 -> head -> index;
		int index2 = team2 -> head -> index;
		int strength1 = fighter1 -> getStrength();
		int strength2 = fighter2 -> getStrength();
		string name1 = fighter1 -> getName();
		string name2 = fighter2 -> getName();
	
		//Fighting
		while(fighter1Dead == false && fighter2Dead == false)
		{
			defVal = fighter2 -> defend();	
			damage = fighter1 -> attack(type2, defVal);
			strength2 = fighter2 -> takeDamage(damage);
			cout << name1 << index1 << " has done " << damage << " points of damage to " << name2 << index2 << "!" << endl;
			cout << name2  << index2 << " has " << strength2 << " health left!" << endl;
			cout << endl;
			if(strength2 == 0)
			{
				cout << "Fighter 1 Wins!" << endl;
				cout << endl;
				fighter1 -> heal();
				team1 -> add(fighter1, type1, index1);
				team1 -> remove();
				losers -> add(team2 -> remove(), index2);
				fighter2Dead = true;
				break;
			}

			defVal = fighter1 -> defend();
			damage = fighter2 -> attack(type1, defVal);
			strength1 = fighter1 -> takeDamage(damage);
			cout << name2 << index2 << " has done " << damage << " points of damage to " << name1 << index1 << "!" << endl;
			cout << name1 << index1 <<  " has " << strength1 << " health left!" << endl;
			cout << endl;
			if(strength1 == 0)
			{
				cout << "Fighter 2 Wins!" << endl;
				cout << endl;
				fighter2 -> heal();
				team2 -> add(fighter2, type2, index2);
				team2 -> remove();
				losers -> add(team1 -> remove(), index1);
				fighter1Dead = true;
				break;
			}
	
		}
		
		//Team win check
		if(team2 -> head == NULL)
		{
			if(team1 -> head != NULL)
			{
				losers -> add(team1 -> remove(), index1);
				
				fighter1 = team1 -> head -> fighter;
				type1 = team1 -> head -> type;
				int index1 = team1 -> head -> index;
				int strength1 = fighter1 -> getStrength();
				string name1 = fighter1 -> getName();
				
			}
			cout << "TEAM 1 WINS" << endl;
		}
		else if(team1 -> head == NULL)
		{
			if(team2 -> head != NULL)
			{
				losers -> add(team2 -> remove(), index2);
				
				fighter2 = team2 -> head -> fighter;
				type2 = team2 -> head -> type;
				int index2 = team1 -> head -> index;
				int strength2 = fighter2 -> getStrength();
				string name2 = fighter2 -> getName();
			}
			cout << "TEAM 2 WINS" << endl;
		}
		else
		{
			cout << "Go to next round? (yes or no) ";
			cin >> cont;
			cout << endl;

			if(cont == "no")
			{
				exit(0);
			}
		}
	}
	cout << "Placement" << endl;
	for(int m=0; m < 3; ++m)
	{
		int place = m+1;
		cout << place << '.';
	}
}
		