/*
	page-8
	EX1-2.Experiment to find out what happens when 
	printf's argument string contains \c, where
	c is some character other than \n,\t,\b,\",\\
*/

/*
	Ans : some chars are printing and
	some others gives error
*/
#include <stdio.h>

int
main(void){
	
	printf("hello, ");
	printf("world\s"); 
	printf("\n");
	return 0;
}
