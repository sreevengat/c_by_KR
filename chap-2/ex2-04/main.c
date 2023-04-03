/*
   	page-48
	EX2-4. Write a alternative 
	version of squeeze(s1, s2) 
	that deletes each character 
	in s1 that matches any 
	character in the string2
*/

/*
 * refer page-47 for squeeze function 
*/

#include <stdio.h>

#define MAXLINE	1000

int get_line(char line[], int maxline);
void squeeze(char str1[], char str2[]);

int
main(void){
	
	char str1[MAXLINE], str2[MAXLINE];
	int loop;

	loop=1;
	while (loop){
		printf("Squeeze string 1 from string 2\n");
		printf("Enter string 1 : ");
		if (get_line(str1, MAXLINE) > 0){
			printf("Enter string 2 : ");
			if (get_line(str2, MAXLINE) > 0){
				squeeze(str1, str2);
				printf("\t%s\n", str1);
			}else loop=0;
		}else loop=0;
	}
	putchar('\n');
	return 0;
}

/* squeeze: deletes each character
 * in s1 that matches any character
 * in s2
 */
void 
squeeze(char s1[], char s2[]){
	
	int i, j,k,c;

	for (i=0; (c=s2[i]) != '\0'; i++){
		for (j=0,k=0; s1[j] != '\0'; j++)
			if (s1[j] != c)
				s1[k++] = s1[j];
		s1[k] = '\0';
	}

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



