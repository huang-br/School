/***********************************************************************
 * Author: Brian Huang
 * Date 7/3/2016
 * Description: Reads in numbers from a file and adds them together.
 * 		it then outputs the sum of those numbers.
************************************************************************/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line;
	string filename;
	int sum = 0;
	int num = 0;

	cout << "What is the file name: " ;
	cin >> filename;

	ifstream inputStream(filename.c_str());

	while(inputStream >> num)
	{
		sum += num;
		cout << num << endl;
	}

	string outputName = "sum.txt";
	ofstream outStream;

	outStream.open(outputName.c_str());
	outStream << sum << endl;
	outStream.close();

	return 0;
}

