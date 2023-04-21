
#include <stdio.h>
#include "lines.h"

void push(double);
double pop(void);

/* reverse polish calculator */
void
calc(void){
	
	char type;
	double op1, op2, res;
	char line[100];

	while (get_line(line, 100) > 0){
		if (sscanf(line, "%lf %lf %c", &op1, &op2, &type) == 3){
			push(op1);
			push(op2);
		}else if (sscanf(line, "%lf %lf", &op1, &op2) == 2){
			push(op1);
			push(op2);
			continue;
		}else if (sscanf(line, "%lf %c", &op1, &type) == 2){
			push(op1);
		}else if (sscanf(line, "%lf", &op1) == 1){
			push(op1);
			continue;
		}else if (sscanf(line, "%c", &type) == 1){	
			;
		}
		else continue;
		switch (type){
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
					continue;
				}
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0){
					push((int)pop()%(int)op2);
				}else{
					printf("error: zero divisor\n");
					continue;
				}
				break;
			case '\n':
				printf("\t%.8g\n", res);
				continue;
			default:
				printf("error: unknown command %d\n", type);
				continue;
		}
		op2=res=pop();
		printf("\t%.8g\n", op2);
		push(op2);
	}
}
