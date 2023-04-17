#include <ctype.h>
#include <stdio.h>
#include "getword.h"
#include "char.h"

/* getword: get next word or character from input */
int
get_word(char *word, int lim){
	
	int c, cmt, pp;
	char *w=word;
	
	cmt=pp=0;
	while (isspace(c=getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)){
		if (c != '_' && c != '"'  && c != '/' && c != '#'){
			*w = '\0';
			return c;
		}
	}
	if (c == '/'){
		cmt=1;
		c = getch();
		if (c != '*'){
			ungetch(c);
			return c;
		}
		*w++ = c;
		lim--;
	}else if (c == '#')
		pp=1;
	for (; --lim > 0; w++){
		*w = getch();
		if (cmt){
			if (*w == '*'){
				cmt=2;
			}else if (cmt == 2){
				if (*w == '/'){
					w++;
					break;
				}
			}
		}else if (pp){
			if (*w == '\n')
				break;
		}else if (!isalnum(*w)){
			if (*w != '_' && *w != '"'){
				ungetch(*w);
				break;
			}
		}
	}
	/*for (; --lim > 0; w++)
		if (!isalnum(*w = getch())){
			if (*w != '_' && *w != '"' ){
				ungetch(*w);
				break;
			}
		}*/
	*w = '\0';
	return word[0];
}
