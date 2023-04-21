#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compare.h"

#define MAXLINE 1000

void
compare(FILE *f1, FILE *f2,
		char *name1, char *name2){
	
	char b1[1000], b2[1000];

	while ((fgets(b1, MAXLINE, f1) > 0) && (fgets(b2, MAXLINE, f2) > 0)){
		if (strcmp(b1, b2) != 0){
			printf("%s: %s", name1, b1);
			printf("%s: %s", name2, b2);
		}
	}

}
