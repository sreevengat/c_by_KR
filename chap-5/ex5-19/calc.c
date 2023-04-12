#include <stdio.h>
#include <math.h>
#include "calc.h"
#include "stack.h"
#include "operand.h"
#include "char.h"
#include "atof.h"


void
calc(void){
	
	int do_math(char *s);
	void handle_var(char *s, double var[]);
	double var[VARLEN], res, op2;
	char s[MAXOP];
	int type, ptype;

	while ((type=getop(s)) != EOF){
		switch (type){
			case NUMBER:
				stack_push(atof(s));
				break;
			case ALPHA:
				type = do_math(s);
				break;
			case VARIABLE:
				if (s[1] == '\0'){	/* actions for most recent var */
					if (s[0] == '=')
						res = stack_pop();
					else if (s[0] == '$')
						stack_push(res);
					else if (s[0] == '?')
						printf("\t%.8g\n", res);
				}else
					handle_var(s, var);
				break;
			case '+':
				stack_push(stack_pop() + stack_pop());
				break;
			case '*':
				stack_push(stack_pop() * stack_pop());
				break;
			case '-':
				op2 = stack_pop();
				stack_push(stack_pop() - op2);
				break;
			case '/':
				op2 = stack_pop();
				if (op2 != 0.0)							
					stack_push(stack_pop()/op2);
				else{
					type=0;
					printf("error: zero divisor\n");
				}
				break;
			case '%':
				op2 = stack_pop();
				if (op2 != 0.0)
					stack_push((int)stack_pop() % (int)op2);
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
					res=stack_pop();
					printf("\t%.8g\n", res);
				}
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
		ptype=type;
	}

	
}

/* handle_var: handle the variables, and perfrom 
 * the actions */
void
handle_var(char s[], double var[]){
	
	int i, c;	
//	extern double var[];
	
	c = s[0];

	switch (c){
		case '=':	/* pop to var value  */
		case '$':	/* push var value to stack */
		case '?':	/* print the var value */
			i = s[1] - 'a';
			if (i >= 0 && i <= 26){	/* var[0], is most recent value \n */
				if (c == '=')
					var[i] = stack_pop();
				else if (c == '$')
					stack_push(var[i]);
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
		stack_push(sin(stack_pop()));
	}else if (s[0] == 'e' && s[1] == 'x' 
				&& s[2] == 'p' && s[3] == '\0'){
		stack_push(exp(stack_pop()));
	}else if (s[0] == 'p' && s[1] == 'o' 
				&& s[2] == 'w'  && s[3] == '\0'){
		op2 = stack_pop();
		stack_push(pow(stack_pop(), op2));
	}else if (s[0] == 's' && s[1] == 'q' 
				&& s[2] == 'r' && s[3] == 't' && s[4] == '\0'){
		stack_push(sqrt(stack_pop()));
	}else if (s[0] == 'l' && s[1] == 'o' 
				&& s[2] == 'g'  && s[3] == '\0'){
		stack_push(log10(stack_pop()));
	}else {
			printf("error: unknown command %s\n", s);
			return -1;
	}
	return ALPHA;
}



