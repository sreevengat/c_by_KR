#ifndef ALLOC_H
#define ALLOC_H

#define ALLOCSIZE	10000	/* size of available storage */

char *alloc(int n);
void afree(char *p);

#endif
