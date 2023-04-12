/*
	page-121
	EX5-17. Add a field handling capability
	,so sorting may be done on fields within 
	lines, each field sorted according to 
	an independent set of options .(The
	index for this book was sorted with -df 
	for the index category and -n for the 
	page numbers.
*/

/* Ans: use -k option for field */

#include <stdio.h>
#include "qsort.h"
#include "string.h"
#include "lines.h"
#include "sort.h"
#include "atof.h"

static char *lineptr[MAXLINES];		/* pointers to text lines */


int sort_flag, field_pos;

/* sort input lines */
int
main(int argc, char *argv[]){
	
	int nlines;		/* number of input lines read */
	char *t;
	char *p=*argv;


	while (--argc > 0){
		t = *++argv;
		if (str_cmp(t, "-n") == 0)
			sort_flag |= SORT_FLAG_NUMERIC;
		else if(str_cmp(t, "-r") == 0)
			sort_flag |= SORT_FLAG_REVERSE;
		else if (str_cmp(t, "-f") == 0)
			sort_flag |= SORT_FLAG_FOLD;
		else if (str_cmp(t, "-d") == 0)
			sort_flag |= SORT_FLAG_DIRORD;
		else if (str_cmp(t, "-k") == 0){
			sort_flag |= SORT_FLAG_FIELDSORT;
			--argc;
			if (!argc)
				field_pos = 0;
			else 
				field_pos = (int)atof(*++argv);
		}else {
			printf("Usage: %s -n -r -f -d -k n \n", p);
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
