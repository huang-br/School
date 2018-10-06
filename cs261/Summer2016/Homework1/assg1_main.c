/*Local headers*/
#include "assg1_fibonacci.h"
#include "assg1_main.h"

/*Libraries used*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*Loops through command line arguments and processes them.
 * 	In C, main functions return 0 if no errors occur and something non-zero
 * 	otherwise.*/
int main (int argc, char** argv) {
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
		int err = process_arg(argv[i]);

		/*Check if an error was returned and exit if so.*/
		if (err) {
			fprintf(stderr,"Cannot process argument \"%s\"\n",argv[i]);
			return 1;
		}
	}
	return 0;
}

/*Processes a given string, where strings that parse as numbers are fed
 *	directly to the hungry fibonacci timer, and ones that don't are assumed to
 * 	be filenames pointing to files full of numbers to be fed to the insatiable
 * 	fibonacci timer.*/
int process_arg(char* arg) {
	/*Local Variables*/
	char* end_ptr = NULL;

	/*Consult the man page for strtol if you want to know exactly what
	 * is going on here.*/
	int n = strtol(arg,&end_ptr,10);
	/*No characters will be consumed by strtol if nothing can be parsed.*/
	if (strlen(arg) == strlen(end_ptr)) {
		return process_file(arg);
	}
	/* implicit else */
	return time_fib_at_n(n);
}

/*Are you ready for file IO? There are many ways to skin this cat, but this
 * 	function will take a string, assume it's a filename, open that file,
 * 	and feed all the number therein to the fibonacci timer.*/
int process_file(char* fname) {
	/*Local Variables*/
	FILE* file_ptr = fopen(fname,"r");/*Open up that file!*/
	char *file_contents = NULL, *token = NULL, *end_ptr = NULL;
	const char* delimiters = " \t\r\n\v\f";/*White space delimiters.*/
	int file_size = 0, n;

	/*If there was an error when opening the file ...*/
	if (file_ptr == NULL) {
		return 1;
	}

	/*This block measures the file size, copies all contents to one string,
	 * 	then closes the file.*/
	fseek(file_ptr,0L,SEEK_END);
	file_size = ftell(file_ptr);
	fseek(file_ptr,0L,SEEK_SET);
	file_contents = calloc(file_size+1,sizeof(char));
	fread(file_contents,sizeof(char),file_size,file_ptr);
	file_contents[file_size]='\0';/*Ensure master string is null terminated.*/
	fclose(file_ptr);

	/*This loops tokenizes the large string, delimited by whitespace.*/
	token = strtok(file_contents,delimiters);
	while (token != NULL) {
		/*As with detecting numbers versus filenames, this will verify that
		 * each token parses as a number.*/
		n = strtol(token,&end_ptr,10);
		if (strlen(token) == strlen(end_ptr)) {
			return 1;
		}
		/* implicit else */
		time_fib_at_n(n);/*More numbers for the ravenous fibonacci timer.*/
		token = strtok(NULL,delimiters);
	}
	return 0;
}

/*For a given n, this function calls your iterative_fibonacci and
 * 	recursive_fibonacci functions, records the results, notes how
 * 	long it took, and prints all that stuff out.*/
int time_fib_at_n(n) {
	/*Local Variables*/
	unsigned long iter_result, recur_result;
	double iter_time, recur_time;
	struct timespec start, end;

	printf("Running iterative_fibonacci(%d) ...\n",n);
	clock_gettime(CLOCK_REALTIME,&start);
	iter_result = iterative_fibonacci(n);
	clock_gettime(CLOCK_REALTIME,&end);
	iter_time = ((end.tv_sec*(1.0e9)+end.tv_nsec)-(start.tv_sec*(1.0e9)+start.tv_nsec))*1.0e-9;
	printf("\titerative_fibonacci(%d) returned %ld\n",n,iter_result);
	printf("\t\tand took %9.9f seconds.\n",iter_time);
	
	printf("Running recursive_fibonacci(%d) ...\n",n);
	clock_gettime(CLOCK_REALTIME,&start);
	recur_result = recursive_fibonacci(n);
	clock_gettime(CLOCK_REALTIME,&end);
	recur_time = ((end.tv_sec*(1.0e9)+end.tv_nsec)-(start.tv_sec*(1.0e9)+start.tv_nsec))*1.0e-9;
	printf("\trecursive_fibonacci(%d) returned %ld\n",n,recur_result);
	printf("\t\tand took %9.9f seconds.\n",recur_time);

	return 0;
}

