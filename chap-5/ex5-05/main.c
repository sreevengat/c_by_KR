/*
	page-107
	EX5-5. Write versions of the library
	functions strncpy, strncat, and strncmp, 
	which operate on at most the first n
	characters of their argument strings.
	For example strncpy (s,t,n) copies 
	at most n characters of t to s.Full
	descriptions are in Appendix B.
*/


#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "getline.h"
#include "getint.h"

#define MAXLINE	1000

int sncpy(char *s, char *t);
int sncat(char *s, char *t);
int sncmp(char *s, char *t);

int
main(void){
	
	char s[MAXLINE], t[MAXLINE];

	while (1){
		if (sncpy(s, t))
			break;
		if (sncat(s, t))
			break;
		if (sncmp(s, t))
			break;
	}
	putchar('\n');
	return 0;
}

int
sncpy(char *dest, char *src){
	
	int n;

	printf("Enter the string: ");
	if (get_line(src, MAXLINE) > 0){
		printf("Enter the n     : ");
		if (get_int(&n) > 0){
			n=str_ncpy(dest, src, n);
			printf("strncpy:%d:%s\n", n, dest);
		}else return 1;
	}else return 1;
	
	return 0;
}
int
sncat(char *dest, char *src){
	
	int n;

	printf("Enter the string 1: ");
	if (get_line(dest, MAXLINE) > 0){
		printf("Enter the string 2: ");
		if (get_line(src, MAXLINE) > 0){ 
			printf("Enter the n      : ");
			if (get_int(&n) > 0){
				n=str_ncat(dest, src, n);
				printf("strncat:%d:%s\n", n, dest);
			}else return 1;
		}else return 1;
	}else return 1;
	
	return 0;
}
int
sncmp(char *dest, char *src){
	
	int n;

	printf("Enter the string 1: ");
	if (get_line(dest, MAXLINE) > 0){
		printf("Enter the string 2: ");
		if (get_line(src, MAXLINE) > 0){ 
			printf("Enter the n      : ");
			if (get_int(&n) > 0){
				n=str_ncmp(dest, src, n);
				printf("strncmp:%d\n", n);	
			}else return 1;
		}else return 1;
	}else return 1;
	
	return 0;
}
