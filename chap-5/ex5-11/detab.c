/*
	vertical bars are tabstops. set your 
	editor for tabstops=4
	|	|	|	|
		
*/

#include <stdio.h>
#include "detab.h"


void
detab(int ts){
	
	int c, n;
	
	n=0;
	if (!ts)
		ts=TABSTOPS;
	while ((c=getchar()) != EOF){
		if (c != '\n' && c != '\t'){
			++n;
			if (n == ts)
				n=0;
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



