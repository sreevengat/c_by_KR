/*
   	page-50
	EX2-7. Write a function invert(x, p, n) that
	returns x with the n bits that begin at
	position p inverted(i.e 1 changed to 0 and
	vice versa), leaving the others unchanged
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

unsigned set_bits(unsigned x, int p,int n, unsigned y);	
unsigned invert(unsigned x, int p, int n);
unsigned htoi(char s[]);
int get_line(char line[], int max);
	
int
main(void){
		
		unsigned r,x;
		int p, n, loop;
		char line[MAXLINE];
		
		loop=1;
		while (loop){
			printf("Enter x value in hex: ");
			if (get_line(line, MAXLINE) > 0){
				x = htoi(line);
				printf("Enter bit pos in hex: ");
				if (get_line(line, MAXLINE) > 0){
					p = htoi(line);
					printf("Enter n bits in hex : ");
					if (get_line(line, MAXLINE) > 0){
						n=htoi(line);
						r = invert(x, p, n);
						printf("Result              : 0x%x\n", r);
						printf("x=%32b\n", x);
						printf("r=%32b\n", r);
					}else loop=0;
				}else loop=0;
			}else loop=0;
		}
		putchar('\n');
	return 0;
}
/* invert : invert n  bits from pos */
unsigned
invert(unsigned x, int p, int n){
	return set_bits(x, p, n, ~x);
}
/* set_bits : set n bits to x from pos in y */
unsigned 
set_bits(unsigned x, int p,
					int n, unsigned y){			
	unsigned mask = (~(~0 << n)) << (p+1-n);
	return (x & ~mask) | (y & mask);	
}
/* htoi : convert hex to digits */
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

