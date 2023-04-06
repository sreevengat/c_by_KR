/*
	page-88
	EX4-13 . Write a recursive version
	of the function reverse(s), which 
	reverse the string s in place
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE	100

void reverse(char s[]);
int get_line(char s[], int lim);

int
main(void){
	
	char s[MAXLINE];

	while(1){
		printf("Enter the number: ");
		if (!(get_line(s, MAXLINE) > 0)){
			printf("\nEOF\n");
			break;
		}
		reverse(s);
		printf("%s", s);
	}
	return 0;
}

