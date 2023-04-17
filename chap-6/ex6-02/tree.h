#ifndef TREE_H
#define TREE_H

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *add_tree(struct tnode *p, char *w);
void tree_print(struct tnode *p);

#endif
