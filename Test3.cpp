#include<stdio.h>
#include<stdlib.h>

void insertionSort(int A[], int N) 
{
	for(int k = 2; k <= N; k++)
	{
		int last = A[k];
		int j = k;
		while(j > 1 && A[j-1] > last)
		{
			A[j] = A[j-1];
			j--;
		}
		A[j] = last;
	}
}



int main()
{
	int n;
	scanf("%d", &n);
	int a[n+1];
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	insertionSort(a,n);
	for(int i = 1 ; i <= n ; i++)
		printf("%d ", a[i]);
	return 0;
}