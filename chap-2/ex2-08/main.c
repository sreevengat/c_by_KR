/*
   	page-50
	EX2-8. Write a function rightrot(x, n),
	that returns the value if the integer
	rotated to right by n positions
*/

/* 
 * bit pos p starts from 0,..n 
 * example p=3, n=4
 * pos 7654 3210        
 * x=0b1111 0101 	
 * r=0b1111 1010
 */

#include <stdio.h>

#define MAXLINE	1000

unsigned htoi(char s[]);
int get_line(char line[], int max);
unsigned right_rot(unsigned x, int n);
int sizeof_unsigned(void);
	
int
main(void){
		
		unsigned r,x;
		int  n, loop;
		char line[MAXLINE];
		
		loop=1;
		while (loop){
			printf("Enter x value in hex: ");
			if (get_line(line, MAXLINE) > 0){
				x = htoi(line);
				printf("Enter n bits in hex : ");
				if (get_line(line, MAXLINE) > 0){
					n=htoi(line);
					r = right_rot(x, n);
					printf("Result              : 0x%x\n", r);
					printf("x=%32b\n", x);
					printf("r=%32b\n", r);
				}else loop=0;
			}else loop=0;
		}
		putchar('\n');
	return 0;
}

/* right_rot: rotate n bits to the right */
unsigned
right_rot(unsigned x, int n){
	
	int i;
	int nbits = (sizeof_unsigned() * 8) - 1;
	
	for (i=0; i < n; ++i){
		if (x & 0x01U)
			x = x | (1 << nbits);	
		x = x >> 1;
	}
	return x;
}
/* sizeof_unsigned : return n bytes of unsigned */
int 
sizeof_unsigned(void){
	
	unsigned x;
	int i;

	x = ~0;
	i=0;
	while (x){
		x=x/2;
		i++;
	}
	return i/8;
}
/* htoi : convert hex to integer */
unsigned 
htoi(char s[]){
	
		int i,c, loop;
		unsigned n;

		n=0;
		loop=1;
		for (i=0; loop &&(c=s[i]) != '\0'; ++i){
			if (!i && c == '0'){
				++i;
				c = s[i];
				if (c == '\0')
					--i;
				else if (c != 'x' &&  c != 'X')
						loop=0;
			}else if (c >= '0' && c <= '9')
				n = 16 * n + (c - '0');
			else if (c >= 'A' && c <= 'F')
				n = 16 * n + (c - ('A' - 10));	 
			else if (c >= 'a' && c <= 'f')
				n = 16 * n + (c - ('a' - 10));
		}
		return n;
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

