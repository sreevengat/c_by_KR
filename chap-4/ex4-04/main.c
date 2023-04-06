/*
	page-79
	EX4-4. Add commands to print the top element 
	of the stack without poping , to duplicate it,
	and to swap the top two elements . Add a 
	command to clear the stack.
*/

/*
 * reverse polish calculator, is entered as
 * 1 2 - 4 5 + * 
 * ans -9
 */

#include <stdio.h>
#include <stdlib.h>	/* for atof */

#define MAXOP	100 /* max size of operand or operator */
#define NUMBER	'0'	/* signal that a number was found */

int getop(char []);

void push(double);
double pop(void);
void stack_dup(void);
void stack_swap(void);
void stack_clear(void);
void stack_list(void);

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
					printf("error: zero divisor\n");
					type=0;
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
				printf("stack list:\n");
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
						|| ptype == '%')
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



