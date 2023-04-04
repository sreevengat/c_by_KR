/*
	page-60
	EX3-2. Write a function escape(s,t)
	that converts characters like newline
	and tab into visibile escape sequences 
	like \n \t as it copies the string t 
	to s . Use a switch . Write a function 
	for other direction as well, converting
	escape sequences into real characters
*/

/* 
 * Array should be in increasing order
*/

#include <stdio.h>

#define MAXLINE	1000

int get_line(char s[], int lim);
void escape(char s[], char t[]);
int to_real_chars(int c, char a[], int len);

int
main(void){
	
	int loop;
	char t[MAXLINE];
	char s[MAXLINE]; /* big enough to hold t */

	loop=1;
	while (loop){
		printf("Enter string : ");
		if (get_line(t, MAXLINE) > 0){
			escape(s, t);
			printf("%s\n", s);
		}else {
				printf("\nEOF\n");
				loop=0;
		}
	}
	return 0;
}

/* escape : convert escape char into real
 * chars from t[] to s[]
 */
void
escape(char s[], char t[]){

	int i,j,c;
	char rc[2];

	j=i=0;
	while ((c=t[i++]) != '\0'){
		switch (c){
			case '\n':
			case '\t':
			case ' ':
				if (to_real_chars(c, rc, 3) == 1){
					s[j++] = rc[0];
					s[j++] = rc[1];
				}
				break;
			default :
				s[j++] = c;
				break;
		}
	}
	s[j] = '\0';
}


/* to_real_chars : escape chars to real chars in a*/
int
to_real_chars(int c, char a[], int len){
	
	int ret=1;

	if (len >= 2){
		a[0]='\\';
		switch (c){
			case '\n':
				a[1] = 'n';
				break;
			case '\t':
				a[1] = 't';
				break;
			case ' ':
				a[1] = 'b';
				break;
			default :
				ret=0;
				break;
		}
	}else 
		ret=0;
	return ret;
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



