/*
	page-159
	EX7-4. Write a  private version of
	scanf analogous to minprintf from the
	previous section 
*/

#include <string.h>
#include "xscanf.h"
#include "minprintf.h"

int
main(void){
	
	int day, year;
	char weekday[20], month[20], dtm[100];

	strcpy(dtm, " Saturday March 25 1989");
	xsscanf(dtm, "%s %s %d %d", weekday, month, &day, &year);

	minprintf("%s %d, %d = %s\n", month, day, year, weekday);

	strcpy(dtm, "		\nHelloWorld\n");
	xsscanf(dtm, "%s", month);
	minprintf("%s\n", month);


	char b[50];
	char res[50];

	strcpy(b, "Hello World\n");
	xsscanf(b, "%s", res);
	minprintf("%s\n", res);
	
	int v1, v2;
	char c='b';

	strcpy(b, "-1234 5678 a ");
	xsscanf(b, "%d %d %c", &v1, &v2, &c);
	minprintf("%d %d %c\n", v1, v2, c);
	
	float f;
	strcpy(b, "1234.5678");
	xsscanf(b, "%f", &f);
	minprintf("%f\n", f);
	

	return 0;
}

