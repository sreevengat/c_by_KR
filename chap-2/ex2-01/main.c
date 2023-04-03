/*
	page-36
	EX2-1. Write a program to determine 
	the ranges of char, short, int, and
	long variables, both signed and unsigned,
	by printing appropriate values from
	standard headers and by direct 
	computation. Harder if you compute
	them : determine the ranges of the
	various floating-point types.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

void print_size_from_std_header(void);
void print_size_using_computation(void);

int
main(void){
	
	print_size_from_std_header();
	print_size_using_computation();
	return 0;
}
void 
print_size_from_std_header(void){
	
		printf("########## RANGES FROM STANDARD HEADERS ##########\n");
		
		printf("unsigned char   :%20d to %-20u\n", CHAR_MIN, UCHAR_MAX);
		printf("signed char     :%20d to %-20d\n", SCHAR_MIN, SCHAR_MAX);	
		
		printf("unsigned short  :%20d to %-20u\n", 0, USHRT_MAX);
		printf("signed short    :%20d to %-20d\n", SHRT_MIN, SHRT_MAX);
		
		printf("unsigned int    :%20d to %-20u\n", 0, UINT_MAX);
		printf("signed int      :%20d to %-20d\n", INT_MIN, INT_MAX);
		
		printf("unsigned long   :%20d to %-20lu\n", 0, ULONG_MAX);
		printf("signed long     :%20ld to %-20ld\n", LONG_MIN, LONG_MAX);
		
		printf("unsigned llong  :%20d to %-20llu\n", 0, ULLONG_MAX);
		printf("signed llong    :%20lld to %-20lld\n", LLONG_MIN, LLONG_MAX);

		printf("float           :%20f to %-20f\n", FLT_MIN, FLT_MAX);
		printf("float precision :%20d\n", FLT_DIG);
		printf("double          :%20f to %-20f\n", DBL_MIN, DBL_MAX);
		printf("double precision:%20d\n", DBL_DIG);

}
void 
print_size_using_computation(void){
	
		unsigned char uchar;
		signed char schar;
		unsigned short ushort;
		signed short sshort;
		unsigned int uint;
		signed int sint;
		unsigned long ulong;
		signed long slong;
		unsigned long long ullong;
		signed long long sllong;
		int i;

		uchar=0;
		schar=1;
		--uchar;
		while (schar > 0)
			schar = schar * 2;
		
		ushort=0;
		sshort=1;
		--ushort;
		while (sshort > 0)
			sshort = sshort * 2;
		
		uint=0;
		sint=1;
		--uint;
		while (sint > 0)
			sint = sint * 2;
		
		ulong=0;
		slong=1;
		--ulong;
		while (slong > 0)
			slong = slong * 2;
		
		ullong=0;
		sllong=1;
		--ullong;
		while (sllong > 0)
			sllong = sllong * 2;
		
		printf("########## RANGES USING COMPUTATION ##########\n");

		printf("unsigned char   :%20d to %-20u\n", 0, uchar);
		uchar = schar-1;
		printf("signed char     :%20d to %-20d\n", schar, uchar);		
		uchar = 0;
		--uchar;
		i=0;
		while (uchar > 0){
			uchar = uchar / 2;
			++i;
		}	
		printf("size of char    :%20dbits, %dbytes\n", i, i/8);	
		
		printf("unsigned short  :%20d to %-20u\n", 0, ushort);
		ushort = sshort-1;
		printf("signed short    :%20d to %-20d\n", sshort, ushort);	
		ushort = 0;
		--ushort;
		i=0;
		while (ushort > 0){
			ushort = ushort / 2;
			++i;
		}	
		printf("size of short   :%20dbits, %dbytes\n", i, i/8);	
		
		printf("unsigned int    :%20d to %-20u\n", 0, uint);
		uint = sint-1;
		printf("signed int      :%20d to %-20d\n", sint, uint);	
		uint = 0;
		--uint;
		i=0;
		while (uint > 0){
			uint = uint / 2;
			++i;
		}	
		printf("size of int     :%20dbits, %dbytes\n", i, i/8);	
		
		printf("unsigned long   :%20d to %-20lu\n", 0, ulong);
		ulong = slong-1;
		printf("signed long     :%20ld to %-20ld\n", slong, ulong);	
		ulong = 0;
		--ulong;
		i=0;
		while (ulong > 0){
			ulong = ulong / 2;
			++i;
		}	
		printf("size of long     :%20dbits, %dbytes\n", i, i/8);	

		printf("unsigned llong  :%20d to %-20llu\n", 0, ullong);
		ullong = sllong-1;
		printf("signed llong    :%20lld to %-20lld\n", sllong, ullong);
		ullong = 0;
		--ullong;
		i=0;
		while (ullong > 0){
			ullong = ullong / 2;
			++i;
		}	
		printf("size of llong    :%20dbits, %dbytes\n", i, i/8);	
		
}



