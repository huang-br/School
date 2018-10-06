#include <iostream>
#include <map>

extern int yylex();

extern std::map<std::string, std::string> symbols;
extern std::string* prog;

int main(int argc, char const *argv[]) {
  if (!yylex()) {
    //Program Wrpper
    std::cout << "#include <iostream>" << std::endl;
    std::cout << "int main() {" << std:: endl;

    std::map<std::string, std::string>::iterator it;
    //Using symbol table to find all the variables. Declaring them all as doubles.
    for(it = symbols.begin(); it != symbols.end(); it++)
    {
	    std::cout << "double " << it->first << ';' << std:: endl;
    }

    //Using symbol table to assign all variables.

    for (it = symbols.begin(); it != symbols.end(); it++) 
    {
      std::cout << it->first << " = " << it->second << ';' << std::endl;
    }

    //Using symbol table to check the variables.
    
    for (it = symbols.begin(); it != symbols.end(); it++)
    {
	    std::cout << "std::cout << \"" + it->first + ": \" " + "<< " + it->first + "<< std::endl;" << std::endl;
    }

    std::cout << "return 0;" << std::endl;
    std::cout << '}' << std::endl;
    return 0;
  } else {
    return 1;
  }
}
