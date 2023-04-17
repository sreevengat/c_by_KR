/*
	page-145
	EX6-5. Write a function undef that 
	will remove a name and definition 
	from the table maintained by lookup
	and install
*/

#include <stdio.h>
#include "table_lookup.h"

int
main(void){
		
	struct nlist *np = install("IN", "1");
	np=lookup("IN");
	if (np != NULL)
		printf("%s, %s\n", np->name, np->defn);
	else  printf("not found\n");
	
	undef("IN");
	np=lookup("IN");
	if (np != NULL)
		printf("%s, %s\n", np->name, np->defn);
	else  printf("not found\n");	

	return 0;
}


