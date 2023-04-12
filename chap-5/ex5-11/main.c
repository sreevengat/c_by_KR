/*
	page-118
	EX5-11. Modify the programs entab 
	and detab (written as exercise in
	Chapter 1) to accept a list of
	tab stops as argument
*/


#include <stdio.h>
#include "atof.h"
#include "detab.h"
#include "entab.h"

int
main(int argc, char *argv[]){
	
	int n = (argc > 1) ? (int)atof(*++argv) : 0;
	
	//detab(n);
	
	//entab(n);
	return 0;
}
