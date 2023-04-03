/*
	page-14
	EX1-5. Modify the temperature conversion 
	program to print the table in reverse order,
	that is from 300 degress to 0;
*/

#include <stdio.h>


/*
	print fahrenheit-celsius table 
*/

int
main(void){
	
	int fahr;

	for (fahr=300; fahr >= 0; fahr -= 20)
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));

	return 0;
}
