/*
	page-137
	EX6-1. Our version of getword does not
	properly handle underscores, string 
	constants , comments, or preprocessor
	control lines. Write a better version
*/

#include <stdio.h>
#include <ctype.h>
#include "getword.h"
#include "binsearch.h"

#define MAXWORD	100
#define NKEYS	(sizeof keytab / sizeof keytab[0])
/* should be in alphabetical order or increasing order*/
struct key keytab[]={
	{"auto", 0},
	{"break", 0},
	{"case", 0},
	{"char", 0},
	{"const", 0},
	{"continue", 0},
	{"default", 0},	
	{"int",0},
	/*....*/
	{"unsigned", 0},
	{"void", 0},
	{"volatile", 0},
	{"while", 0},
};

int
main(void){
	
	int n;
	char word[MAXWORD];

	while (get_word(word, MAXWORD) != EOF){
		if (isalpha(word[0]))
			if ((n=bin_search(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	}
	for (n=0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n",
						keytab[n].count, keytab[n].word);

	return 0;
}

