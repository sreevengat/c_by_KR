#include <stdio.h>
#include <ctype.h>
#include "char.h"

/* getfloat: get next float value from input */
int
get_float(double *pd){
	
	int c, sign;
	double pow;

	while (isspace(c=getch()))	/* skip whit space */
		;
	if (!isdigit(c) && c != EOF && c != '+'
			&& c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+')
		c=getch();
	for (*pd=0.0; isdigit(c); c=getch())
		*pd = 10.0 * *pd + (c - '0');
	if  (c == '.')
		c=getch();
	for (pow=1.0; isdigit(c); c=getch()){
		*pd = 10.0 * *pd + (c-'0');
		pow *= 10.0;
	}
	*pd = *pd * sign / pow;
	if (c != EOF)
		ungetch(c);
	if (isalpha(c))
		return 0;
	return c;
}
