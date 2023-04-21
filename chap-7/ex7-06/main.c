/*
	page-165
	EX7-6. Write a program to 
	compare two files, printing 
	the first line where they differ
*/

#include <stdio.h>
#include <stdlib.h>
#include "compare.h"

int
main(int argc, char *argv[]){
	
	if (argc != 3){
		fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
		exit(1);
	}
	
	FILE *fp[2];
	char *fname[2];

	while (--argc > 0){
		if ((fp[3-argc-1] = fopen(*++argv, "r")) == NULL){
			printf("compare: cant't open %s\n", *argv);
			exit(1);
		}
		fname[3-argc-1] = *argv;
	}
	compare(fp[0], fp[1], fname[0], fname[1]);
	fclose(fp[0]);
	fclose(fp[1]);
	exit(0);
}

