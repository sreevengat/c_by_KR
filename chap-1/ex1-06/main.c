/*
	page-16
	EX1-6. Verify that the expression getchar() != EOF is 0 or 1;
*/

#include <stdio.h>


/* copy input to output */
int
main(void){
	
	int c, res;
	
	while ((res=((c=getchar()) != EOF)))
		putchar(c);
	printf("expression getchar() != EOF is %d\n", res);

	return 0;
}
