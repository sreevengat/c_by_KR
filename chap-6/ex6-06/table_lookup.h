#ifndef TABLE_LOOKUP_H
#define TABLE_LOOKUP_H


#define HASHSIZE 101


struct nlist {	/* table entry */
	struct nlist *next; /* next entry in chain */
	char *name;			/* defined name */
	char *defn;			/* replacement name */
};

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *name);

#endif
