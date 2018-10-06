/* CS261- HW1 - Program6.c*/
/* Name:Brian Huang
 * Date:4/8/2016
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void lowerCase(char* word){
     /* Convert to lower case letters */
	int k;
	char temp;
	for(k=0; k < 100; ++k)
	{
		if(word[k] >= 65 && word[k] <= 90)
		{
			temp = toLowerCase(word[k]);
			word[k] = temp;
		}
		else
		{
		}
	}

}

void upperCase(char* word){
	/* Convert to upper case letters */
	int k;
	char temp;
	for(k=0; k < 100; ++k)
	{
		if(word[k] >= 97 && word[k] <= 122)
		{
			temp = toUpperCase(word[k]);
			word[k] = temp;
		}
		else
		{
		}
	}
}

int main(){
    /* Input a word and flag */
	int x;
	char word[100];
	printf("Enter a word: ");
	scanf("%s",word);
	printf("Uppercase or Lowercase? (1 for uppercase, 0 for lowercase) ");
	scanf("%d",&x);

    /* Print the input word and flag */
	printf("Your word is: %s\n", word);
	if(x == 1)
	{
		printf("You have chosen your word to be put in all uppercase\n");
	}
	else if(x == 0)
	{
		printf("You have chosen your word to be put in all lowercase\n");
	}
	else
	{
		printf("You have not chosen correctly.\n");
		exit(0);
	}	
    /* Based on the value of flag
	  Call lowerCase()
	  or
	  Call upperCase() */
	if(x == 1)
	{
		upperCase(word);
	}
	else if(x == 0)
	{
		lowerCase(word);
	}
    
    /* Print the new word */
	printf("Your word is: %s\n", word);
    return 0;
}
