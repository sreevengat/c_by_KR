#include <stdio.h>
#include <ctype.h>

#define NUMBER	'0'

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int
getop(char s[]){
	
	int i, c;
	
	i=0;
	/* skip white spaces */
	while ((s[i] = c = getch()) == ' ' ||
			c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.'){
		if (c == '-' || c == '+'){ /* handle sign */
			c=getch();
			if (isdigit(c)){
				s[++i] = c;
				goto HERE;
			}else {
				ungetch(c);
				c = s[0];
			}
		}
		return c;	/* not a number */
	}

	if (isdigit(c))	/* collect integer part */
HERE:	while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')	/* collect fractional part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)	/* push back the character */
		ungetch(c);
	return NUMBER;
}
