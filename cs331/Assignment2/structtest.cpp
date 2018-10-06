#include <iostream>
#include <vector>


struct move
{
	int x;
	int y;
};

int main()
{
	move newMove;
	newMove.x = 10;
	newMove.y = 20;

	std::vector<move> moveList;
	std::cout << newMove.x << std::endl;
	std::cout << newMove.y << std::endl;

	for(int i=0; i < 10; i++)
	{
		move testMove;
		testMove.x = i;
		testMove.y = i + 2;
		moveList.push_back(testMove);
	}

	for(int j=0; j< 10; j++)
	{
		std::cout << moveList[j].x << ' ' << moveList[j].y << std::endl;
	}

	
	return 0;

}
