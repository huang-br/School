/*Local Includes*/
#include "paren_checker.h"
#include "stack.h"
#include "check_next_paren.h"

/*Library Includes*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*This program takes each argument as a filename and checks to see if it is
 * parentheses balanced.*/
int main(int argc, char** argv) {
	/*Local Variables*/
	int i;
	
	/*If no command line arguments given, return an error.*/
	if (argc < 2) {
		fprintf(stderr,"No arguments given!\n");
		return 1;
	}

	/*Iterate through the arguments.*/
	for (i=1; i<argc; i++) {
		/*Process the argument.*/
		bool err = process_file(argv[i]);

		/*Check if an error was returned and exit if so.*/
		if (err) {
			fprintf(stderr,"Cannot process argument \"%s\"\n",argv[i]);
			return 1;
		}
	}
	return 0;
}

/*This function will take a string, assume it's a filename, open that file,
 * 	iterate over each character in that file, feed the brackets to your
 * 	check_next_paren function, and determine if the file had balanced
 * 	parentheses or not.*/
bool process_file(char* fname) {
	/*Local Variables*/
	FILE* file_ptr = fopen(fname,"r");/*Open up that file!*/
	char nextchar;
	stack* paren_stack = new_stack();
	bool balanced = true;

	/*If there was an error when opening the file ...*/
	if (file_ptr == NULL) {
		return true;
	}

	/*This loop iterates over each character in the file, but only considers
	 * characters from the set {'(',')','{','}','[',']'} and passes them and
	 * a stack pointer along to a balance checker.*/
	nextchar = fgetc(file_ptr);
	while(nextchar!=EOF) {
		switch (nextchar) {
		case '(':
		case ')':
		case '{':
		case '}':
		case '[':
		case ']':
			balanced = check_next_paren(paren_stack,nextchar);
		default:
			break;
		}
		if (!balanced) {
			printf("File %s is not balanced.\n",fname);
			return false;
		}
		nextchar = fgetc(file_ptr);
	}
	fclose(file_ptr);

	/*When the file is finished, the stack should be empty.*/
	balanced = is_empty(paren_stack);
	if (!balanced) {
		printf("File %s is not balanced.\n",fname);
		return false;
	}
	printf("File %s is balanced.\n",fname);
	return false;/*Remember: the return value is meant to indicate an error,
					not whether or not the file was balanced.*/
}
