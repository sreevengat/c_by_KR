#ifndef CALC_H
#define CALC_H

#define MAXOP	100
#define MAXVAL	100
#define NUMBER 	'0'
#define ALPHA	'A'
#define VARIABLE 'V'
#define VARLEN	26


void calc(void);

int do_math(char s[]);
void handle_var(char s[]);

#endif
