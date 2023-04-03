/*
	page-31
	EX1-16. Revise the main routine of the longest-line 
	program so it will correctly print the length of arbitrarily 
	long input lines, and as much as possible of the text
*/

#include <stdio.h>

#define MAXLINE	1000	/* maximum input line size */

int get_line(char line[], int maxline);

int
main(void){
	
	int len;	/* current line length */
	int max;	/* maximum length seen so far */
	char line[MAXLINE]; /* current input line */

	max = 0;
	while ((len=get_line(line, MAXLINE)) > 0)
		if (len > max){
			printf("%d:%s", len, line);
			max = len;
		}
	return 0;
}

/* getline: read a line into s, return length */
int
get_line (char s[], int lim){
	
	int c, i;

	for (i=0; i<lim-1 && (c=getchar()) != EOF && 
							c != '\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

