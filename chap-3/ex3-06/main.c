/*
	page-65
	EX3-6. Write a version of itoa that
	accepts three arguments instead of two
	. The third argument is a minimum field 
	width ; the converted number must be padded
	with blanks on the left if necessary to make
	it wide enough
*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BIN	2
#define OCT	8
#define DEC	10
#define HEX	16

int itob(signed int n, char s[], int base, int pad);
void reverse(char s[]);
int get_line(char s[], int lim);
int atoi(char s[]);
int itoa(signed int n, char s[], int pad);


int
main(void){
	
	char line[50];
	int loop, pad, n;
	
	loop=1;
	while (loop){
		printf("Enter the digits in dec  : ");
		if (get_line(line, 50) > 0){
				n = atoi(line);
				printf("Enter the padding in dec : ");
				if (get_line(line, 50) > 0){
					pad = atoi(line);
					itoa(n, line, pad);
					printf("%s\n", line);
				}else loop=0;
		}else loop=0;
	}
	printf("\nEOF\n");
	return 0;
}

/* itoa: convert n to characters in s */
int
itoa(signed int n, char s[], int pad){
	return itob(n, s, DEC, pad);
}

/* itob: convert n to characters in s, witn base */
int
itob(signed int n, char s[], int base, int pad){
	
	if (base != BIN && base != OCT 
			&& base != DEC && base != HEX)
			return -1;

	int i, sign;
	unsigned int v;

	if (((sign=n) < 0) && base == DEC)
		v=-n;
	else 
		v = n;
	i=0;
	do {				/*generate digits in reverse order*/
		n = v % base;
		if (n >= 10 && n <= 15)
			n += 87; 				/* for hex chars */
		else
			n += '0';
		s[i++] = n;
	}while ((v/=base) > 0); /* delete it */

	switch (base){
		case BIN:	
			s[i++] = 'b';
			s[i++] = '0';
			break;
		case OCT:
			s[i++] = '0';
			break;
		case HEX:
			s[i++] = 'x';
			s[i++] = '0';
			break;
		default:
			if (sign < 0)
			s[i++] = '-';
			break;
	}
	pad = pad - i;
	if (pad > 0)
		while (pad-- > 0)
			s[i++] = ' ';
	s[i]='\0';
	reverse(s);
	return 0;
}
/* atoi : convert ascii to integer */
int 
atoi(char s[]){
	
		int i, n, sign;
	
		for (i=0; isspace(s[i]); i++)	/* skip white space */
				;
		sign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '-' || s[i] == '+')
				i++;
		for (n=0; isdigit(s[i]); i++)
				n = 10 * n + (s[i] - '0');
		return sign * n;
}

/* reverse : reverse the s  */
void
reverse(char s[]){
	
	int i, j, tmp;

	for (i=0,j=strlen(s)-1; i < j; ++i,--j){
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
	
}
/* get_line: get line from user input char */
int 
get_line(char s[], int lim){
	
	int i, c;

	for (i=0; i < lim-1 && ((c=getchar()) != '\n')
			&& c != EOF ; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

