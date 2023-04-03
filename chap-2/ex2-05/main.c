/*
   	page-48
	EX2-5. Write a function any(s1, s2), which
	returns the first location in the string
	s1 where any character from the string s2
	occurs, or -1 if s1 contains no characters
	from s2. (The standard library function
	strpbrk does tha same job but returns a
	pointer to the location.
*/

#include <stdio.h>

#define MAXLINE	1000

int get_line(char line[], int maxline);
int any(char s1[], char s2[]);

int
main(void){
	
	char str1[MAXLINE], str2[MAXLINE];
	int loop, pos;

	loop=1;
	while (loop){
		printf("Enter string 1 : ");
		if (get_line(str1, MAXLINE) > 0){
			printf("Enter string 2 : ");
			if (get_line(str2, MAXLINE) > 0){
				pos=any(str1, str2);
				if (pos >= 0)
					printf("%d:%c\n", pos+1, str1[pos]);
				else printf("no matches\n");
			}else loop=0;
		}else loop=0;
	}
	putchar('\n');
	return 0;
}
/* any: return pos of str1, if any character matches
 * from s2, else -1
*/
int
any(char s1[], char s2[]){
	
	int i, j, c;

	for (i=0; (c=s2[i]) != '\n'; i++)
		for (j=0; s1[j] != '\n'; j++)
			if (s1[j] == c )
				return j;
	return -1;
}

/* get_line : make a line string from user input */
int
get_line(char s[], int lim){
	
		int c, i;

		for (i=0; i<lim-1 && (c=getchar()) != '\n' 
				 && c != EOF; ++i)
				s[i] = c;
		if (c == '\n'){
			s[i] =c;
			++i;
		}
		s[i] = '\0';
		return i;
}



