#include <stdio.h>
#include "char.h"

/* Last in first out */

static char buf[BUFSIZE];	/* buffer for ungetch */
static int bufp=0;			/* next free position in buf */

int 
getch(void){		/* get a (possibly pushed back) character */
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void
ungetch(int c){	/* push character back on input */
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else{
		buf[bufp++] = c;
	}
}
void
ungets(char *s){
	while (*s)
		ungetch(*s++);
}

