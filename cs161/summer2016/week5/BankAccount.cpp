/*****************************************************************
 * Author: Brian Huang
 * Date: 7/13/2016
 * Description: The implentation file for the Bank Account class.
*****************************************************************/

#include "BankAccount.hpp"

BankAccount::BankAccount()
{
}

BankAccount::~BankAccount()
{
}

BankAccount::BankAccount(string n, string i, double b)
{
	name = n;
	ID = i;
	balance = b;
}

void BankAccount::setName(string n)
{
	name = n;
}

void BankAccount::setID(string i)
{
	ID = i;
}

void BankAccount::setBalance(double b)
{
	balance = b;
}

string BankAccount::getCustomerName()
{
	return name;
}

string BankAccount::getCustomerID()
{
	return ID;
}

double BankAccount::getCustomerBalance()
{
	return balance;
}

void BankAccount::withdraw(double amount)
{
	if(amount > balance)
	{
		cout << "You do not have enough money to withdraw $" << amount << "from your account." << endl; 
	}
	else
	{
		balance - amount;
		cout << "$" << amount << " has be deducted from your account." << endl;
	}
}

void BankAccount::deposit(double amount)
{
	balance = balance + amount;
	cout << "You have added $" << amount << " to your account." << endl;
}


