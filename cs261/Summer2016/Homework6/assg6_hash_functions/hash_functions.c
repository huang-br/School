#include "hash_functions.h"
#include <string.h>

/*This hash function should just return the length of str.*/
int hash_by_length(const char* str) {
	/*TODO: Complete this function.*/
	int length = strlen(str);
	return length;
}

/*This hash function should return the sum the ASCII values of each character
 * in str.
 *
 * Note: To get a char's ASCII value simply treat the char as a number in your
 * code.*/
int hash_by_sum(const char* str) {
	/*TODO: Complete this function.*/
	int k;
	int sum = 0;

	for(k=0; k < strlen(str); k++)
	{
		sum += str[k];
	}

	return sum;
}

/*This hash function should shift the value of each char according to its index
 * in the string and return the sum of the shifted values.
 *
 * To shift a char, multiply it by 2^i where i is the index of the char.
 *
 * Example: if the char at index 4 was value 11, you would treat its value
 * as 11*(2*2*2*2) when summing the chars.*/
int hash_by_shifted_sum(const char* str) {
	/*TODO: Complete this function.*/
	int k,j;
	int sum = 0;
	for(k=0; k < strlen(str); k++)
	{
		int power =1;
		for(j=0; j < k; j++)
		{
			power *= 2;
		}
		int num = str[k] * power;
		sum += num;
	}

	return sum;
}
