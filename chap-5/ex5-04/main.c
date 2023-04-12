/*
	page-107
	EX5-4. Write a function 
	strend(s,t) ,which return 1
	if the string t occurs at the
	end of the string s, and zero 
	otherwise
*/


#include <stdio.h>
#include "string.h"
#include "getline.h" 

#define MAXLINE	1000


int
main(void){
	
	char s[MAXLINE], t[MAXLINE];
	
	while (1){
		printf("Enter the string 1: ");
		if (get_line(s, MAXLINE) > 0){
			printf("Enter the string 2: ");
			if (get_line(t, MAXLINE) > 0){
				printf("strend: %d\n", str_end(s,t));
			}else break;
		}else break;
	}
	putchar('\n');
	return 0;
}

