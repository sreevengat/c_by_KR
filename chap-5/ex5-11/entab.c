#include <stdio.h>
#include "entab.h"

void
entab(int ts){
	
	int c, nb, nt;
	

	if (!ts)
		ts=TABSTOPS;
	nb=0;
	while ((c=getchar()) != EOF){
		if (c == ' ')
			++nb;
		else {
			if (nb > 0){
				/* print number of tabs */
				for (nt = nb/ts; nt > 0; --nt)
					printf("\\t");
				/* print number of spaces */
				for (nb = nb%ts; nb > 0; --nb)
					printf("\\b");
			}
			putchar(c);
		}
	}
}



