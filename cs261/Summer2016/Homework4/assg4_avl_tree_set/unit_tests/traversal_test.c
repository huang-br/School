#include "traversal_test.h"
#include "../tree.h"
#include "../iterator.h"
#include "unit_test.h"

/*This is a series of unit tests meant to test correct construction of the
 * pre-,in-a nd post-order traversals of trees.*/
int main(int argc, char** argv) {
	generic correct_preorder[19] = {80.0f,40.0f,20.0f,10.0f,15.0f,30.0f,25.0f,60.0f,50.0f,70.0f,
									120.0f,100.0f,90.0f,81.0f,110.0f,140.0f,130.0f,150.0f,151.0f};
	generic correct_inorder[19]  = {10.0f,15.0f,20.0f,25.0f,30.0f,40.0f,50.0f,60.0f,70.0f,80.0f,
									81.0f,90.0f,100.0f,110.0f,120.0f,130.0f,140.0f,150.0f,151.0f};
	generic correct_postorder[19]= {15.0f,10.0f,25.0f,30.0f,20.0f,50.0f,70.0f,60.0f,40.0f,81.0f,
									90.0f,110.0f,100.0f,130.0f,151.0f,150.0f,140.0f,120.0f,80.0f};
	new_tests();
	announce_code(tree_node* root = NULL);
	summarize_code("Adding elements: 80,40,120,20,60,100,140,10,30,50");
	summarize_code("Adding elements: 70,90,110,130,150,15,25,81,151");
		root = tree_add(root,80.0f);
		root = tree_add(root,40.0f);
		root = tree_add(root,120.0f);
		root = tree_add(root,20.0f);
		root = tree_add(root,60.0f);
		root = tree_add(root,100.0f);
		root = tree_add(root,140.0f);
		root = tree_add(root,10.0f);
		root = tree_add(root,30.0f);
		root = tree_add(root,50.0f);
		root = tree_add(root,70.0f);
		root = tree_add(root,90.0f);
		root = tree_add(root,110.0f);
		root = tree_add(root,130.0f);
		root = tree_add(root,150.0f);
		root = tree_add(root,15.0f);
		root = tree_add(root,25.0f);
		root = tree_add(root,81.0f);
		root = tree_add(root,151.0f);
	summarize_code("Building pre-order iterator.");
		iterator* itr = tree_preorder_traversal(root);
		int match_count = 0;
		int i;
		printf("\tGiven preorder:\t\t");
		for (i=0; i < 19; i++) {
			generic correct = correct_preorder[i];
			generic given = -1.0f;
			if (has_next(itr)) {
				given = next(itr);
			}
			if (given == correct) {
				match_count++;
			}
			printf(" %g",given);
		}
		printf("\n");
		printf("\tCorrect preorder:\t");
		for (i=0; i < 19; i++) {
			generic correct = correct_preorder[i];
			printf(" %g",correct);
		}
		printf("\n");
	bool all_of_the_above_match = match_count == 19;
	unit_test(all_of_the_above_match,5);
	announce_code(free_iterator(itr));
	summarize_code("Building in-order iterator.");
		itr = tree_inorder_traversal(root);
		match_count = 0;
		printf("\tGiven inorder:\t\t");
		for (i=0; i < 19; i++) {
			generic correct = correct_inorder[i];
			generic given = -1.0f;
			if (has_next(itr)) {
				given = next(itr);
			}
			if (given == correct) {
				match_count++;
			}
			printf(" %g",given);
		}
		printf("\n");
		printf("\tCorrect inorder:\t");
		for (i=0; i < 19; i++) {
			generic correct = correct_inorder[i];
			printf(" %g",correct);
		}
		printf("\n");
	all_of_the_above_match = match_count == 19;
	unit_test(all_of_the_above_match,5);
	announce_code(free_iterator(itr));
	summarize_code("Building post-order iterator.");
		itr = tree_postorder_traversal(root);
		match_count = 0;
		printf("\tGiven postorder:\t");
		for (i=0; i < 19; i++) {
			generic correct = correct_postorder[i];
			generic given = -1.0f;
			if (has_next(itr)) {
				given = next(itr);
			}
			if (given == correct) {
				match_count++;
			}
			printf(" %g",given);
		}
		printf("\n");
		printf("\tCorrect postorder:\t");
		for (i=0; i < 19; i++) {
			generic correct = correct_postorder[i];
			printf(" %g",correct);
		}
		printf("\n");
	all_of_the_above_match = match_count == 19;
	unit_test(all_of_the_above_match,5);
	announce_code(free_iterator(itr));
	announce_code(free_tree(root));
	report_tests();
	return 0;
}
