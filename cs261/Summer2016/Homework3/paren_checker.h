#ifndef PAREN_CHECKER_H
#define PAREN_CHECKER_H

#define TYPE char

#include <stdbool.h>

/*This program takes each argument as a filename and checks to see if it is
 * parentheses balanced.*/
int main(int argc, char** argv);

/*This function will take a string, assume it's a filename, open that file,
 * 	iterate over each character in that file, feed the brackets to your
 * 	check_next_paren function, and determine if the file had balanced
 * 	parentheses or not.*/
bool process_file(char* fname);

#endif/*ndef PAREN_CHECKER_H*/
