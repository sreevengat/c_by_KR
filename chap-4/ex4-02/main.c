/*
	page-73
	EX4-2. Extend atof to handle scientific 
	notation of the form 123.45e-6 where a
	floating-point number may be followed
	by e or E and an optionally signed exponent
*/


#include <stdio.h>

#define MAXLINE	1000

int get_line(char s[], int lim);
double atof(char s[]);

int
main(void){
	
	char line[MAXLINE];

	while (1){
		printf("Enter exponent float number : ");
		if (get_line(line, MAXLINE) > 0)
			printf("%f\n", atof(line));
		else break;
	}
	printf("\nEOF\n");
	return 0;
}




