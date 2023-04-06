/*
	page-88
	EX4-12 . Adapt the ideas of 
	printd to write a recursive 
	version of itoa. 
	that is convert an integer into
	a string by calling recursive
	routine
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE	100

void itoa(int, char s[]);
int get_line(char s[], int lim);

int
main(void){
	
	char s[MAXLINE], num[50];
	int n;

	while(1){
		printf("Enter the number: ");
		if (!(get_line(s, MAXLINE) > 0)){
			printf("\nEOF\n");
			break;
		}
		n = (int)atof(s);
		itoa(n, num);
		printf("%s\n", num);
	}
	return 0;
}

