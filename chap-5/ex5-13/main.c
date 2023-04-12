/*
	page-118
	EX5-13. Write the program tail, 
	which prints the last n lines of
	its input. By default , n is 10,
	let us say, but it changed by an 
	optional argument ,so that 
	tail -n
	prints the last n lines. The program
	should behave rationally no matter 
	how unreasinable the input or the 
	value of n. Write the program so 
	it makes the best use of available 
	storage.lines should be stored as 
	in the sorting program of section 
	5.6 , not in two-dimensional array of 
	fixed sized.
*/


#include <stdio.h>
#include "tail.h"
#include "atof.h"
#include "lines.h"

static char *lineptr[MAXLINES];
static char linebuf[BUFSIZE];

int
main(int argc, char *argv[]){
	
	int n;
	char *t = *argv;

	n = NTAIL;
	if (argc > 1){
		while (--argc > 0)
			if ((*++argv)[0] == '-')
				n = (int)atof(++*argv);
			else {
				printf("Usage: %s -n\n", t);
				return 1;
			}
	}
	
	int nlines;	
	if ((nlines=read_lines(lineptr, MAXLINES, linebuf, BUFSIZE)) >=0 ){
		if (nlines < n){
			n=nlines;
			nlines=0;
		}else 
			nlines = nlines-n;
		while (n--)
			printf("%s\n", lineptr[nlines++]);
	}else {
		printf("error: line is too long\n");
		return 1;
	}
	return 0;
}
