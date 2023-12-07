#include <stdio.h>
#include <stdlib.h>
void selectionSort(int A[], int N) 
{
	for(int k = 1; k <= N; k++)
	{
		int min = k;
		for(int j = k+1; j <= N; j++)
		{
			if(A[min] > A[j]) min = j;
		}
		int tmp = A[min]; 
		A[min] = A[k]; 
		A[k] = tmp;
	}
}

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


void bubbleSort(int A[], int N) {
    int swapped;

    do {
        swapped = 0;
        for (int i = 1; i < N; i++) {
            if (A[i] > A[i + 1]) {
                int tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                swapped = 1;
            }
        }
    } while (swapped == 1);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    bubbleSort(a, n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

