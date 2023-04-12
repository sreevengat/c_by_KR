#define MAXOP	100
#define MAXVAL	100
#define NUMBER '0'
#define ALPHA	'A'
#define VARIABLE 'V'
#define VARLEN	26

int getop(char s[]);

void push(double);
double pop(void);
void stack_dup(void);
void stack_swap(void);
void stack_clear(void);
void stack_list(void);

int getch(void);
void ungetch(int);

int get_line(char s[], int lim);

int do_math(char s[]);
void handle_var(char s[]);
