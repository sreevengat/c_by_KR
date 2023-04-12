/*
	page-118
	EX5-12. Extend entab and detab to
	accept the shorthand entab -m +n
	to mean tab stops every n columns,
	starting at column m. Choose
	convenient (for user_default
	behaviour.
*/

#include <stdio.h>
#include "atof.h"
#include "detab.h"
#include "entab.h"

int
main(int argc, char *argv[]){
	
	int m, n;
	char *t = *argv;

	m=n=0;
	if (argc > 1){
		int c;
		while (--argc > 0){
			c = (*++argv)[0];
			if (c == '-')
				m = (int)atof(++*argv);
			else if (c == '+')
				n = (int)atof(++*argv);
			else{
				printf("Usage: %s -m +n\n", t);
				return 1;
			}
		}
	}

	detab(m, n);
	//entab(n);
	return 0;
}
