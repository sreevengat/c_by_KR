/*
	page-111
	EX5-7. Rewrite readlines to 
	store lines in an array supplied
	by main, rather than calling alloc to 
	maintain storage. How much faster is the
	program?
*/


#include <stdio.h>
#include "qsort.h"
#include "sort.h"
#include "lines.h"

static char *lineptr[MAXLINES];	/* pointer to text line */
static char linebuf[BUFSIZE];		/* buffer for text lines */
/* sort input lines */
int
main(void){
	
	int nlines;		/* number input lines read */
	
	if ((nlines=read_lines(lineptr, MAXLINES, linebuf, BUFSIZE)) >= 0){
		q_sort(lineptr, 0, nlines-1);
		write_lines(lineptr, nlines);
		return 0;
	}else 
		printf("error: input too big to sort \n");
	
	return 0;
}

