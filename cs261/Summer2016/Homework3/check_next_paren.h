#ifndef CHECK_NEXT_PAREN_H
#define CHECK_NEXT_PAREN_H

#define TYPE char

#include "stack.h"
#include <stdbool.h>

/*This function should verify that 'nextchar' does not validate rules of
 * parentheses balancing according to parentheses history stored in
 * 'paren_stack'. If 'nextchar' is an open parentheses it may be pushed onto
 * the stack, otherwise the stack should be popped and nextchar and the popped
 * value should be compared to see if they complement each other.
 * This function should return true if balancing has not been violated
 * and false only in the case that you compared two chars and they did not
 * fit each other. See the README for more precise instructions and ask
 * questions in class or on Canvas for further clarification.
 *
 * You may assume this function is never passed any char other than those in
 * the set {'(',')','{','}','[',']'} and that they fit as such:
 *
 * 	Open parentheses		Matching closing parentheses
 * 				(					)
 * 				{					}
 * 				[					]
 * */
bool check_next_paren(stack* paren_stack,char nextchar);

#endif/*ndef PAREN_CHECKER_H*/
