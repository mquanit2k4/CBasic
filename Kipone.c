#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int generate()
{
    // trả về số nguyên có giá trị nằm trong [-100;100]
    // Các giá trị thay đổi mỗi lần chạy

    return rand() % 201 - 100;
}

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

LIST* insertLast(LIST *L, int x)
{
    LIST *p, *q;
    p = makeNode(x);
    if(L == NULL)
        L = p;
    else
    {
        q = L;
        while(q->next != NULL)
            q = q->next;
        q->next = p;
    }
    return L;
}
LIST* createList(int n)
{
	
    for(int i = 0; i < n; i++)
    {
        int x = generate();
        L = insertLast(L, x);
    }
    return L;
}

int count(LIST* L)
{
    int dem = 0;
    while(L != NULL)
    {
        if (L->data % 2 == 0)
            dem++;
        L = L->next;
    }
    return dem;
}


LIST* deleteEven(LIST *L)
{
    LIST *p, *q;
    while(L != NULL && L->data % 2 == 0)
    {
        p = L;
        L = L->next;
        free(p);
    }
    if(L == NULL)
        return L;
    p = L;
    q = L->next;
    while(q != NULL)
    {
        if(q->data % 2 == 0)
        {
            p->next = q->next;
            free(q);
        }
        else
            p = q;
        q = p->next;
    }
    return L;

}

void sort(LIST* L)
{
	LIST *p, *q;
    int temp;
    for(p = L; p != NULL; p = p->next)
    {
        for(q = p->next; q != NULL; q = q->next)
        {
            if(p->data > q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

void display(LIST* L)
{
    LIST *p;
    for(p = L; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}
int main()
{
    int choice;
    srand(time(NULL));
    while(1)
    {
        printf("-------------------------\n");
    	printf("1. Tao danh sach\n");
    	printf("2. Hien thi so luong phan tu chan\n");
    	printf("3. Xoa cac phan tu chan\n");
    	printf("4. Sap xep danh sach tang dan\n");
        printf("5. Hien thi danh sach\n");
    	printf("6. Quit\n");
    	printf("-------------------------\n");
    	printf("Vui long chon chuc nang:\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
        	int n;
        	printf("Vui long nhap so phan tu can tao: ");
    		scanf("%d", &n);
            L = createList(n);
            printf("Tao danh sach thanh cong\n");
        }
        else if (choice == 2)
        {
            int res = count(L);
            printf("So luong phan tu chan trong danh sach la: %d\n", res);
        }
        else if (choice == 3)
        {
            L = deleteEven(L);
            printf("Xoa cac phan tu chan thanh cong\n");
        }
        else if (choice == 4)
        {
            sort(L);
            printf("Sap xep danh sach thanh cong\n");
        }
        else if (choice == 5)
        {
            printf("Danh sach lien ket hien tai la:\n");
            display(L);
        }
        else if (choice == 6)
        {
            break;
        }
    }
    return 0;
}