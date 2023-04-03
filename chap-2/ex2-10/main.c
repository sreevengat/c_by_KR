/*
   	page-52
	EX2-10. Rewrite the function lower
	which converts upper case letters
	to lower case , with an conditional
	expression instead of if-else
*/

#include <stdio.h>

#define MAXLINE	1000

unsigned htoi(char s[]);
int get_line(char line[], int max);
int lower(int c);

int
main(void){
		
		int  loop, i, c;
		char line[MAXLINE];
		
		loop=1;
		while (loop){
			printf("Enter string: ");
			i=0;
			if (get_line(line, MAXLINE) > 0)
				while ((c=line[i++]) != '\0')
					putchar(lower(c));
			else 
				loop=0;
		}
		putchar('\n');
	return 0;
}

/* lower : upper case to lower case*/
int
lower(int c){
	return (c >= 'A' && c <= 'Z') ? c+32 : c;
}
/* get_line: get line from user input char */
int 
get_line(char s[], int lim){
	
	int i, c;

	for (i=0; i < lim-1 && ((c=getchar()) != '\n')
					&& c != EOF ; i++)
			s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

