#include <stdio.h>
#include "calc.h"

static int sp=0;			/* next free stack position */
static double val[MAXVAL];	/* value stack */

/* Last in first out LIFO , like plate stacks*/

/* push: push f onto value stack */
void
stack_push(double f){
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, cant't push %g\n", f);

}

/* pop: pop and return top value from the stack */
double
stack_pop(void){
	
	if (sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* stack_list: print ,top to bottom of the stack */
void
stack_list(void){
	
	int i;

	for (i=sp-1; i >= 0; i--)
		printf("%.8g\n", val[i]);
}
/* stack_dup: duplicate the top of the stack */
void
stack_dup(void){
	
	double t;
	
	if (sp > 0){
		sp--;
		t = val[sp];
		val[sp-1] = t;
		printf("stack duplicated\n");
	}else printf("error: stack empty\n");
		
}
/* stack_swap: swap top two elements of the stack*/
void
stack_swap(void){
	
	double t;
	
	if (sp > 1){
		t = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = t;
		printf("stack swapped\n");
	}else printf("error: stack empty\n");
}

/* stack_clear : clear the stack and reset sp = 0 */
void
stack_clear(void){
	for (; sp >= 0; sp--)
		val[sp]=0;
	sp=0;
	printf("stack cleared\n");
}

