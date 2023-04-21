/*
	page-165
	EX7-7. Modify the pattern finding
	program of Chapter 5 to take its 
	input from a set of named files or
	if no files are name as arguments,
	from the standard input. Should the
	file name be printed when a matching 
	line is found.
*/

/* yes we can print the file name,
 * when match ocuurs */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lines.h"
#define MAXLINE 1000

int
main(int argc, char *argv[]){
	
	char line[MAXLINE], fline[MAXLINE];
	int found=0, i, len;
	FILE *fp;
		
	argc--;
	if (!argc)
		fprintf(stderr, "Usage: %s file1..filen\n", *argv);
	else {
		while (fgets(line, MAXLINE, stdin)){
			for (i=1; i <= argc; i++){
				if ((fp=fopen(argv[i], "r")) != NULL){
					while (fgets(fline, MAXLINE, fp)){
						len = strlen(fline);
						fline[len-2] = '\0';
						if (strstr(line, fline) != NULL){
							printf("%s:%s", argv[i], line);
							found++;
						}
					}
					fclose(fp);
				}else {
					fprintf(stderr, "Failed to open %s\n", argv[i]);
				}
			}
		}
	}
	return found;
}

