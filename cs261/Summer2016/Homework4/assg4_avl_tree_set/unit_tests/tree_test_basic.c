#include "tree_test_basic.h"
#include "../tree.h"
#include "unit_test.h"
#include <stdio.h>

/*This is a series of unit tests meant to test basic functionality of the
 * add/remove/contains and size functions of a tree.*/
int main(int argc, char** argv) {
	new_tests();
	announce_code(tree_node* root = NULL);
	unit_test(tree_size(root)==0,1);
	summarize_code("Adding elements: 4,2,6,1,3,5,7");
		root = tree_add(root,4.0f);
		root = tree_add(root,2.0f);
		root = tree_add(root,6.0f);
		root = tree_add(root,1.0f);
		root = tree_add(root,3.0f);
		root = tree_add(root,5.0f);
		root = tree_add(root,7.0f);
		printf("Root left:%f, Root right:%f\n", root -> left -> element, root -> right -> element);
	unit_test(tree_size(root)==7,1);
	unit_test(tree_size(root->left)==3,2);
	unit_test(tree_size(root->right)==3,2);
	unit_test(tree_contains(root,1.0f),1);
	unit_test(tree_contains(root,2.0f),1);
	unit_test(tree_contains(root,3.0f),1);
	unit_test(tree_contains(root,5.0f),1);
	unit_test(tree_contains(root,5.0f),1);
	unit_test(tree_contains(root,6.0f),1);
	unit_test(tree_contains(root,7.0f),1);
	unit_test(!tree_contains(root,-1.0f),1);
	unit_test(!tree_contains(root,9.0f),1);
	summarize_code("Adding elements that are already there: 2,4,6");
		root = tree_add(root,4.0f);
		root = tree_add(root,2.0f);
		root = tree_add(root,6.0f);
	unit_test(tree_size(root)==7,2);
	summarize_code("Removing elements: 1,4,7");
		root = tree_remove(root,1.0f);
		root = tree_remove(root,4.0f);
		root = tree_remove(root,7.0f);
	unit_test(tree_size(root)==4,1);
	unit_test(!tree_contains(root,1.0f),1);
	unit_test(!tree_contains(root,4.0f),1);
	unit_test(!tree_contains(root,7.0f),1);
	summarize_code("About to add elements: 0.5,3.5,6.5,11");
	unit_test(!tree_contains(root,0.5f),1);
	unit_test(!tree_contains(root,3.5f),1);
	unit_test(!tree_contains(root,6.5f),1);
	unit_test(!tree_contains(root,11.0f),1);
	summarize_code("Adding elements: 0.5,3.5,6.5,11");
		root = tree_add(root,0.5f);
		root = tree_add(root,3.5f);
		root = tree_add(root,6.5f);
		root = tree_add(root,11.0f);
	unit_test(tree_size(root)==8,1);
	unit_test(tree_contains(root,0.5f),1);
	unit_test(tree_contains(root,3.5f),1);
	unit_test(tree_contains(root,6.5f),1);
	unit_test(tree_contains(root,11.0f),1);
	announce_code(free_tree(root));
	report_tests();
	return 0;
}
