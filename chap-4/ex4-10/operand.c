#include <stdio.h>
#include <ctype.h>

#define MAXLINE	100

#define NUMBER	'0'
#define ALPHA	'A'
#define VARIABLE 'V'

int inc=0;
char line[MAXLINE];

int get_line(char s[], int lim);

/* getop: get next operator or numeric operand */
int
getop(char s[]){
	
	int i, c, ret;
	
	if (line[inc] == '\n'){
		inc=0;
		return '\n';
	}else if (line[inc] == '\0')
		inc = 0;
	if (!inc){
		if (!(get_line(line, MAXLINE) > 0))
			return EOF;
	}	
	i=0;
	/* skip white spaces */
	while ((s[i] = c = line[inc++]) == ' ' ||
			c == '\t')
		;
	s[1] = '\0';
	if (!isalnum(c) && c != '.' 
				&& c != '=' && c != '$'
				&& c != '?'){	/* = for assign to var, $ for get var value, ? print var value */
		if (c == '-' || c == '+'){ /* handle sign */
			c=line[inc++];
			if (isdigit(c)){
				s[++i] = c;
				goto HERE;
			}else {
				inc--;
				c = s[0];
			}
		}
		return c;	/* not a number */
	}
	if (c == '=' || c == '$' || c == '?'){
		while (!(isspace(s[++i] = c = line[inc++])))
				;
		ret = VARIABLE;
	}else if (isalpha(c)){	/* collect alphabets */
	while (isalpha((s[++i] = c = line[inc++])))
				;
		if (isspace(s[1])){
			inc--;
			return s[0];
		}
		ret = ALPHA;
	}else if (isdigit(c)){	/* collect integer part */
HERE:	while (isdigit(s[++i] = c = line[inc++]))
			;
		if (c == '.')	/* collect fractional part */
			while (isdigit((s[++i] = c = line[inc++])))
				;
		ret = NUMBER;
	}
	s[i] = '\0';
	inc--;
	return ret;
}
