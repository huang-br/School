#include "AutoList.h"

//Default Constructor
AutoList::AutoList()
{
	index = 1;
}

//Functions
void AutoList::addAuto()
{
	Auto *transfer, newcar;
	newcar.getAuto();
	if(index == 1)
	{ 
		++index;
		cars = new Auto[index];
		cars[1] = newcar;
	}
	else
	{
		transfer = new Auto[index];
		for(int k = 0; k < index; k++)
		{
			transfer[k] = cars[k];
		}
		++index;
		delete [] cars;
		cars = new Auto[index];
		for(int l = 0; l < index-1; l++)
		{
			cars[l] = transfer[l];
		}
		delete [] transfer;
		cars[index-1] = newcar;
	}
}

void AutoList::removeAuto()
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
		Auto *transfer;
		
		transfer = new Auto[index-1];
		for(int k = 1; k < removed_spot ; k++)
		{
			transfer[k] = cars[k];
		}
		for(int l=removed_spot+1; l < index; l++)
		{
			transfer[l-1] = cars[l];
		}
	
		--index;
		delete[]cars;
		cars = new Auto[index];
		for(int m = 1; m < index; m++)
		{
			cars[m] = transfer[m];
		}
		delete[]transfer; 
	}
}


void AutoList::PrintList()
{
	for(int k = 1; k < index; k++)
	{

		if(cars[k].getPrice() >= 10000)
		{
			cout <<"Automobile #" << k << endl;
			cout <<"Its over 10000!!!" << endl;
			cars[k].print();
			cout << endl;
		}
		else
		{
			cout << "Automobile #" << k << endl; 
			cars[k].print();
			cout << endl;
		}
	}
}

void AutoList::PrintBasic()
{
	for(int k = 1; k < index; k++)
	{
		if(cars[k].getPrice() >= 10000)
		{
			cout <<"Automobile #" << k << endl;
			cout <<"Its over 10000!!!" << endl;
			cars[k].basicPrint();
			cout << endl;
		}
		else
		{	
			cout <<"Automobile #" << k << endl;
			cars[k].basicPrint();
			cout << endl;
		}
	}
}

void AutoList::adjustMiles()
{
	int number, spot;
	if(index == 1)
	{
		cout <<"There are no cars.";
	}
	else
	{
		cout<<"Which vehicle would you like to add miles to? ";
		cin >> spot;
		cout<<"How many miles? ";
		cin >> number;
		cars[spot].addMiles(number);
	}
}
		
void AutoList::Search()
{
	double lower, upper, price;
	if (index == 1)
	{
		cout <<"There are no cars.";
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
			if(cars[k].getPrice() >= lower && cars[k].getPrice() <= upper)
			{
				cars[k].basicPrint();
				cout << endl; 	
			}
		}
	}
}

void AutoList::buyCar()
{
	if(index == 1)
	{
		cout << "There are no cars. " << endl;
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
		price = cars[num].getPrice();
		price = price + 95 - deduct;
		price = price * ((rate * pow(1+rate, months)) / (pow(1+rate, months) -1));
		
		cout <<"Total Loan Amount: " << cars[num].getPrice() << endl;	
		cout <<"Your Interest Rate: " << rate << "%" << endl;
		cout <<"Monthly Paymens: " << price << endl;
		
		cout <<"Do you want to buy the car? (yes or no)" ;
		cin >> choice;
		
		if(choice == "yes")
		{
			Auto *transfer;
		
			transfer = new Auto[index-1];
			for(int k = 1; k < num ; k++)
			{
				transfer[k] = cars[k];
			}
			for(int l=num+1; l < index; l++)
			{
				transfer[l-1] = cars[l];
			}
	
			--index;
			delete[]cars;
			cars = new Auto[index];
			for(int m = 1; m < index; m++)
			{
				cars[m] = transfer[m];
			}
			cout << "Car is now sold." << endl;
		}
		else if(choice == "no")
		{

		}
	}
}
	








	
	
	






		
