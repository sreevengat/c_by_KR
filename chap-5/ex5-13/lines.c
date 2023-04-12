#include <stdio.h>
#include "lines.h"
#include "alloc.h"
#include "string.h"
#include "tail.h"


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
/* read_lines: read input lines */
int
read_lines(char *lineptr[], int maxlines, char *linebuf, int bufsize){
	
	int len, nlines;
	char *p;

	nlines=0;
	p = linebuf;
	while ((len = get_line(p, MAXLEN)) > 0)
		if (nlines >= maxlines || p >= (linebuf + bufsize) )
			return -1;
		else {
			p += --len;
			*p++ = '\0';	/* delete newline */
			lineptr[nlines++] = p-len-1;				
		}
	return nlines;
}
/* writelines: write output lines */
void
write_lines(char *lineptr[], int nlines){
	
	int i;

	for (i=0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}


