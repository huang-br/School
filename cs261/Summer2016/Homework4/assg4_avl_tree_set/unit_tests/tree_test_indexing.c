#include "tree_test_indexing.h"
#include "../tree.h"
#include "unit_test.h"

/*This is a series of unit tests meant to test correct functionality of the
 * size and index functions of a tree.*/
int main(int argc, char** argv) {
	new_tests();
	announce_code(tree_node* root = NULL);
	summarize_code("Adding numbers in range [-100,100]");
		root = tree_add(root,0.0f);
		generic a,b;
		for (a = 0.0f; a < 100.0f; a += 10.0f) {
			for (b = a + 10.0f; b > a; b-= 1.0f) {
				root = tree_add(root,b);
				root = tree_add(root,-b);
			}
		}
	unit_test(tree_get_at_index(root,0) == -100.0f,1);
	unit_test(tree_get_at_index(root,200) == 100.0f,1);
	unit_test(tree_get_at_index(root,100) == 0.0f,1);
	unit_test(tree_get_at_index(root,11) == -89.0f,1);
	unit_test(tree_get_at_index(root,29) == -71.0f,1);
	unit_test(tree_get_at_index(root,77) == -23.0f,1);
	unit_test(tree_get_at_index(root,113) == 13.0f,1);
	unit_test(tree_get_at_index(root,132) == 32.0f,1);
	unit_test(tree_get_at_index(root,152) == 52.0f,1);
	unit_test(tree_get_at_index(root,189) == 89.0f,1);
	announce_code(free_tree(root));
	report_tests();
	return 0;
}
