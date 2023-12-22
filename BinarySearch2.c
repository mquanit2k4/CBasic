#include <stdio.h>
#include <stdlib.h>

int compare(const void *a , const void *b)
{
	return (*(int*)a - *(int*)b);
}

int binary_search(int a[], int n , int x)
{
	int l = 0;
	int r = n - 1;
	while (l <= r)
	{
		int mid = l+ (r-l)/2;
		if (a[mid] == x)
			return mid;
		else if (a[mid] < x)
			l = mid + 1;
		else 
			r = mid - 1;
	}
	return -1;
}

int main()
{
	int a[] = {12,1,2,4,5,23,6,7,6,34,76,2,32,5,65};
	int n = sizeof(a) / sizeof(a[0]);
	qsort(a,n, sizeof(int), compare);
	for (int i = 0 ; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	int x = 6;
	int res = binary_search(a,n,x);
	printf("%d", x);
}