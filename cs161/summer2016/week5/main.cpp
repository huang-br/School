#include <iostream>
#include "Box.hpp"
#include "BankAccount.hpp"

int main()
{
	BankAccount account1("Brian", "123456", 1000);
	account1.withdraw(10);
	account1.deposit(100);

	account1.withdraw(200);
	account1.deposit(1000);

	double finalBalance = account1.getCustomerBalance();

	return 0;
}

