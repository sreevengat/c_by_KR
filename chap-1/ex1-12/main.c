/*
	page-21
	EX1-12. Write a program that prints
	its input one word per line
*/

#include <stdio.h>

#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */


int
main(void){
	
	int c ,state;

	state  = OUT;
	while ((c=getchar()) != EOF){
		/* dont print blanks, tabs, newlines */
		if (c != ' ' && c != '\n' && c != '\t')
				putchar(c);
		if (c == ' ' || c == '\n' || c == '\t'){
			if (state == IN){
				state = OUT;
				putchar('\n');
			}
		}
		else if (state == OUT){
			state = IN;
		}
	}
	return 0;
}
