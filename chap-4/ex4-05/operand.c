#include <stdio.h>
#include <ctype.h>

#define NUMBER	'0'
#define ALPHA	'A'

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int
getop(char s[]){
	
	int i, c, alnum;
	
	i=0;
	alnum=0;
	/* skip white spaces */
	while ((s[i] = c = getch()) == ' ' ||
			c == '\t')
		;
	s[1] = '\0';
	if (!isalnum(c) && c != '.'){
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
	if (isalpha(c)){	/* collect alphabets */
	while (isalpha(s[++i] = c = getch()))
				;
		if (isspace(s[1]) || s[1] == '\0')
			return s[0];
		alnum = ALPHA;
	}else if (isdigit(c)){	/* collect integer part */
HERE:	while (isdigit(s[++i] = c = getch()))
			;
		if (c == '.')	/* collect fractional part */
			while (isdigit(s[++i] = c = getch()))
				;
		alnum = NUMBER;
	}
	s[i] = '\0';
	if (c != EOF)	/* push back the character */
		ungetch(c);
	return alnum;
}
