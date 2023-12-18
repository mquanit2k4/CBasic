#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int l , int m , int r)
{
	int i,j,k;
	// So phan tu mang ben trai
	int n1 = m - l + 1;
	
	// So phan tu mang ben phai
	int n2 = r - m;
	
	// Khai bao 2 mang tam
	int L[n1], R[n2];
	
	// Copy du lieu sang cac mang tam
	for (i = 0; i < n1 ; i++)
		L[i] = a[l+i];
	
	for (j = 0; j < n2 ; j++)
		R[j] = a[m+1+j];
		
	// Gop 2 mang vao mang a
	i = 0 ; j = 0;
	k = l;
	while(i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;	
	}	
	
	// TH 2 mang chua tron het phan tu
	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;	
	}
	
	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int a[] , int l , int r)
{
	if (l < r)
	{
		int m = l + (r-l)/2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		merge(a, l, m, r);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	mergeSort(a,0,n-1);
	for (int i = 0; i < n ; i++)
		printf("%d " ,a[i]);
	return 0;
}