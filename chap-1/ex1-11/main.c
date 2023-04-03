/*
	page-21
	EX1-11. How would you test the word count program?
	What kinds of inputs are most likely to uncover bugs
	if there are any
*/

/*
	1.5.4 Word counting from book
*/


/*
	Ans: There is no bugs, for alpha numeric input, 
	and is counts correctly, for special characters
	like #,.& it count as a word
*/
#include <stdio.h>

#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */


/* count lines, words and characters in input */
int
main(void){
	
	int c , nl, nw, nc, state;

	state  = OUT;
	nl=nw=nc=0;
	while ((c=getchar()) != EOF){
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT){
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
	return 0;
}
