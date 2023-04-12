#include <stdio.h>

/*str_ncmp: compare n nchars from t to s */
int
str_ncmp(char *s, char *t, int n){
	
	char *src=t, *dest=s;

	while (--n >= 0 && *src == *dest 
				&& *src && *dest){
		src++;
		dest++;
	}
	return (*dest-*src);
}

/* str_ncat: concatenate n chars from t to s */
int
str_ncat(char *s, char *t, int n){
	
	char *src=t, *dest=s;
	
	while (*dest)
		dest++;
	if (*(dest-1) == '\n')
		dest--;
	while (--n >=0 && *src)
		*dest++ = *src++;
	*dest = '\0';
	return src-t;
}

/* str_ncpy: copy first n charactes from t to s */
int
str_ncpy(char *s, char *t, int n){
	
	char *src=t, *dest=s;

	while (--n >= 0 && *src)
		*dest++=*src++;
	*dest = '\0';
	return src-t;
}

/* str_end: return 1, if t occurs in s, from end , else 0*/
int
str_end(char *s, char *t){
	
	char *src=t, *dest=s;
	
	while (*src)
		src++;
	while (*dest)
		dest++;
	for (; dest >= s && *src==*dest; src--, dest--)
			if (src == t)
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
		s--;
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
