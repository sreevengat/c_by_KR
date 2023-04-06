#include <stdio.h>

#define MAXVAL	100 /* maximum depth of val stack */

int sp=0;			/* next free stack position */
double val[MAXVAL];	/* value stack */


/* Last in first out LIFO , like plate stacks*/

/* push: push f onto value stack */
void
push(double f){
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, cant't push %g\n", f);

}

/* pop: pop and return top value from the stack */
double
pop(void){
	
	if (sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}
