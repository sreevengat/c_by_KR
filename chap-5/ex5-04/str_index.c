#include <string.h>

/* strrindex: return index of t in s, -1 if none */
/* scan from right to left */
int 
strrindex(char s[], char t[]){
	
	int i, j, k, t_len;
	
	t_len=strlen(t)-1;
	for (i=strlen(s)-1; i >= 0; i--){
		for (j=i, k=t_len; k >= 0 && s[j]==t[k]; j--,k--)
				;
		if (k == -1)
			return i;
	}
	return -1;
}

/* strindex: return index of t in s, -1 if none */
/* scan from left to right */

int
strindex(char s[], char t[]){
	
	int i, j, k;

	for (i=0; s[i] != '\0'; i++){
		for (j=i,k=0; t[k] != '\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
