#include <stdio.h>

/* str_cat : copies t to s*/
void
str_cat(char *s, char *t){
	
	while (*s)
		s++;
	/* when loops end s points to '\0' */
	if (*(s-1) == '\n')	 
		s -= 1;
	/* it will copy '\0' also */
	while ((*s++ = *t++))
			;
}


/* reverse: reverse a string using recurrsion */
void
reverse(char s[]){
	
	static int i, j;

	if (s[j] != '\0' && s[j] != '\n'){
		j++;
		reverse(s);
	}
	if (i < j){
		int c;
		c = s[i];
		s[i++] = s[--j];
		s[j] = c;
	}else 
		i=j=0;
}
