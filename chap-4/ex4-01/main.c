/*
	page-71
	EX4-1. Write the function strrindex(s,t)
	which returns the position of the rightmost 
	occurence of t in s, or -1 if there is none
*/


#include <stdio.h>

#define MAXLINE	1000

int get_line(char s[], int lim);
int strrindex(char s[], char t[]);

char pattern[] = "ould";	/* pattern to search for */

int
main(void){
	
	char line[MAXLINE];
	int found=0;

	while (get_line(line, MAXLINE) > 0){
		if (strrindex(line, pattern) != -1){
				printf("%s", line);
				found++;
		}
	}
	return found;
}




