#include <iostream>
#include "Library.hpp"

int main()
{
	Library lib;
	Book book1("1", "Witcher", "Some Polish dude");
	Book book2("2", "Hexer", "same polish dude");


	std::string name = book1.getTitle();

	std::cout << name << std::endl;

	return 0;
}





