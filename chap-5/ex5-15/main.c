/*
	page-121
	EX5-15. Add the option -f to fold
	upper and lower case together, so
	that case distinctions are not made
	during sorting. for example a and A
	compare equal
*/

#include <stdio.h>
#include "qsort.h"
#include "string.h"
#include "lines.h"
#include "sort.h"

static char *lineptr[MAXLINES];		/* pointers to text lines */


int sort_flag;

/* sort input lines */
int
main(int argc, char *argv[]){
	
	int nlines;		/* number of input lines read */
	char *t;
	char *p = *argv;

	while (--argc > 0){
		t = *++argv;
		if (str_cmp(t, "-n") == 0)
			sort_flag |= SORT_FLAG_NUMERIC;
		else if(str_cmp(t, "-r") == 0)
			sort_flag |= SORT_FLAG_REVERSE;
		else if (str_cmp(t, "-f") == 0)
			sort_flag |= SORT_FLAG_FOLD;
		else{
			printf("Usage: %s -n -r -f\n", p);
			return 1;
		}
	}
	if ((nlines=read_lines(lineptr, MAXLINES)) >= 0){
		qsort((void **)lineptr, 0, nlines-1, 
					(int (*)(void *, void *))((sort_flag & SORT_FLAG_NUMERIC)? num_cmp : str_cmp));
		write_lines(lineptr, nlines);
		return 0;
	}else {
		printf("input too big to sort \n");
		return -1;
	}

	return 0;
}
