/*
	page-24
	EX1-14. Write a program to print
	histogram of frequencies of different 
	characters in its input
*/

#include <stdio.h>

int
main(void){
	
	int c, i, j,others,
	lower[26],
	upper[26],
	digit[10];

	for (i=0; i < 26; i++)
		lower[i] = upper[i] = 0;
	for (i=0; i < 10; i++)
		digit[i] = 0;

	others = 0;
	while ((c=getchar()) != EOF){
		if (c >= '0' && c <= '9')
			++digit[c - '0'];
		else if (c >= 'a' && c <= 'z')
			++lower[c-'a'];
		else if (c >= 'A' && c <= 'Z')
			++upper[c-'A'];
		else
			++others;
	}
	for (i=0, c='0'; i < 10; ++i,++c){
		printf("%c:",c);
		for (j=0; j < digit[i]; ++j)
			putchar('#');
		putchar('\n');
	}

	for (i=0, c='A'; i < 26; ++i,++c){
		printf("%c:",c);
		for (j=0; j < upper[i]; ++j)
			putchar('#');
		putchar('\n');
	}
	for (i=0, c='a'; i < 26; ++i,++c){
		printf("%c:",c);
		for (j=0; j < lower[i]; ++j)
			putchar('#');
		putchar('\n');
	}	
	printf("others:%d\n", others);


	
	return 0;
}
