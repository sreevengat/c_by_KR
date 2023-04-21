/*
	page-165
	EX7-8. Write a program to print a 
	set of files, starting each new 
	one a new page , with title and
	a running page count for each file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lines.h"
#define MAXLINE 80
#define NLINES	20


int
main(int argc, char *argv[]){
	
	if (argc == 1){
		fprintf(stderr, "Usage: %s file1..filen\n", *argv);
		exit(1);
	}
	int i, lineno, page, len;
	FILE *fp;
	char line[MAXLINE];
	char mark[MAXLINE];
	
	for (i=0; i < MAXLINE-1; i++)
		mark[i] = '-';
	mark[i] = '\0';
	lineno=0;
	for (i=1; i < argc; i++){
		if ((fp=fopen(argv[i], "r")) != NULL){
			page=lineno=0;
			printf("%s\n", mark);
			printf("%40s\n", argv[i]);
			printf("%s\n", mark);
			while (fgets(line, MAXLINE, fp)){
				printf("%s", line);
				len = strlen(line);
				if (line[len-2] != '\n')
					putchar('\n');
				lineno++;
				if (lineno > NLINES){
					page++;
					lineno=0;
					printf("%39s[%d]\n\n", " ", page);
					printf("%s\n", mark);
				}
			}
			if (lineno){
				while (lineno < NLINES){
					lineno++;
					putchar('\n');
				}
				printf("%39s[%d]\n\n", " ", page+1);
				printf("%s\n", mark);
			}
		fclose(fp);
		}else fprintf(stderr, "file %s not found \n", argv[i]);
	}
	exit(0);
}

