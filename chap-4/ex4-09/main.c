/*
	page-79
	EX4-9. Our getch and ungetch do not 
	handle a pushed-back EOF correctly .
	Decide what their properties ought
	to be if an EOF is pushed back, 
	then implement your design
*/

/*
 * Ans: in getop() fun, we didn't push
 * back the EOF, so changes made to getch(),
 * 
 */

/*
 * reverse polish calculator, is entered as
 * 1 2 - 4 5 + * 
 * ans -9
 */

#include <stdio.h>
#include <stdlib.h>	/* for atof */
#include <math.h>

#define MAXOP	100 /* max size of operand or operator */
#define NUMBER	'0'	/* signal that a number was found */
#define ALPHA	'A' /* signal that a alphabets was found */
#define VARIABLE 'V' /* signal that a variable was found */
#define VARLEN	26

/*example 
 * use variable a to z
 * 10 =1, assigns 10 to var 1
 * ?1, print var 1
 * ? print most recent var
 * $1 push var 
 * $ push recent res
 * 10 =a 20 =b
 * $a $b +
 * 30
 * $ $a +
 * 40
 * 5 $ +
 * 45
 */

int getop(char []);

void push(double);
double pop(void);
void stack_dup(void);
void stack_swap(void);
void stack_clear(void);
void stack_list(void);

int do_math(char s[]);
void handle_var(char s[]);

double var[VARLEN];
double res;


int
main(void){
	
	extern double res;
	int type, ptype; 
	double op2;
	char s[MAXOP];
	
	while ((type=getop(s)) != EOF){
		switch (type){
			case NUMBER:
				push(atof(s));
				break;
			case ALPHA:
				type = do_math(s);
				break;
			case VARIABLE:
				if (s[1] == '\0'){	/* actions for most recent var */
					if (s[0] == '=')
						res = pop();
					else if (s[0] == '$')
						push(res);
					else if (s[0] == '?')
						printf("\t%.8g\n", res);
				}else
					handle_var(s);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0){							
					type=0;
					push(pop()/op2);
				}
				else	
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((int)pop() % (int)op2);
				else{
					type=0;
					printf("error: zero divisor\n");
				}
				break;
			case 'l':
				printf("stack list :\n");
				stack_list();
				break;
			case 'd':
				stack_dup();
				break;
			case 's':
				stack_swap();
				break;
			case 'c':
				stack_clear();
				break;
			case '\n':
				if (ptype == '+' || ptype == '-' 
						|| ptype == '*' || ptype == '/' 
						|| ptype == '%' || ptype == ALPHA){
					res=pop();
					printf("\t%.8g\n", res);
				}
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
		ptype=type;
	}
	return 0;
}
/* handle_var: handle the variables, and perfrom 
 * the actions */
void
handle_var(char s[]){
	
	int i, c;	
	extern double var[];
	
	c = s[0];

	switch (c){
		case '=':	/* pop to var value  */
		case '$':	/* push var value to stack */
		case '?':	/* print the var value */
			i = s[1] - 'a';
			if (i >= 0 && i <= 26){	/* var[0], is most recent value \n */
				if (c == '=')
					var[i] = pop();
				else if (c == '$')
					push(var[i]);
				else if (c == '?')
					printf("\t%.8g\n", var[i]);
			}else printf("error: var %d out of range\n", i);
			break;
		default :
			printf("error: unknown variable command %s\n", s);
			break;
	}
}
/* do_math : perform math library functions */
int 
do_math(char s[]){
	double op2;

	if (s[0] == 's' && s[1] == 'i'
				&& s[2] == 'n' && s[3] == '\0'){
		push(sin(pop()));
	}else if (s[0] == 'e' && s[1] == 'x' 
				&& s[2] == 'p' && s[3] == '\0'){
		push(exp(pop()));
	}else if (s[0] == 'p' && s[1] == 'o' 
				&& s[2] == 'w'  && s[3] == '\0'){
		op2 = pop();
		push(pow(pop(), op2));
	}else if (s[0] == 's' && s[1] == 'q' 
				&& s[2] == 'r' && s[3] == 't' && s[4] == '\0'){
		push(sqrt(pop()));
	}else if (s[0] == 'l' && s[1] == 'o' 
				&& s[2] == 'g'  && s[3] == '\0'){
		push(log10(pop()));
	}else {
			printf("error: unknown command %s\n", s);
			return -1;
	}
	return ALPHA;
}

