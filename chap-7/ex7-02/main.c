/*
	page-156
	EX7-2. Write a program that will print 
	arbitary input in a sensible way. As a
	minimum , it should print non-graphic
	characters in octal or hexadecimal 
	according to local custom and break long
	text lines.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lines.h"


#define MAXLINE	20

#define HEX	'x'
#define OCT	'0'
#define LOCALCUSTOM HEX


int
main(void){
	
	char line[MAXLINE], *p;
	char fmt[5];

	if (LOCALCUSTOM == HEX)
		strcpy(fmt, "0x%x");
	else if (LOCALCUSTOM == OCT)
		strcpy(fmt, "0%o");
	while (get_line(line, MAXLINE) > 0){
		p = line;
		while (*p){
			if (isalnum(*p))
				putchar(*p);
			else printf(fmt, *p);
			p++;
		}
		putchar('\n');
	}
	putchar('\n');
	
	return 0;
}

