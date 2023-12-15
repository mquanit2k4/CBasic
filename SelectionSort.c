#include <stdio.h>
#include <stdlib.h>
void swap (int *a, int *b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void selectionSort(int a[] , int n)
{
	int min;
	for(int i = 0; i < n - 1 ; i++)
	{
		min = i;
		for (int j = i + 1 ; j < n; j++)
			if (a[j] < a[min])
				min = j;
		if (min != i)
			swap(&a[min], &a[i]);	
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	selectionSort(a,n);
	for (int i = 0; i < n ; i++)
		printf("%d " ,a[i]);
}