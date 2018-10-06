#include <iostream>
#include <set>
#include "parser.hpp"

extern int yylex();

//extern std::string* target_program;
//extern std::set<std::string> symbols;

extern struct ASTnode* Root;

void traverseTree(struct ASTnode* root, int level);

int main() {
  if (!yylex()) {
    // Write initial gz stuff
    int Level = 0;
    std::cout << "digraph G {" << std::endl;
    traverseTree(Root, Level);
    std::cout << "}" << std::endl;
  }
}

void traverseTree(struct ASTnode* node, int level)
{
	std::cout << "\tn" << level << "[label = \"" << *(node -> label) << ' ' << *(node -> value) << "\"];" << std::endl;
	for(unsigned int i =0; i < node -> children.size(); i++)
	{
		std::cout << "\tn" << level << " -> " << "n" << level << "_" << i << ";" << std::endl;
		traverseTree(node -> children[i], (level + 1));
	}
	
}
