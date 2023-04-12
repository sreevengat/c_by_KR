#include <stdio.h>
#include "string.h"

/* str_cmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int
str_cmp(char *s, char *t){
	for (; *s == *t; s++, t++)
		if (!*s)
			return 0;
	return *s-*t;
}


/* str_cpy: copy t to s */
void
str_cpy(char *s, char *t){
	
	while ((*s++=*t++))
		;
}

/* strindex: return index of t in s, -1 if none */
/* scan from left to right */
int
str_index(char s[], char t[]){
	
	char *s1, *s2, *t1;
	
	s1=s;
	while (*s1){
		s2=s1;
		t1=t;
		while (*t1 && *s2 == *t1){
			s2++;
			t1++;
		}
		if (t1 > t  && !(*t))
			return s1-s;
		s1++;
	}
	return -1;
}

/* strrindex: return index of t in s, -1 if none */
/* scan from right to left */
int 
str_rindex(char s[], char t[]){
	
	int i, j, k, t_len;
	
	t_len=str_len(t)-1;
	for (i=str_len(s)-1; i >= 0; i--){
		for (j=i, k=t_len; k >= 0 && s[j]==t[k]; j--,k--)
				;
		if (k == -1)
			return i;
	}
	return -1;
}
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
str_rev(char *s){
	
	char *start, *end, t;

	start=end=s;
	while (*end)
		end++;
	end--;
	while (start < end){
		t = *start;
		*start++ = *end;
		*end-- = t;
	}
}

int
str_len(char *s){
	
	char *p = s;

	while (*p)
		p++;
	return p-s;
}
