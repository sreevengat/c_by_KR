/*
	page-143
	EX6-2. Write a program that reads a 
	C program and prints in alphabetical
	order each group of variable names
	that are identical in the first 6 
	characters, but different somewhere
	thereafter. Don't count words 
	within strings and comments . Make
	6 a parameter that can be set from 
	command line.
*/

#include <stdio.h>
#include <ctype.h>
#include "string.h"
#include "getword.h"
#include "tree.h"

#define MAXWORD	500
#define NPARA	6+1

/* word frequency count */
int
main(int argc, char **argv){
	
	char pattern[NPARA];
	int npara=0;

	if (argc == 1 || argc > 6){
		printf("Usage: %s c1 c2...c6\n", *argv);
		return 1;
	}
	npara=argc-1;
	pattern[npara] = '\0';
	while (--argc > 0)
		pattern[argc-1] = argv[argc][0];
	
	struct tnode *root;
	char word[MAXWORD];

	root=NULL;
	while (get_word(word, MAXWORD) != EOF){
		//if (isalpha(word[0]))
		 if (str_ncmp(word, pattern, npara) == 0) 
			root=add_tree(root, word);
	}
	tree_print(root);
	
	return 0;
}


