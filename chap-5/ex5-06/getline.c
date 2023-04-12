#include <stdio.h>


/* get_line: ptr version, getline into s, return length */

#if 1
int
get_line(char *s, int lim){
	
	char *p=s;
	int c;

	while (--lim > 0 &&	(c=getchar()) != EOF && c != '\n')
		*p++ = c;	
	if (c=='\n')
		*p++=c;
	*p='\0';
	return p-s;
}
#endif

#if 0
int 
get_line (char s[], int lim){
	
	int c, i;

	i=0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
			s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i]='\0';
	return i;
}
#endif 
