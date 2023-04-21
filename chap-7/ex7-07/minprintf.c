#include <stdio.h>
#include "minprintf.h"

/* min printf: minimal printf with 
 * variable argument list */
void
minprintf(char *fmt, ...){

	va_list ap;	/* points to each unnamed arg in turn */
	char *p, *sval;
	int islong, i;
	double dval;
	unsigned long int ulval;
	unsigned long long int ullval;
	char tmp[7];

	va_start(ap, fmt);	/* make ap point to 1st unnamed arg */
	for (p=fmt; *p; p++){
		if (*p != '%'){
			putchar(*p);
			continue;
		}
		islong=0;
		i=0;
		tmp[i++] = '%';
		++p;
		if (*p == 'l'){
			tmp[i++] = *p;
			islong=1;
			++p;
			if (*p == 'l'){
				tmp[i++] = *p;
				islong=2;
				++p;
			}
		}
		tmp[i++] = *p;
		tmp[i] = '\0';
		switch(*p){
			case 'd':
			case 'c':
				if (islong==2){
					ullval = va_arg(ap, long long int);
					printf(tmp, ullval);
				}
				else {
					ulval = (islong) ? va_arg(ap, long int) : va_arg(ap, int);
					printf(tmp, ulval);
				}
				break;
			case 'x':
			case 'X':
			case 'o':
			case 'b':
			case 'u':
				if (islong == 2){
					ullval = va_arg(ap, unsigned long long int);
					printf(tmp, ullval);
				}else {
					ulval = (islong) ? va_arg(ap, unsigned long int ) : va_arg(ap, unsigned int);
					printf(tmp, ulval);
				}
				break;
			case 'f':
				dval = va_arg(ap, double);	
				printf("%f", dval);
				break;
			case 's':
				for (sval=va_arg(ap, char *); *sval; sval++)
					putchar(*sval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}
