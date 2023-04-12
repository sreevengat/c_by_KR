/*
	page-107
	EX5-5. Rewrite appropriate programs
	from earlier chapters and exercises
	with pointers instead of array indexing.
	Good possibilities include getline
	(Chapter 1 and 4 ), atoi, itoa and 
	their variants (Chapter 2, 3, and 4),
	reverse (chapter 3), and strindex and 
	getop(Chapter 4).
*/


#include <stdio.h>
#include "getline.h"

#define MAXLINE	1000

double atof(char *s);
void itoa(int n, char *s);

int
main(void){
	
	char s[MAXLINE];
	int n;
	double dn;

	while (1){
		printf("Enter the string: ");
		if ((n = get_line(s, MAXLINE)) > 0){
			printf("getline:%s", s);
			dn = atof(s);
			printf("atof   :%f\n", dn);
			itoa((int)dn, s);
			printf("itoa   :%s\n", s);
		}
		else
			break;
		
	}
	putchar('\n');
	return 0;
}

