#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "string.h"

static struct tnode *talloc(void);

/* add_tree: add a node with w, at or below p */
struct tnode
*add_tree(struct tnode *p, char *w){
	
	int cond;

	if (p == NULL){	/* a new word has arrive */
		p = talloc();
		p->word = str_dup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}else if ((cond = str_cmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = add_tree(p->left, w);
	else
		p->right = add_tree(p->right, w);
	return p;
}
/* talloc : make a tnode */
struct tnode 
*talloc(void){
	return (struct tnode *)malloc(sizeof(struct tnode));
}

/* tree_print: in order of tree p */
void
tree_print(struct tnode *p){
	
	if (p != NULL){
		tree_print(p->left);
		printf("%4d %s\n", p->count, p->word);
		tree_print(p->right);
	}
}

