#ifndef STRING_H
#define STRING_H

char *str_dup(char *s);

int str_cmp(char *s, char *t);
void str_cpy(char *s, char *t);

int str_index(char *s, char *t);
int str_rindex(char *s, char *t);

int str_ncpy(char *s, char *t, int n);
int str_ncat(char *s, char *t, int n);
int str_ncmp(char *s, char *t, int n);

void str_cat(char *s, char *t);
int str_end(char *s, char *t);

void str_rev(char *s);
int str_len(char *s);
#endif
