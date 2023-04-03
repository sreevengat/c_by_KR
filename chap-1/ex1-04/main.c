/*
	page-13
	EX1-4. Write a program to print corresponding 
	Celsius to Fahrenheit table
*/

#include <stdio.h>


int
main(void){
	
	/*
		from previous example ex1-3 
		we get step size for celsius is 11.1,
		upper limit is 148.9, lower limit is -17.8
	*/
	
	float lower, upper, step, fahr, celsius;

	lower = -17.8;
	upper = 148.9;
	step = 11.1;
	celsius = lower;

	printf("Celsius Fahr\n");
	while (celsius <= upper){
		fahr = celsius * (9.0/5.0) + 32.0;
		printf("%6.1f %4.0f\n", celsius, fahr);
		celsius = celsius + step;
	}

	return 0;
}
