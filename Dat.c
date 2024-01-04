#include <stdio.h>
#include <stdlib.h>
void sort(int a[], int n)
{
    for(int i = 0 ; i < n-1; i++)
    {
        for(int j = i ; j < n; j++)
        {
            if(a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp; 
            }
        }
    }
}
int main()
{
    int n = 20;
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int check = 0;
    printf("Cac vi tri co gia tri = 10 la: ");
    for (int i = 0 ; i < n; i++)
    {
        if(a[i] == 10)
        {
            check = 1;
            printf("%d ", i);
        }
    }
    printf("\n");
    if (check == 0)
        printf("Khong co!\n");
    sort(a,n);
    int average;
    int sum = 0;
    for(int i = 0 ; i < n; i++)
        sum += a[i];
    average = sum / n;
    printf("Gia tri trung binh cua day la: %d\n", average);
    // Insert average into array follow right position following accending
    int i = 0;
    while(a[i] < average)
        i++;
    for(int j = n-1; j >= i; j--)
    {
        a[j+1] = a[j];
    }
    a[i] = average;
    printf("Day sau khi chen gia tri trung binh la: ");
    for(int j = 0; j < n; j++)
        printf("%d ", a[j]);
    return 0;
}