/********************************************************
 * Brian Huang
 * 3/14/2016
 * Maze Project
*******************************************************/


#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Floor.h"
#include "Actor.h"
#include "Player.h"
#include "Swan.h"
#include "Game.h"

using namespace std;

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout << "Not enough arguments" << endl;
	}
	else
	{
		srand(time(NULL));
		int floorNum = atoi(argv[1]);
		Game project;
		for(int k = 0; k < atoi(argv[1]); ++k)
		{
			project.play(floorNum);
			floorNum--;
		}
		cout << "You have escaped!" << endl;	
	}
		


return 0;
}
