
#include <stdio.h>

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
