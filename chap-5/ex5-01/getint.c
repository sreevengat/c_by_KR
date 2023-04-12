#include <stdio.h>
#include <ctype.h>
#include "char.h"	/* for getch(), ungetch() */


/* get_int: get next integer from 
 * into *pn */
int
get_int(int *pn){

	int c, sign;

	while (isspace(c=getch()))	/* skip white space */
			;	
	if (!isdigit(c) && c != EOF
			&& c != '+' && c != '-'){
		ungetch(c);	
		return 0;
	}
	sign = (c=='-') ? -1 : 1;
	if (c == '+' || c == '-')
		c=getch();
	for (*pn=0; isdigit(c); c=getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	if (isalpha(c))		
		return 0;
	return c;
}
