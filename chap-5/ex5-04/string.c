#include <stdio.h>


/* str_end: return 1, if t occurs in s, from end , else 0*/
int
str_end(char *s, char *t){
	
	char *src=s, *dest=t;
	
	while (*src)
		src++;
	while (*dest)
		dest++;
	for (; src >= s && *src==*dest; src--, dest--)
			if (dest == t)
				return 1;
	return 0;
}

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
