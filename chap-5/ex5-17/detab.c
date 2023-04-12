/*
	vertical bars are tabstops. set your 
	editor for tabstops=4
	|	|	|	|
		
*/

#include <stdio.h>
#include "detab.h"


void
detab(int tc, int ts){
	
	int c, n, col;
	
	n=0;
	col=0;
	if (tc <= 0)
		tc=0;
	if (!ts)
		ts=TABSTOPS;
	while ((c=getchar()) != EOF){
		if (c != '\n' && c != '\t'){
				col++;
				if (col >= tc)
					++n;
			if (n == ts){
				col=0;
				n=0;
			}
		}
		if (c == '\t'){
			if (n == 0)
				putchar(c);
			else {
				n = ts - n;
				while (n > 0){
					n--;
					putchar('_');
				}
			}
		}else
			putchar(c);
	}
}



