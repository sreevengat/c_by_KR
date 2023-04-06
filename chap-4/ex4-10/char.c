#include <stdio.h>

#define BUFSIZE	1

/* Last in first out */

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp=0;			/* next free position in buf */
int eof=0;			/* check for EOF */

int 
getch(void){		/* get a (possibly pushed back) character */
	int c;

	if (!eof){
		c = (bufp > 0) ? buf[--bufp] : getchar();
		if (c == EOF)
			eof=1;
	}
	else c = EOF;
	return c;
}

void
ungetch(int c){	/* push character back on input */
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else 
		buf[bufp++] = c;
}
