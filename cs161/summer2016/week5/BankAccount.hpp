/***********************************************************************
 * Author: Brian Huang
 * Date: 7/13/2016
 * Description: The header file for the BankAccount class.
***********************************************************************/

#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
	public:
		//Defualt Constructor
		BankAccount();
		//Deconstructor
		~BankAccount();
		//Overloaded Contructor
		BankAccount(string, string, double);
		//Mutators
		void setName(string);
		void setID(string);
		void setBalance(double);
		//Accessors
		string getCustomerName();
		string getCustomerID();
		double getCustomerBalance();
		//Functions
		void withdraw(double);
		void deposit(double);
	private:
		string name;
		string ID;
		double balance;
};

#endif
