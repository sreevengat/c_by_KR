/*
	page-27
	EX1-15. Rewrite the temperature conversion 
	program of section 1.2 to use a function for
	conversion
*/

#include <stdio.h>

/* function prototye or function declaration*/
float fahr_to_celsius(float fahr);


int
main(void){
	
	float fahr;
	int lower, upper, step;

	lower = 0;		/* lower limit of temperature */
	upper = 300;	/* upper limit */
	step = 20;		/* step size */
	fahr = lower;
	printf("Fahr Celsius\n");
	while (fahr <= upper){
		printf("%4.0f %6.1f\n", fahr, fahr_to_celsius(fahr));
		fahr = fahr + step;
	}

	return 0;
}

/* function definition */
/* convert : given fahr to celsius */
float 
fahr_to_celsius(float fahr){
	float celsius;

	celsius = (5.0/9.0) * (fahr-32.0);
	return celsius;
}


