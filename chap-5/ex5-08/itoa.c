#include <stdio.h>
#include "string.h"

#if 1
/* itoa: convert integer to string */
void
itoa(int v, char *str){
	
	char *s=str;
	unsigned int n;

	n = (v < 0) ? -v : v;
	do {
		*s++ = n % 10 + '0';
	}while ((n/=10) > 0);
	if (v < 0)
		*s++ = '-';
	*s='\0';
	str_rev(str);
	
}
#endif

#if 0
/* itoa: convert integer to string */
void
itoa(int n, char s[]){
	
	unsigned int v;
	static int i, sign;

	if (n < 0){
		s[i++] = '-';
		v = -n;
		sign=-1;
	}else v = n;

	if (v/10)
		itoa(v/10, s);
	else {
		if (sign == -1){
			sign=1;
			i=1;
		}
		else i=0;
	}
	s[i++]=v%10+'0';
	s[i] = '\0';
}
#endif
