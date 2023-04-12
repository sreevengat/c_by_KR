/*
	page-98
	EX5-1. As Written, get int treats a 
	+ or - not followed by a digit as a
	valid representation of zero. Fix
	it to push such a character back on
	the input.
*/

#include <stdio.h>
#include <ctype.h>
#include "getint.h"

int
main(void){
	
	int n;

	while (1){
		printf("Enter the number: ");
		if (get_int(&n) > 0)
			printf("%d\n", n);
		else{	putchar('\n');
				break;
		}
		n=0;
	}
	return 0;
}

