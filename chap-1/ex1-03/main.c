/*
	page-13
	EX1-3. Modify the temperature conversion 
	program to print a heading above the table
*/

#include <stdio.h>

/*
	print Fahrenheit-Celsius table 
*/

int
main(void){
	
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;		/* lower limit of temperature */
	upper = 300;	/* upper limit */
	step = 20;		/* step size */

	fahr = lower;

	printf("Fahr Celsius\n");
	while (fahr <= upper){
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%4.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

	return 0;
}
