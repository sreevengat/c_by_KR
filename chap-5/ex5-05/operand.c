#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int
getop(char s[]){
	
	int i, c, ret;
	static int prev_char;

	i=0;
	do {
		if (prev_char != 0){
			s[i] = c = prev_char;
			prev_char = 0;
		}else 
			s[i] = c = getch();
	}while(c == ' ' || c == '\t');
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
				prev_char = c;
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
	/* push back the character , includeing EOF */
	prev_char = c;
	return ret;
}
