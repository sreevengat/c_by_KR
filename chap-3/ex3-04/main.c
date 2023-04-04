/*
	page-65
	EX3-4. In a two's complement 
	number representation , our 
	version of itoa does not handle
	the largest negative number ,
	that is, the value of n equal 
	to -(2 pow wordsize-1). Explain why not.
	Modify it to print the value correctly,
	regardless of the machine on which it runs
*/

/*
 * Ans : Because, for example data type 
 * char, largest negative value is -128,
 * and largest positive value is 127.
 * in our itoa function , we change negative
 * to positive (i.e) -128 to 128, so it can't
 * handle.solution is use unsigned char, which
 * will handle upto 255, this applies to all
 * data type
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(signed int n, char s[]);
void reverse(char s[]);


int
main(void){
	
	char s[50];	
	
	printf("Largest negative number \n");
	printf("From std header : %d\n", INT_MIN);
	itoa(INT_MIN, s);
	printf("From itoa       : %s\n", s);

	return 0;
}

/* itoa: convert n to characters in s */
void
itoa(signed int n, char s[]){

	int i, sign;
	unsigned v;

	v = ((sign=n) < 0) ? -n : n;
	i=0;
	do {	/*generate digits in reverse order*/ 
		s[i++] = v % 10 + '0';	/* get next digit */
	}while ((v/=10) > 0);		/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i]='\0';
	reverse(s);
}

void
reverse(char s[]){
	
	int i, j, tmp;

	for (i=0,j=strlen(s)-1; i < j; ++i,--j){
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
	
}



