
#include <stdio.h>
#include "sort.h"
#include "lines.h"
#include "qsort.h"

char *lineptr[MAXLINES];	/* pointer to text line */

/* sort input lines */
int
main(void){
	
	int nlines; 	/* number of input lines read */
	
	if ((nlines=read_lines(lineptr, MAXLINES)) >= 0){
		q_sort(lineptr, 0, nlines-1);
		write_lines(lineptr, nlines);
		return 0;
	}else 
		printf("error: input too big to sort \n");

	return 1;
}

