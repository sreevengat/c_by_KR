#include <stdio.h>
#include "string.h"
#include "atof.h"
#include "sort.h"

/* qsort: sort v[left]...v[right] into increasing order */
void
qsort(void *v[], int left, int right,
			int (*comp)(void *, void *)){
	int i, last;
	void swap(void *v[], int, int);
	extern int sort_flag;
	int cond, r;
	
	if (left >= right)	/* do nothing if array contains */
		return ;
	swap(v, left, (left+right)/2);
	last=left;
	for (i=left+1; i <= right; i++){
		cond = ((r=(*comp)(v[i], v[left])) < 0);	
		if (sort_flag & SORT_FLAG_REVERSE)
			cond = !cond;
		if (sort_flag & SORT_FLAG_FOLD)
			if (r == -32)
				continue;
		if (cond)
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}

/* swap: swap two elemets */
void
swap(void *v[], int i, int j){
	
	void *temp;

	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}

/* numcmp: compare s1 and s2 numerically */
int
num_cmp(char *s1, char *s2){
	
	double v1, v2;
	
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else 
		return 0;
}


#if 0
/* qsort: sort v[left]...v[right] into increasing order */

void
q_sort(char *v[], int left, int right){
	
	int i, last;
	void swap (char *v[], int i, int j);

	if (left >= right) /* do nothing if array contains */
		return;			/* fewer than two elements */
	swap(v, left, (left + right)/2);
	last=left;
	for (i=left+1; i <= right; i++)
		if (str_cmp(v[i], v[left]) < 0)
				swap(v, ++last, i);
	swap(v, left, last);
	q_sort(v, left, last-1);
	q_sort(v, last+1, right);
	
}
/* swap: interchange v[i] and v[j] */
void
swap(char *v[], int i, int j){
	
	char *temp;

	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}
#endif
