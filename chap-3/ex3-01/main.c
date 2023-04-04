/*
	page-58
	EX3-1. Our binary search  makes two 
	tests inside the loop, when one would 
	suffice (at the price of more test
	outside). Write a version withe only
	one test inside the loop and
	measure the difference in run-time
*/


/* 
 * Array should be in increasing order
*/

#include <stdio.h>

int binsearch(int x, int v[], int n);

int
main(void){
	
	int sort_array[10] = {1,3,5,7,8,100,101,200,300,301};
	int pos = binsearch(100, sort_array, 10);
	
	if (pos != -1)
		printf("%d\n", sort_array[pos]);
	return 0;
}

/* binsearch : find x in v[0] <=v[1]..v<=[n-1] */
int
binsearch(int x, int v[], int n){
	
	/* run , both measure the timings */
	/* exercise */

	int low, high, mid;

	low=0;
	high=n-1;
	while (low <= high){
		mid = (low+high)/2;
		if (v[mid] == x)
			return mid;
		else if (x < v[mid])
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;

/* code from the book */
/*
   int low, high, mid;

	low=0;
	high=n-1;
	while (low <= high){
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid-1;
		else if (x > v[mid])
			low = mid+1;
		else
			return mid;
	}
	return -1;
*/

}



