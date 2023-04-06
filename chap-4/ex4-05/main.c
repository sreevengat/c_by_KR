/*
	page-79
	EX4-5.Add access to library functions
	like sin, exp, and pow. see <math.h>
	in Appendix B, section 4
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

int getop(char []);

void push(double);
double pop(void);
void stack_dup(void);
void stack_swap(void);
void stack_clear(void);
void stack_list(void);

int do_math(char s[]);

int
main(void){
	
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
				if (op2 != 0.0)							
					push(pop()/op2);
				else{
					type=0;
					printf("error: zero divisor\n");
				}
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
						|| ptype == '%' || ptype == ALPHA)
					printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
		ptype = type;
	}
	return 0;
}
/* do_math : perform math library function */
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

