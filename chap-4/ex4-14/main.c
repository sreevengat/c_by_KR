/*
	page-91
	Define a macro swap(t,x,y) that
	interchanges two arguments ot type
	t.(Block structure will help)
*/

#include <stdio.h>

#define paste(front, back)	front ## back

#define dprint(expr) printf(#expr " = %g\n", expr);


#define swap(t,x,y)	{t tmp;\
						tmp=x;\
						x=y;\
						y=tmp;}


int
main(void){
	
		float paste(v, 1)=10.0;
		float paste(v, 2)=20.0;

		printf("before swap: v1=%g, v2=%g\n", v1, v2);
		swap(int, v1, v2);
		printf("after  swap: v1=%g, v2=%g\n", v1, v2);
				
		dprint(v1/v2);

}

