#include <stdio.h>
#include "lines.h"

/* get_line: ptr version, getline into s, return length */
int
get_line(char *s, int lim){
	
	char *p=s;
	int c;

	while (--lim > 0 &&	(c=getchar()) != EOF && c != '\n')
		*p++ = c;	
	if (c=='\n')
		*p++=c;
	*p='\0';
	return p-s;
}

