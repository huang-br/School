#include "tree_test_avl.h"
#include "../tree.h"
#include "unit_test.h"

/*This is a series of unit tests meant to test correct functionality of the
 * height and balancing functions of a tree.*/
int main(int argc, char** argv) {
	new_tests();
	announce_code(tree_node* root = NULL);
	announce_code(bool size_contents_check = true);
	int correct_size = 0;
	summarize_code("Adding numbers [1,1000]");
		generic a;
		for (a = 1.0f; a <= 1000.0f; a += 1.0f) {
			root = tree_add(root,a);
			correct_size++;
			size_contents_check = (tree_size(root)==correct_size) && tree_contains(root,a);
			if (!size_contents_check) {
				summarize_code("WARNING: tree is failing to build properly.");
				summarize_code("size_contents_check == false");
				break;
			}
		}
		if (size_contents_check) {
			summarize_code("NOTE: tree meets size and contents requirements");
			summarize_code("size_contents_check == true");
		}
	announce_code(int true_height = hard_height_count(root));
	announce_code(int reported_height = tree_height(root));
	announce_code(int max_height_allowed = 15);
	unit_test(size_contents_check && true_height == reported_height && true_height <= max_height_allowed,5);
	announce_code(free_tree(root));
	announce_code(root = NULL);
	summarize_code("Adding numbers [-5000,5000]");
		root = tree_add(root,0.0f);
		correct_size = 1;
		for (a = 1.0f; a <= 5000.0f; a += 1.0f) {
			root = tree_add(root,a);
			root = tree_add(root,-a);
			correct_size += 2;
			size_contents_check = (tree_size(root)==correct_size) && tree_contains(root,a) && tree_contains(root,-a);
			if (!size_contents_check) {
				summarize_code("WARNING: tree is failing to build properly.");
				summarize_code("size_contents_check == false");
				break;
			}
		}
		if (size_contents_check) {
			summarize_code("NOTE: tree meets size and contents requirements");
			summarize_code("size_contents_check == true");
		}
	announce_code(true_height = hard_height_count(root));
	announce_code(reported_height = tree_height(root));
	announce_code(max_height_allowed = 19);
	unit_test(size_contents_check && true_height == reported_height && true_height <= max_height_allowed,5);
	announce_code(free_tree(root));
	announce_code(root = NULL);
	summarize_code("Adding numbers [-100000,100000]");
		root = tree_add(root,0.0f);
		correct_size = 1;
		generic b;
		for (b = 0.0f; b < 100000.0f; b += 100.0f) {
			for (a = b + 100.0f; a > b; a -= 1.0f) {
				root = tree_add(root,a);
				root = tree_add(root,-a);
				correct_size += 2;
				size_contents_check = (tree_size(root)==correct_size) && tree_contains(root,a) && tree_contains(root,-a);
				if (!size_contents_check) {
					summarize_code("WARNING: tree is failing to build properly.");
					summarize_code("size_contents_check == false");
					break;
				}
			}
			if (!size_contents_check) {
				break;
			}
		}
	summarize_code("Removing numbers [-50000,50000]");
		root = tree_remove(root,0.0f);
		correct_size--;;
		for (b = 0.0f; b < 50000.0f; b += 100.0f) {
			for (a = b + 100.0f; a > b; a -= 1.0f) {
				root = tree_remove(root,a);
				root = tree_remove(root,-a);
				correct_size -= 2;
				size_contents_check = (tree_size(root)==correct_size) && !tree_contains(root,a) && !tree_contains(root,-a);
				if (!size_contents_check) {
					summarize_code("WARNING: tree is failing to build properly.");
					summarize_code("size_contents_check == false");
					break;
				}
			}
			if (!size_contents_check) {
				break;
			}
		}
		if (size_contents_check) {
			summarize_code("NOTE: tree meets size and contents requirements");
			summarize_code("size_contents_check == true");
		}
	announce_code(true_height = hard_height_count(root));
	announce_code(reported_height = tree_height(root));
	announce_code(max_height_allowed = 24);
	unit_test(size_contents_check && true_height == reported_height && true_height <= max_height_allowed,5);
	announce_code(free_tree(root));
	report_tests();
	return 0;
}

/*Iteratively counts the height of a tree to verify it against
 * student's tree_height function*/
int hard_height_count(tree_node* t) {
	if (t == NULL) {
		return -1;
	}
	int lh = hard_height_count(t->left);
	int rh = hard_height_count(t->right);
	if (lh > rh) {
		return 1 + lh;
	}
	return 1 + rh;
}
