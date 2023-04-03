/*
	page-34
	EX1-23. Write a program to remove all
	comments from a C program , Dont forget 
	to handle quoted strings and character 
	constants properly. C comments do not
	nest /

*/

#include <stdio.h>

#define MAXLINE 1000

int get_line(void);

char line[MAXLINE];

int
main(void){
	
	int i, c, error, is_true, line_no;
	int loop;

	error=0;
	line_no=0;
	is_true=1;
	while (is_true==1 && (get_line() > 0) ){
		++line_no;
		for (i=0; (c=line[i]) != '\0' && is_true==1; ++i){ /* handle character or string constant */
			if (c == '\''){
				putchar(c);
				++i;
				c=line[i];
				if (c =='\0')
						--i;
				else 
						putchar(c);
				++i;
				c=line[i];
				if (c == '\0')
					--i;
				if (c != '\'')
						error=2;
				else putchar(c);

			}else if (c == '"'){	
				putchar(c);
				++i;
				while ((c=line[i]) && c != '"' && c != '\0'){ /* should be within the line */
					++i;
					putchar(c);
				}
				if (c == '\0') 
					--i;	
				if (c != '"')
						error=3;
				else 
					putchar(c);
			}else if (c == '*')	/* handle comments */
				error=1;
			else if (c == '/'){
				++i;
				c=line[i];
				error=1;
				if (c == '*') {
					loop=1;
					while (loop==1 && (c=line[i]) != EOF){
						if (c == '/'){
							if (line[i-1] == '*'){ /* check for comment ends */
									error=0;		
									loop=0;
							}
						}
						if (c == '\n'){	/* get next line */
							i=0;
							if (get_line() <= 0){ /* line over, end all the loops*/
								is_true=0;
								loop=0;
							}else ++line_no;
						}else ++i;
					}
				}
			}else {
				if (error == 0)
					putchar(c);
			}
			if (error > 0)
				is_true=0;
		}
	}
	if (error==1)
		printf("\nError:%d:comment", line_no);
	else if (error==2)
		printf("\nError:%d:character constant", line_no);
	else if (error==3)
		printf("\nError:%d:string constant", line_no);
	putchar('\n');
	return 0;
}

/* get_line : specialized version , using global variables*/
int 
get_line(void){

	extern char line[];
	int i, c;

	for (i=0; i < MAXLINE-1
		&& (c=getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n'){
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

