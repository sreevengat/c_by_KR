/*
	page-153
	EX7-1. Write a program that converts
	upper case to lower or lower case to 
	upper, depending on the name it is
	invoked with , as found in argv[0].
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LOWER	'a'
#define UPPER	'A'

int
main(int argc, char **argv){
	
	int opt;
	 
	if (strcmp(*argv, "./lower") == 0)
		opt = LOWER;
	else if (strcmp(*argv, "./upper") == 0)
		opt = UPPER;
	else{
		printf("error: argv[0] must be lower or upper \n");
		return 1;
	}
	
	int c;

	while ((c=getchar()) != EOF)
		if (opt == LOWER)
			putchar(tolower(c));
		else
			putchar(toupper(c));

	return 0;
}

