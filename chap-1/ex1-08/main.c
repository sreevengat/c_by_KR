/*
	page-20
	EX1-8. Write a program to count blanks, tabs, and newlines
*/

#include <stdio.h>


int
main(void){
	
	int bk, tb, nl, c;

	bk=0;
	tb=0;
	nl=0;
	
	while ((c = getchar()) != EOF){
		if (c == ' ')
			++bk;
		if (c == '\t')
			++tb;
		if (c == '\n')
			++nl;
	}
	printf("blanks=%d, tabs=%d, newlines=%d\n", bk, tb, nl);
	return 0;
}
