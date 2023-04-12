#include <stdio.h>
#include "entab.h"

void
entab(int tc, int ts){
	
	int c, nb, nt, col;
	
	if (tc <= 0)
		tc=0;
	if (ts <= 0)
		ts = TABSTOPS;

	nb=0;
	while ((c=getchar()) != EOF){
		if (c == ' '){
			col++;
			if (col >= tc)
				++nb;
		}
		else {
			if (nb > 0){
				/* print number of tabs */
				for (nt = nb/ts; nt > 0; --nt)
					printf("\\t");
				/* print number of spaces */
				for (nb = nb%ts; nb > 0; --nb)
					printf("\\b");
			}
			col=0;
			putchar(c);
		}
	}
}



