/*
	page-34
	EX1-22. Write a program to "fold" long 
	input lines into two or more shorter 
	lines after the last non-blank character
	that occurs before the n-th column of
	input.Make sure your program does 
	something intellignet with very long
	lines, and if there are no blanks or 
	tabs before the specified column.

*/

#include <stdio.h>

#define MAXLINE 	1000
#define FOLDLENGTH	9


int get_line(void);
void fold_line(void);

char line[MAXLINE];

int
main(void){
		
	while (get_line() > 0)
			fold_line();
	return 0;
}

/* fold_line: fold long line into two or more lines*/
void
fold_line(void){
	
	extern char line[];
	char fold[FOLDLENGTH];
	int i, j, k, c;
	
	i=j=0;
	while ((c=line[i]) != '\0'){
		++i;
		if (c == '\n'){	
			fold[j] = '\0';
			printf("%s\n", fold);
		}else if (j < FOLDLENGTH){	
			fold[j] = c;
			++j;
		}else {
			--i;			
			fold[j] = '\0';	
			c = fold[j-1];
			if (c != ' ' && c != '\t'){	
				k=j-1;
				while (k >=0 && fold[k] != ' ' && fold[k] != '\t')
					--k;
				if (k >= 0){	
					fold[k] = '\0';
					i = i-(FOLDLENGTH-k)+1;	
				}
			}
			j=0;
			printf("%s\n", fold);
		}	
	}

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

