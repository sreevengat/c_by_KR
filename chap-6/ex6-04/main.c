/*
	page-143
	EX6-4. Write a program that prints
	the distinct words in its input 
	sorted into decreasing order of
	frequency of occurrenct. Precede
	each word by its count.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "getword.h"
#include "tree.h"
#include "qsort.h"

#define MAXWORD	500


static int idx;

void tree_to_array(struct tnode *p, struct tnode_arr *arr);
/* word frequency count */
int
main(void){
	
	
	struct tnode *root;
	char word[MAXWORD];
	extern int nnodes;

	root=NULL;
	while (get_word(word, MAXWORD) != EOF){
		if (isalpha(word[0]))
			root=add_tree(root, word);
	}
	//tree_print(root);
	struct tnode_arr *arr = (struct tnode_arr *)malloc(sizeof(struct tnode_arr)*nnodes);
	
	if (arr == NULL){
		printf("error: malloc()\n");
		return 1;
	}
	tree_to_array(root, arr);	
	q_sort(arr, 0, idx-1);
	for (int i=0; i < idx; i++)
		printf("\t%d %s\n", arr[i].count, arr[i].name);
	free(arr);
	return 0;
}
void tree_to_array(struct tnode *p, struct tnode_arr *arr){
	
	if (p != NULL){
		tree_to_array(p->left, arr);
		arr[idx].name = p->word;
		arr[idx++].count= p->count;
		tree_to_array(p->right, arr);
	}
}


