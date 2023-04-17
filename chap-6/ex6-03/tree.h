#ifndef TREE_H
#define TREE_H

struct tnode {
	char *word;
	int line;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *add_tree(struct tnode *p, char *w, int line);
void tree_print(struct tnode *p);

#endif
