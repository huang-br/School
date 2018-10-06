#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cout << "Needs a file name to open." << endl;
	}
	else
	{
		string filename = argv[1];
		ifstream inputStream(filename.c_str());

		char c = inputStream.get();

		while(inputStream.good())
		{
			cout << c;
			c = inputStream.get();
		}

		inputStream.close();
	}

	return 0;
}

			
	
