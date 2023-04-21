#ifndef FILE_H
#define FILE_H

#include <stdio.h>

char *fgets(char *s, int n, FILE *iop);
int fputs(char *s, FILE *iop);
int getline(char *line, int max);

#endif
