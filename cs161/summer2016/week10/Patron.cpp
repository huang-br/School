#include "Patron.hpp"

Patron::Patron(std::string idn, std::string n)
{
	idNum = idn;
	name = n;
}

std::string Patron::getIdNum()
{
	return idNum;
}

std::string Patron::getName()
{
	return name;
}

std::vector<Book*> Patron::getCheckedOutBooks()
{
	return checkedOutBooks;
}

void Patron::addBook(Book* b)
{
	checkedOutBooks.push_back(b);
}

void Patron::removeBook(Book* b)
{
	for(int k=0; k <= checkedOutBooks.size(); k++)
	{
		if(checkedOutBooks.at(k) == b)
		{
			checkedOutBooks.erase(checkedOutBooks.begin() + k);
			return;
		}
	}
}

double Patron::getFineAmount()
{
	return fineAmount;
}

void Patron::amendFine(double amount)
{
	fineAmount += amount;
	if(fineAmount < 0)
	{
		fineAmount = 0;
	}
}
