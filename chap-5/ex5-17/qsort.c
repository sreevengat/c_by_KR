#include <stdio.h>
#include "string.h"
#include "atof.h"
#include "sort.h"


#define OUT	0
#define IN	1

/* qsort: sort v[left]...v[right] into increasing order */
void
qsort(void *v[], int left, int right,
			int (*comp)(void *, void *)){
	
	extern int sort_flag;
	void swap(void *v[], int, int);
	int get_valid_field(char *);
	int get_col_pos(char *, int);

	int i, last, p1, p2, f1, f2;	
	int cond, r;
	extern int field_pos;
	
	f1=f2=p1=p2=0;
	if (left >= right)	/* do nothing if array contains */
		return ;
	swap(v, left, (left+right)/2);
	last=left;
	for (i=left+1; i <= right; i++){
		if (sort_flag & SORT_FLAG_FIELDSORT){
			f1=get_col_pos((char *)v[i], field_pos);
			f2=get_col_pos((char *)v[left], field_pos);
		}
		if (sort_flag & SORT_FLAG_DIRORD){	
			p1=get_valid_field((char *)v[i]);
			p2=get_valid_field((char *)v[left]);
		}
		cond = ((r=(*comp)((v[i]+p1+f1), (v[left]+p2+f2))) < 0);	
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

/* get_col_pos: return valid word pos */
int
get_col_pos(char *s, int col){
	
	char *p = s;
	int state = OUT, c=0;

	while (*p && col){
		c++;
		if (*p == ' ' || *p == '\t')
			state = OUT;
		else if (state == OUT){
			state = IN;
			col--;
		}
		p++;
	}
	if (!*p)
		c=0;
	else if (c)
		c--;
	return c;
	
}

/* get_valid_field: return pos of num,alpha,space */
int
get_valid_field(char *s){
	
	char *p=s;

	while (*p){
		if (*p == ' ')
			break;
		else if (*p >= '0' && *p <= '9')
			break;
		else if (*p >= 'A' && *p <= 'Z')
			break;
		else if (*p >= 'a' && *p <= 'z')
			break;
		p++;
	}
	if (!*p)
		p=s;
	return p-s;
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
