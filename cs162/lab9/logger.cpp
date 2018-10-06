#include <fstream>
#include <ctime>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

string monthConvert(int);

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout << "Needs a name." << endl;
		return 0;
	}
	else
	{
		//Getting the time and date;
		time_t now = time(0);
		tm *date = localtime(&now);
	
		int year = 1900 + date -> tm_year; //year
		int numMonth = 1 + date -> tm_mon;  //month
		int day = date -> tm_mday; //day
		
		//Getting the name
		string name = argv[1];
		
		//Creating the month name
		string month = monthConvert(numMonth);
		
		//Using stringstream to put all together
		stringstream ss(stringstream::out | stringstream::in);
		ss << name << '_' << day << month << year << ".txt";	
		string all = ss.str();	
		
		//Creating the file
		ofstream outStream;
		outStream.open(all.c_str());
		cout <<"Type some stuff, enter an empty line to finish." << endl;
		
		//Writing to the file
		string stuff;
		do
		{
			getline(cin, stuff);
			outStream << stuff << endl;
		}
		while(!stuff.empty());

		outStream.close();
		return 0;
	}
}

string monthConvert(int num)
{
	string month;
	if(num == 1)
	{
		month = "Jan";
		return month;
	}
	else if(num == 2)
	{
		month = "Feb";
		return month;
	}
	else if(num == 3)
	{
		month = "Mar";
		return month;
	}
	else if(num == 4)
	{
		month = "Api";
		return month;
	}
	else if(num == 5)
	{
		month = "May";
		return month;
	}
	else if(num == 6)
	{
		month = "Jun";
		return month;
	}
	else if(num == 7)
	{
		month = "Jul";
		return month;
	}
	else if(num == 8)
	{
		month = "Aug";
		return month;
	}
	else if(num == 9)
	{
		month = "Sep";
		return month;
	}
	else if(num == 10)
	{
		month = "Oct";
		return month;
	}
	else if(num == 11)
	{
		month = "Nov";
		return month;
	}
	else if(num == 12)
	{
		month = "Dec";
		return month;
	}
}
