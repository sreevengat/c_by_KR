#include <stdio.h>
#include <ctype.h>

#define NUMBER	'0'
#define ALPHA	'A'
#define VARIABLE 'V'

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int
getop(char s[]){
	
	int i, c, ret;
	
	i=0;
	/* skip white spaces */
	while ((s[i] = c = getch()) == ' ' ||
			c == '\t')
		;
	s[1] = '\0';

	if (!isalnum(c) && c != '.' 
				&& c != '=' && c != '$'
				&& c != '?'){	/* = for assign to var, $ for get var value, ? print var value */
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
	if (c == '=' || c == '$' || c == '?'){
		while (!isspace(s[++i] = c = getch()))
				;
		ret = VARIABLE;
	}else if (isalpha(c)){	/* collect alphabets */
	while (isalpha(s[++i] = c = getch()))
				;
		if (isspace(s[1]) || s[1] == '\0')
			return s[0];
		ret = ALPHA;
	}else if (isdigit(c)){	/* collect integer part */
HERE:	while (isdigit(s[++i] = c = getch()))
			;
		if (c == '.')	/* collect fractional part */
			while (isdigit(s[++i] = c = getch()))
				;
		ret = NUMBER;
	}
	s[i] = '\0';	
	if (c != EOF)	/* push back the character */
		ungetch(c);
	return ret;
}
