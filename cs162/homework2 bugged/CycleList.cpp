#include "CycleList.h"

//Default Constructor
CycleList::CycleList()
{
	index = 1;
}

//Functions
void CycleList::addCycle()
{
	Cycle *transfer, newbike;
	newbike.getCycle();
	if(index == 1)
	{ 
		++index;
		bikes = new Cycle[index];
		bikes[1] = newbike;
	}
	else
	{
		transfer = new Cycle[index];
		for(int k = 0; k < index; k++)
		{
			transfer[k] = bikes[k];
		}
		++index;
		delete [] bikes;
		bikes = new Cycle[index];
		for(int l = 0; l < index-1; l++)
		{
			bikes[l] = transfer[l];
		}
		delete [] transfer;
		bikes[index-1] = newbike;
	}
}

void CycleList::removeCycle()
{
	int removed_spot;
	if(index == 1)
	{
		cout << "There is nothing to remove.";
	}
	else
	{
		cout <<"Which vehicle number would you like to remove? ";
		cin >> removed_spot;	
		Motorcycle *transfer;
		
		transfer = new Motorcycle[index-1];
		for(int k = 1; k < removed_spot ; k++)
		{
			transfer[k] = bikes[k];
		}
		for(int l=removed_spot+1; l < index; l++)
		{
			transfer[l-1] = bikes[l];
		}
	
		--index;
		delete[]bikes;
		bikes = new Motorcycle[index];
		for(int m = 1; m < index; m++)
		{
			bikes[m] = transfer[m];
		}
		delete[]transfer; 
	}
}


void CycleList::PrintList()
{
	for(int k = 1; k < index; k++)
	{

		if(bikes[k].getPrice() >= 10000)
		{
			cout <<"Motorcycle #" << k << endl;
			cout <<"Its over 10000!!!" << endl;
			bikes[k].print();
			cout << endl;
		}
		else
		{
			cout << "Motorcycle #" << k << endl; 
			bikes[k].print();
			cout << endl;
		}
	}
}

void CycleList::PrintBasic()
{
	for(int k = 1; k < index; k++)
	{
		if(bikes[k].getPrice() >= 10000)
		{
			cout <<"Motorcycle #" << k << endl;
			cout <<"Its over 10000!!!" << endl;
			bikes[k].basicPrint();
			cout << endl;
		}
		else
		{	
			cout <<"Motorcycle #" << k << endl;
			bikes[k].basicPrint();
			cout << endl;
		}
	}
}

void CycleList::adjustMiles()
{
	int number, spot;
	if(index == 1)
	{
		cout <<"There are no bikes.";
	}
	else
	{
		cout<<"Which vehicle would you like to add miles to? ";
		cin >> spot;
		cout<<"How many miles? ";
		cin >> number;
		bikes[spot].addMiles(number);
	}
}
		
void CycleList::Search()
{
	double lower, upper, price;
	if (index == 1)
	{
		cout <<"There are no bikes.";
	}
	else
	{
		cout <<"Search by Price" << endl;
		cout <<"Lower price range: " ;
		cin >> lower;
		cout <<"Upper price range: ";
		cin >> upper;
		cout << endl;
		cout <<"Search Resualts:" << endl;
		for(int k = 1; k < index; k++)
		{
			if(bikes[k].getPrice() >= lower && bikes[k].getPrice() <= upper)
			{
				bikes[k].basicPrint();
				cout << endl; 	
			}
		}
	}
}

void CycleList::buyCycle()
{
	if(index == 1)
	{
		cout << "There are no bikes. " << endl;
	}
	else
	{
		int num, months;
		double price, deduct, rate;
		string choice;
		cout << "Which vehicle would you like to buy?" << endl;
		cout << "Enter a number: "; 
		cin >> num;
		cout << "Interest Rate(enter as percent): ";
		cin >> rate;
		rate = rate/100;
		cout << "Amount of months: "; 
		cin >> months;
		cout << "Any Deductions? ";
		cin >> deduct;
		cout <<"There will be a $95 administrative fee added to your total." << endl;
		
		//Calculations
		price = bikes[num].getPrice();
		price = price + 95 - deduct;
		price = price * ((rate * pow(1+rate, months)) / (pow(1+rate, months) -1));
		
		cout <<"Total Loan Amount: " << bikes[num].getPrice() << endl;	
		cout <<"Your Interest Rate: " << rate << "%" << endl;
		cout <<"Monthly Paymens: " << price << endl;
		
		cout <<"Do you want to buy the Motorcycle? (yes or no)" ;
		cin >> choice;
		
		if(choice == "yes")
		{
			Motorcycle *transfer;
		
			transfer = new Motorcycle[index-1];
			for(int k = 1; k < num ; k++)
			{
				transfer[k] = bikes[k];
			}
			for(int l=num+1; l < index; l++)
			{
				transfer[l-1] = bikes[l];
			}
	
			--index;
			delete[]bikes;
			bikes = new Motorcycle[index];
			for(int m = 1; m < index; m++)
			{
				bikes[m] = transfer[m];
			}
			cout << "Motorcycle is now sold." << endl;
		}
		else if(choice == "no")
		{

		}
	}
}
	








	
	
	






		
