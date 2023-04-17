/*
	page-143
	EX6-3. Write a cross-refrencer that
	prints a list of words in a document 
	and for each word, list of line numbers
	on which it occurs. Remove noise words
	like "the" "and" so on..
*/

#include <stdio.h>
#include <ctype.h>
#include "string.h"
#include "getword.h"
#include "tree.h"

#define MAXWORD	500

static char *noise_words[] = {
		"the",
		"and",
		"\0"
};

/* word frequency count */
int
main(void){
	
	struct tnode *root;
	char word[MAXWORD];
	int line;
	int i;

	root=NULL;
	while ((line=get_word(word, MAXWORD)) != EOF){
			if (isalpha(word[0])){
				for (i=0; noise_words[i][0] != '\0'; i++)
					if (str_cmp(noise_words[i], word) == 0){
						break;
					}
				if (noise_words[i][0] == '\0')
					root=add_tree(root, word, line);
			}
	}
	tree_print(root);	
	return 0;
}


