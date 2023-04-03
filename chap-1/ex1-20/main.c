/*
	page-34
	EX1-20. Write a program detab that replaces tabs 
	in the input with the proper number of blanks to
	space to the next tab stop . Assume a fixed set of 
	tab stops , say every n columns . Should n be a
	variable or a symbolic parameter
*/

/*
	Ans: n be a variable
*/

/*
	vertical bars are tabstops. set your 
	editor for tabstops=4
	|	|	|	|
		
*/

#include <stdio.h>

#define TABSTOPS	4


int
main(void){
	
	int c, n;
	
	n=0;
	while ((c=getchar()) != EOF){
		if (c != '\n' && c != '\t'){
			++n;
			if (n == TABSTOPS)
				n=0;
		}
		if (c == '\t'){
			if (n == 0)
				putchar(c);
			else {
				n = TABSTOPS - n;
				while (n > 0){
					n--;
					printf("\\b");
				}
			}
		}else
			putchar(c);
	}
	return 0;
}



