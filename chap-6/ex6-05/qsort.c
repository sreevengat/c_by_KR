#include <stdio.h>
#include "qsort.h"

/* qsort: sort v[left]...v[right] into increasing order */
void
q_sort(struct tnode_arr v[], int left, int right){

	void swap(struct tnode_arr v[], int, int);
	int i, last; 
	
	if (left >= right)	/* do nothing if array contains */
		return ;
	swap(v, left, (left+right)/2);
	last=left;
	for (i=left+1; i <= right; i++){		
		if (num_cmp(v[i].count, v[left].count) > 0)	
			swap(v, ++last, i);
	}
	swap(v, left, last);
	q_sort(v, left, last-1);
	q_sort(v, last+1, right);
}

/* swap: swap two elemets */
void
swap(struct tnode_arr v[], int i, int j){
	
	struct tnode_arr t;
	
	t.name = v[i].name;
	t.count = v[i].count;
	
	v[i].name = v[j].name;
	v[i].count = v[j].count;

	v[j].name = t.name;
	v[j].count = t.count;

}

/* numcmp: compare s1 and s2 numerically */
int
num_cmp(int v1, int v2){
	
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
