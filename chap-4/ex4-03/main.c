/*
	page-79
	EX4-3. Given the basic framework, its
	straightforward to extend the calculator.
	Add the modulus(%) operator and 
	provisions for negative numbers.
*/

/*
 * reverse polish calculator, is entered as
 * 1 2 - 4 5 + * 
 * ans -9
 */

/*
 * modulus(%) operator wont work on float 
 */

#include <stdio.h>
#include <stdlib.h>	/* for atof */

#define MAXOP	100 /* max size of operand or operator */
#define NUMBER	'0'	/* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse polish calculator */
int
main(void){
	
	int type;
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
				else	
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0){
					push((int)pop()%(int)op2);
				}else
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}




