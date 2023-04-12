#ifndef STRING_H
#define STRING_H

int str_ncpy(char *s, char *t, int n);
int str_ncat(char *s, char *t, int n);
int str_ncmp(char *s, char *t, int n);

void str_cat(char *s, char *t);
int str_end(char *s, char *t);

#endif
