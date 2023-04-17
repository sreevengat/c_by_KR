/*
	page-145
	EX6-6. Implement a simple version of
	the #define processor(i.e.., no arguments)
	suitable for use with C programs, based on
	the routines of this section. You may
	also find getch and ungetch helpful.
*/

#include <stdio.h>
#include "preprocess.h"

#define IN	1
#define OUT	0

int
main(void){
	
	preprocess();
	
	return 0;
}


