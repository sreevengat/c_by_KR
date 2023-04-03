/*
   	page-46
	EX2-3. Write a function htoi(s)
	, which converts a string of 
	h	exadecimal digits (including 
	an optional 0x or 0X) into its
	equivalent integer value.The
	allowable digits are 0 through 9,
	a through f, and A through F
*/

#include <stdio.h>

#define MAXLINE	1000

int get_line(char line[], int maxline);
int htoi(char s[]);

int
main(void){
	
	char line[MAXLINE];
	int loop;
	
	loop=1;
	while (loop){
		printf("Enter hex number : ");
		if (get_line(line, MAXLINE) <= 0)
				loop = !loop;
		else
			printf("%d\n", htoi(line));
	}
	putchar('\n');
	return 0;
}


/* htoi : convert hex to digits */
int 
htoi(char s[]){
	
		int i,c, loop, n;

		n=0;
		loop=1;
		for (i=0; loop &&(c=s[i]) != '\0'; ++i){
			if (!i && c == '0'){
				++i;
				c = s[i];
				if (c == '\0')
					--i;
				else if (c != 'x' &&  c != 'X')
						loop=0;
			}else if (c >= '0' && c <= '9')
				n = 16 * n + (c - '0');
			else if (c >= 'A' && c <= 'F')
				n = 16 * n + (c - ('A' - 10));	 
			else if (c >= 'a' && c <= 'f')
				n = 16 * n + (c - ('a' - 10));
		}
		return n;
}

/* get_line : make a line string from user input */
int 
get_line(char s[], int lim){
	
		int c, i;

		for (i=0; i<lim-1 && (c=getchar()) != '\n' 
				 && c != EOF; ++i)
				s[i] = c;
		if (c == '\n'){
			s[i] =c;
			++i;
		}
		s[i] = '\0';
		return i;
}



