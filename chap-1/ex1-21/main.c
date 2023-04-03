/*
	page-34
	EX1-21. Write a program entab that replaces
	strings of blanks by the minimum number of
	tabs and blanks to achieve the same spacing.
	Use the same tab stop as for detab. When
	either a tab or a single blank would suffice
	to reach a tab stop, which should be given
	preference?
*/

/*
	single blank, will be the preference
*/

#include <stdio.h>

#define TABSTOPS	4

int
main(void){
	
	int c, nb, nt;
	
	nb=0;
	while ((c=getchar()) != EOF){
		if (c == ' ')
			++nb;
		else {
			if (nb > 0){
				/* print number of tabs */
				for (nt = nb/TABSTOPS; nt > 0; --nt)
					printf("\\t");
				/* print number of spaces */
				for (nb = nb%TABSTOPS; nb > 0; --nb)
					printf("\\b");
			}
			putchar(c);
		}
	}

	return 0;
}



