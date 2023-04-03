/*
	page-20
	EX1-9. Write a program to copy its input to its output,
	replacing each string of one or more blanks by a single blank
*/

#include <stdio.h>


/* use ' ' or any char for visual */
#define REPLACE_CHAR	'_'

int
main(void){

	int c;
	int bk;
	
	bk=0;
	while ((c = getchar()) != EOF){
			if (c == ' ')
				++bk;
			if (c != ' '){
				if (bk > 0){
					bk=0;
					putchar(REPLACE_CHAR);
				}
				putchar(c);
			}
	}
	return 0;
}
