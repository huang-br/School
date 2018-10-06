#include <vector>

struct ASTnode
{
	std::string* label;
	std::string* value;
	std::vector<struct ASTnode*> children;
	
	public:
		ASTnode(std::string* l, std::string* v)
		{
			label = l;
			value = v;
		}	
};

