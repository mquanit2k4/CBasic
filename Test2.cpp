#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

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
int main() {
    int n, m, M;
    int a[1001];
     srand(time(NULL)); 
 
    printf("Nhap so gia tri (n): ");
    scanf("%d", &n);
    printf("Nhap gia tri m: ");
    scanf("%d", &m);
    printf("Nhap gia tri M: ");
    scanf("%d", &M);
 
    FILE* fptr = fopen("arr-n.txt", "w");
 
    if (fptr == NULL) {
        fprintf(stderr, "Khong the mo tep tin.\n");
        return 1;
    }
 
    fprintf(fptr, "%d\n", n);
 
    for (int i = 1; i <= n; i++) {
        a[i] = generateRandomNumber(m, M);
    }
 	selectionSort(a,n);
 	for (int i = 1; i <= n; i++) {
 		fprintf(fptr, "%d ", a[i]);
    }
 	
    fclose(fptr);
 
    printf("Da luu du lieu vao tep tin arr-n.txt.\n");
 
    return 0;
}