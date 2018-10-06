#include "Library.hpp"
#include <iostream>

Library::Library()
{
	currentDate = 0;
}

void Library::addBook(Book *b)
{
	holdings.push_back(b);
}

void Library::addPatron(Patron *p)
{
	members.push_back(p);
}

std::string Library::checkOutBook(std::string pID, std::string bID)
{
	Patron *person = getPatron(pID);
	Book *theBook = getBook(bID);

	if((theBook == NULL)||(person == NULL))
	{
		return "Book not found";
	}
	else if(theBook -> getLocation() == CHECKED_OUT)
	{
		return "Book is checked out";
	}
	else if(theBook -> getLocation() == ON_HOLD_SHELF)
	{
		return "Book is on hold";
	}	
	else
	{		
		person -> addBook(theBook);
		theBook -> setLocation(CHECKED_OUT);
		return "Book successfuly checked out";
	}
}

std::string Library::returnBook(std::string bID)
{
	for(int k=0; k < holdings.size(); k++)
	{
		if(holdings.at(k) -> getIdCode() == bID && holdings.at(k) -> getLocation() != CHECKED_OUT)
		{
			return "book already in Library";
		}
		else if(holdings.at(k) -> getIdCode() == bID && holdings.at(k) -> getLocation() == CHECKED_OUT)
		{
			Patron *temp = holdings.at(k) -> getCheckedOutBy();
			temp -> removeBook(holdings.at(k));
			if(holdings.at(k) -> getRequestedBy() != NULL)
			{
				holdings.at(k) -> setLocation(ON_HOLD_SHELF);
				return "return successful.";
			}
			else
			{
				holdings.at(k) -> setLocation(ON_SHELF);
				return "return successful.";
			}
		}
	}
	return "book not found";
}

std::string Library::requestBook(std::string pID, std::string bID)
{
	Book *theBook = getBook(bID);
	Patron *person = getPatron(pID);
	if(theBook == NULL)
	{
		return "Book not found";
	}
	else if(person == NULL)
	{
		return "Patron not found";
	}
	else if(theBook -> getLocation() == ON_HOLD_SHELF)
	{
		return "Book is already on hold";
	}
	else
	{
		theBook -> setRequestedBy(person);
	}
}

std::string Library::payFine(std::string pID, double payment)
{
	Patron *person = getPatron(pID);
	person -> amendFine(payment);
}

void Library::incrementCurrentDate()
{
	currentDate++;
	for(int k=0; k < members.size(); k++)
	{
		members.at(k) -> amendFine(00.10);
	}	
}

Patron* Library::getPatron(std::string pID)
{
	for(int k=0; k < members.size(); k++)
	{
		if(members.at(k) -> getIdNum() == pID)
		{
			return members.at(k);
		}
	}
	return NULL;
}

Book* Library::getBook(std::string bID)
{
	for(int k=0; k < holdings.size(); k++)
	{
		if(holdings.at(k) -> getIdCode() == bID)
		{
			return holdings.at(k);
		}
	}
	return NULL;
}

