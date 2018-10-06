#include <iostream>
#include <vector>

struct AST
{
	std::string* label;
	std::string* value;
	std::vector<struct AST*> children;

	public:
		AST()
		{
		}

		AST(std::string* l, std::string* v)
		{
			label = l;
			value = v;
		}
};



int main()
{
	std::cout << "Hello World" << std::endl;

	std::string* l = new std::string("PLUS");
	std::string* v = new std::string("");
	struct AST* node = new AST(l, v);


	std::cout << *(node -> label) << std::endl;
	std::cout << *(node -> value) << std::endl;

	
	std::string* l_1 = new std::string("FLOAT");
	std::string* v_1 = new std::string("1");
	struct AST* node_1 = new AST(l_1, v_1);

	std::cout << *(node_1 -> label) << std::endl;
	std::cout << *(node_1 -> value) << std::endl;

	node -> children.push_back(node_1);
	std::cout << *(node -> children[0] -> label) << std::endl;

	if(node)
	{
		std::cout << "Printing in the IF statement." << std::endl;
	}
	else
	{
		std::cout << "Printing in the ELSE statement." << std::endl;
	}
	
	std::string testString("");

	if(testString == "")
	{
		std::cout << "Printing in the IF statement." << std::endl;
	}
	else if(testString == "Hello")
	{
	//	std::cout << "Printing in the else if statement." << std::endl;
	}
	else
	{
		std::cout << "Printing in the Else statement." << std::endl;
	}

	struct AST* emptyNode;

	emptyNode = node;

	std::cout << *(emptyNode -> label) << std::endl;

	
	return 0;

}

