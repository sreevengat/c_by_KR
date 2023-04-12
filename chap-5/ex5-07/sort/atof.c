#include <ctype.h>

#if 1
/* atof: convert string s to double */
double
atof(char *s){
	
	char *p=s;
	double val, power, exp;
	int sign;
	
	while (isspace(*p)) /* skip blanks */
		p++;
	sign=(*p == '-') ? -1 : 1;
	if (*p == '+' || *p == '-')
		p++;
	for (val =0.0; isdigit(*p); p++)
		val = 10.0 * val + (*p - '0');
	if (*p == '.')
		p++;
	for (power = 1.0; isdigit(*p); p++){
		val = 10.0 * val + (*p-'0');
		power *= 10.0;
	}
	val = sign * val / power;
	if (*p == 'e' || *p == 'E'){
		p++;
		sign = (*p == '-') ? -1 : 1;
		if (*p == '+' || *p == '-')
			p++;
		for (exp=0.0; isdigit(*p); p++)
			exp = 10.0 * exp + (*p-'0');
		while (exp-- > 0.0){
			if (sign == 1)
				val *= 10.0;
			else
				val /= 10.0;

		}
	}
	return val;	
}
#endif 

#if 0
/* atof: convert string s to double */
double
atof(char s[]){

	double val, power, exp;
	int i, sign;

	for (i=0; isspace(s[i]); i++) /* skip blanks */
		;
	sign=(s[i]=='-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val =0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i]-'0');
		power *= 10.0;
	}
	val = sign * val / power;
	if (s[i] == 'e' || s[i] == 'E'){
		i++;
		sign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			++i;
		for (exp=0.0; isdigit(s[i]); i++)
			exp = 10.0 * exp + (s[i]-'0');
		while (exp-- > 0.0){
			if (sign == 1)
				val *= 10.0;
			else
				val /= 10.0;

		}
	}
	return val;	
}
#endif

