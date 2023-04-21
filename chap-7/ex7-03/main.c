/*
	page-156
	EX7-3. Revise minprintf to handle more
	of the other facilites of printf.
*/

#include "minprintf.h"
#include <limits.h>

int
main(void){
	
	minprintf("%c\n", 'a');
	minprintf("%d\n", 1234);
	minprintf("%x\n", 15);
	minprintf("%b\n", 15);
	minprintf("%d\n", INT_MIN);
	minprintf("%d\n", INT_MAX);
	minprintf("%u\n", UINT_MAX);
	minprintf("%ld\n", LONG_MIN);
	minprintf("%ld\n", LONG_MAX);
	minprintf("%lu\n", ULONG_MAX);
	minprintf("%lld\n", LLONG_MIN);
	minprintf("%lld\n", LLONG_MAX);
	minprintf("%llu\n", ULLONG_MAX);
	

	return 0;
}

