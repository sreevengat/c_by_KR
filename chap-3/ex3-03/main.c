/*
	page-63
	EX3-3. Write a function expand 
	(s1,s2) that expands shorthand 
	notations like a-z in the 
	string s1 into the equivalent 
	complete list abc..xyz in s2. 
	Allow for letters of either 
	case and digits, and be 
	prepared to handle cases like
	a-b-c and a-z0-9 and -a-z.
	Arrange that a leading or 
	trailing - is taken literally

*/


#include <stdio.h>

#define MAXLINE		1000
#define SHORTLINE	100

int get_line(char s[], int lim);
void expand(char s1[], char s2[]);
	
int
main(void){
	
	int loop;
	char sline[MAXLINE];
	char eline[SHORTLINE]; /* big enough to hold expand char */

	loop=1;
	while (loop){
		printf("Enter short hand notation : ");
		if (get_line(sline, SHORTLINE) > 0){
			expand(sline, eline);
			printf("%s\n", eline);
		}else {
				printf("\nEOF\n");
				loop=0;
		}
	}
	return 0;
}

/* expand : convert shorthand notation
 * from s1 to s2
 */
void 
expand(char s1[], char s2[]){
	
	int i, j, c, s, prev;

	j=i=0;
	while ((c=s1[i++]) != '\0'){
		if (c != '\n' && c != '-')
			s2[j++]=c;
		if (prev == '-'){
			if (j > 1){
				--j;
				s = s2[j-1]+1;
				while (s <= c)
					s2[j++] = s++;
			}
		}
		prev=c;
	}
	s2[j]='\0';
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



