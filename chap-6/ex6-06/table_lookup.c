#include <stdlib.h>
#include <stdio.h>
#include "table_lookup.h"
#include "string.h"

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string and return index */
unsigned
hash(char *s){
	
	unsigned hashval;

	for (hashval=0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	//printf("hash:%s:%d:%d\n", p, hashval, hashval % HASHSIZE);
	return hashval % HASHSIZE;
}

/* lookup: look for s in table */
struct nlist 
*lookup(char *s){
	
	struct nlist *np;
	

	for (np = hashtab[hash(s)]; np != NULL; np=np->next){
		if (str_cmp(s, np->name) == 0)
			return np;	/* found */
	}
	return NULL;
}
/* install: put(name, defn) in hashtab */
struct nlist
*install(char *name, char *defn){
	
	struct nlist *np;
	unsigned hashval;

	if ((np=lookup(name)) == NULL){	/* not found */
		np = (struct nlist *)malloc(sizeof(*np));
		if (np == NULL || (np->name = str_dup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}else 	/* already there */
		free((void *)np->defn);	/* free previous defn */
	if ((np->defn = str_dup(defn)) == NULL)
		return NULL;
	return np;
}

void
undef(char *name){
	
	struct nlist *np;
	unsigned hashval;

	if ((np=lookup(name))){	/* found */
		hashval = hash(name);
		free((void *)np->name);
		free((void *)np->defn);
		np =  hashtab[hashval];	
		free((void *)np);
		hashtab[hashval] = NULL;
	}

}

