#include "ShoppingCart.hpp"

using namespace std;

int main()
{
	Item myItem;
	Item myOverloadedItem("Witcher 3", 49.99, 1);

	ShoppingCart amazon;

	amazon.addItem(&myItem);
	amazon.addItem(&myOverloadedItem);

	return 0; 

}
