/*
	page-24
	EX1-13. Write a program to print a histogram
	of the lengths of words in its input. It is easy to
	draw the histogram with the bars horizontal; a vertical
	orientation is more challenging 
*/
#include <stdio.h>

#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */
#define YES 1
#define NO 0

int
main(void){
	
	/* assuming no of words is 20 in a line*/

	int c, state, nw,
	print_histo, i, j, 
	word_len, wl,
	nwords[26];		/* no need to zero , because 
						we are assigning value 
						at run time 
					*/

	nw=wl=0;
	word_len=15;		
	print_histo=NO;
	state=OUT;
	while ((c=getchar()) != EOF){
		if (c != ' ' && c != '\n' && c != '\t') /* getting word length */
			++wl;
		if (c == ' ' || c == '\n' || c == '\t'){
			if (state == IN){	/* word ends */	
				state = OUT;
				if (nw < 26){		/* check for no of words within 20 */
					nwords[nw] = wl;
					++nw;
				}
				wl=0;
			}
			if (c == '\n' && nw > 0) /* if newline print histogram */
				print_histo = YES;
		}else if (state == OUT)	/* word starts */
			state = IN;
		if (print_histo == YES){
			print_histo = NO;
			/* printing in horizontal orientation */
			for (i=0; i < nw; ++i){
				for (j=0; j < nwords[i]; ++j)
					putchar('_');
				putchar(' ');
			}
			putchar('\n');
			/* printing in vertical orientation ,
				assume  word len (i.e)row is 15 */
			for (i=0; i < word_len; ++i){
				for (j=0; j < nw; ++j){
					if (nwords[j] != 0){
						putchar('|');
						--nwords[j];
					}else putchar(' ');
					putchar(' ');
				}
				putchar('\n');
			}
			nw=0;
		}
	}
	return 0;
}
