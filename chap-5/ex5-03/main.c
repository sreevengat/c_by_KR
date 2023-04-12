/*
	page-107
	EX5-3. Write a pointer version
	of function strcat that we showed 
	in chapter 2. strcat(s,t) copies
	that string t to the end of s
*/

/*Ans: return type is int */

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
				str_cat(s, t);
				printf("strcat: %s", s);
			}else break;
		}else break;
	}
	putchar('\n');
	return 0;
}

