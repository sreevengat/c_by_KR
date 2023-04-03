/*
 	[ from get_line fun]
		for (i=0; i<lim-1 && (c=getchar()) != '\n' 
			&& c != EOF; ++i)
			s[i] = c;
   	page-41
	EX2-2.Write a loop equivalent to 
	the for loop above without using
	&&  or ||
*/

#include <stdio.h>

#define MAXLINE	1000

int get_line(char line[], int maxline);

int
main(void){
	
	int len;
	char line[MAXLINE];

	while ((len=get_line(line, MAXLINE)) > 0)
			printf("%d:%s", len, line);

	return 0;
}

int 
get_line(char s[], int lim){
	
		int c, i, loop;

		i=0;
		loop=1;
		while (loop){
			c = getchar();
			if (c == EOF)
				loop=!loop;
			else if (i < lim-1){
				--lim;
				if (c == '\n')
					loop=!loop;
				s[i] = c;
				++i;
			}else loop=!loop;
		}	
		s[i] = '\0';
		return i;
}



