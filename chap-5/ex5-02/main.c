/*
	page-98
	EX5-2. Write getfloat,the floating
	point analog of getint. What type
	does getfloat return as its 
	function value
*/

/*Ans: return type is int */

#include <stdio.h>
#include <ctype.h>
#include "getfloat.h"

int
main(void){
	
	double n;

	while (1){
		printf("Enter the number: ");
		if (get_float(&n) > 0)
			printf("%f\n", n);
		else {
			putchar('\n');
			break;
		}
		n=0;
	}

	return 0;
}

