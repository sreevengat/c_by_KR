/*
	page-118
	EX5-10. Write a program expr, which evaluates
	a reverse Polis expression from the command
	line , where each operator or operand is a
	separate argument for example,
	2 3 4 + *
*/


#include <stdio.h>
#include "char.h"
#include "calc.h"
#include "string.h"

int
main(int argc, char *argv[]){
	
	if (argc < 3){
		printf("error: Usage %s operand1 operand2 operator\n", *argv);
		return -1;
	}
	else{
		/* rev order the argv */
		ungetch('\n');
		while (--argc > 0){
			str_rev(argv[argc]);
			ungets(argv[argc]);
			ungetch(' ');
		}
		calc();
	}
	return 0;
}
