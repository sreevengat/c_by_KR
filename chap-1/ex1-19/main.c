/*
	page-31
	EX1-19. write a function reverse(s) that reverses 
	the character string s. Use it to write a program 
	that reverses its input a line at a time
*/

#include <stdio.h>

#define MAXLINE	1000	/* maximum input line size */

int get_line(char line[], int maxline);
void reverse(char s[]);

int
main(void){
	
	int len;			/* current line length */
	char line[MAXLINE]; /* current input line */

	while ((len=get_line(line, MAXLINE)) > 0){
			reverse(line);
			printf("%s",line);
	}
	return 0;
}


/* reverse : reverse the string */
void
reverse(char s[]){
	
	int len, i, j, c;

	len=0;
	while (s[len] != '\0')	/* get length of the string */
		++len;
	for (i=0, j=len-2; i < j; ++i,--j){ /* len -2 for skip newline and '\0'*/
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

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


