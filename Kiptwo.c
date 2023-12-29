#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node LIST;
LIST *L;

LIST* makeNode(int x)
{
    LIST *p;
    p = (LIST*)malloc(sizeof(LIST));
    p->data = x;
    p->next = NULL;
    return p;
}

LIST* insertHead(LIST *L, int x)
{
    LIST *p;
    p = makeNode(x);
    if(L == NULL)
        L = p;
    else
    {
        p->next = L;
        L = p;
    }
    return L;
}

int generate()
{
    return rand() %201 - 100;
}

LIST* createList(int n)
{
    for(int i = 0; i < n; i++)
    {
        int x = generate();
        L = insertHead(L, x);
    }
    return L;
}

void sort (LIST* L)
{
    LIST *p, *q;
    int temp;
    for(p = L; p != NULL; p = p->next)
        for(q = p->next; q != NULL; q = q->next)
            if(p->data < q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
}

void reverse(LIST **L)
{
    if (*L == NULL || (*L)->next == NULL)
        return;
    LIST *p1 = NULL;
    LIST *p2 = *L;
    LIST *p3 = (*L)->next;
    while(p2 != NULL)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        if (p3 != NULL) p3 = p3->next;
    }
    *L = p1;
}

void display(LIST *L)
{
    while(L != NULL)
    {
        printf("%d ", L->data);
        L = L->next;
    }
    printf("\n");
}
int main()
{
    srand(time(NULL));
    int choice;
    while(1){
        printf("-------------------------\n");
    	printf("1. Tao danh sach\n");
    	printf("2. Dao nguoc danh sach\n");
    	printf("3. Sap xep danh sach giam dan\n");
        printf("4. Hien thi danh sach\n");
    	printf("5. Quit\n");
    	printf("-------------------------\n");
    	printf("Vui long chon chuc nang:\n");
        scanf("%d", &choice);
        if(choice == 1)
        {
            int n;
            printf("Nhap so luong phan tu: ");
            scanf("%d", &n);
            L = createList(n);
            printf("Tao danh sach thanh cong\n");
        }
        else if(choice == 2)
        {
            reverse(&L);
            printf("Dao nguoc danh sach thanh cong\n");
        }
        else if(choice == 3)
        {
            sort(L);
            printf("Sap xep danh sach thanh cong\n");
        }
        else if(choice == 4)
        {
            printf("Danh sach hien tai la: ");
            display(L);
        }
        else if(choice == 5)
        {
            break;
        }
    }
    return 0;
}