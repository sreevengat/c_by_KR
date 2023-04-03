/*
	page-31
	EX1-18. Write a program to remove trailing blanks 
	and tabs from each line of input and to delete entirely
	blank lines
*/

#include <stdio.h>

#define MAXLINE	1000	/* maximum input line size */

int get_line(char line[], int maxline);
int remove_blanks(char line[], int len);

int
main(void){
	
	int len;			/* current line length */
	char line[MAXLINE]; /* current input line */

	while ((len=get_line(line, MAXLINE)) > 0)
		if ((len=remove_blanks(line, len)) > 1)
			printf("%4d:%s", len, line);
	return 0;
}

/* remove_blanks: remove trailing blanks and tabs
	and delete entirely blank lines */
int 
remove_blanks(char line[], int len){
	
	int i;

	/* move to the end of the line */
	i = len - 2;
	while ((i >= 0) && (line[i] == ' ' || line[i] == '\t'))
		i--;
	i++;
	line[i] = '\n';
	i++;
	line[i] = '\0';
	return i;
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


