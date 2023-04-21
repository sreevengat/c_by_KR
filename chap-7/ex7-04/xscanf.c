#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "xscanf.h"

/* xscanf: scan from str, according to fmt
 * and save the  result in variable args */


void
xsscanf(char *str, char *fmt, ...){
	
	va_list ap;
	char *p, *sp, *sval;
	char tmp[100], *tp;
	int *ip;
	float *fp;
	
	sp = str;
	va_start(ap, fmt);
	for (p=fmt; *p && *sp; p++){
		if (*p != '%')
			continue;
		while (isspace(*sp))
		 sp++;
		tp = tmp;
		switch (*++p){
			case 'd':
				while (isdigit(*sp) || *sp == '+' || *sp == '-')
					*tp++ = *sp++;
				*tp = '\0';
				ip = va_arg(ap, int *);
				*ip = (int)atof(tmp);
				break;
			case 'f':
				while (isdigit(*sp) || *sp == '+' || *sp == '-')
					*tp++ = *sp++;
				if (*sp == '.'){
					*tp++ = *sp++;
					while (isdigit(*sp))
						*tp++ = *sp++;
				}
				*tp = '\0';	
				fp = va_arg(ap, float *);
				*fp = atof(tmp);
				break;
			case 's':
			case 'c':
				sval = va_arg(ap, char *);
				if (*p == 's'){
					while (!isspace(*sp))
						*sval++ = *sp++;
					*sval = '\0';
				}else *sval = *sp;
				break;
		}
	}
	va_end(ap);
}


