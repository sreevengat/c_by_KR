/*
   	page-51
	EX2-9.In a two's complement number 
	system, x &= (x-1) deletes the right-
	most 1-bit in x. Explain why. Use
	this observation to write a faster 
	version of bitcount
*/

/*
 	Ans : for any given number other than zero
	there is atleadt one 1-bit, because of 
	binary format when we Anding the number 
	with minus that number, the number is 
	decrementing fastly.

 */

#include <stdio.h>

#define MAXLINE	1000

unsigned htoi(char s[]);
int get_line(char line[], int max);
int bitcount(unsigned x);

int
main(void){
		
		unsigned r,x;
		int  loop;
		char line[MAXLINE];
		
		loop=1;
		while (loop){
			printf("Enter x value in hex: ");
			if (get_line(line, MAXLINE) > 0){
				x = htoi(line);
				r = bitcount(x);
				printf("Result              : 0x%x\n", r);
				printf("x=%32b\n", x);
				printf("r=%32b\n", r);
			}else loop=0;
		}
		putchar('\n');
	return 0;
}

/* bitcount:counts number of 1-bits */
int
bitcount(unsigned x){

	int b;

	for (b=0; x != 0; x &= (x-1))
			b++;
	return b;
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

