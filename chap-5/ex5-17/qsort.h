#ifndef QSORT_H
#define QSORT_H

void qsort(void *v[], int left, int right, 
				int(*comp)(void *, void *));
int num_cmp(char *s1, char *s2);

#endif
