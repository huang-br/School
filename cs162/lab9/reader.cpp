#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout << "Needs a name. " << endl;
		return 0;
	}
	else
	{
		string line;
		string filename = argv[1];

		ifstream inputStream(filename.c_str());

		if(inputStream.is_open())
		{
			while(getline(inputStream,line))
			{
				cout << line << endl;
			}
			inputStream.close();
		}
		return 0;
	}
}


