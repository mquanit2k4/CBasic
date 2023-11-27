#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	char malop[11];
	char mahp[11];
	struct node* next;
};

typedef struct node* Node;


void printList(Node head)
{
	while(head != NULL)
	{
		printf("%s\t%s\n",head->malop,head->mahp);
		head = head->next;
	}
}
Node makeNode(char malop[] , char mahp[])
{
	Node newNode = (Node)malloc(sizeof(struct node));
	strcpy(newNode->malop,malop);
	strcpy(newNode->mahp,mahp);
	newNode->next = NULL;
	return newNode;
}

Node insertHead(Node head, char malop[] , char mahp[] )
{
	Node tmp = makeNode(malop,mahp);
	tmp->next = head;
	return tmp;
}

Node insertLast(Node head , char malop[] , char mahp[])
{
	Node q = makeNode(malop,mahp);
	if (head == NULL)
		return q;
	Node p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = q;
	return head;
}

Node deleteClass(Node head , char malop[])
{
	if (head == NULL)
		return NULL;
	if (strcmp(head->malop,malop) == 0)
	{
		Node tmp = head;
		head = head->next;
		free(tmp);
		head = deleteClass(head, malop);
		return head;
	}
	head->next = deleteClass(head->next, malop);
	return head;
}

int findClass (Node head, char mahp[])
{
	Node res = NULL;
	while (head != NULL)
	{
		if 
	}
}
int main() {
    char malop[11];
    char mahp[11];
    
    FILE *f3 = fopen("C:\\Users\\admin\\Desktop\\C Basic\\Schedule.txt", "r");
    if (f3 == NULL) {
        printf("Khong the mo tep.");
        return 1;
    }
    Node head = NULL;
    while (fscanf(f3, "%s\t%s", malop, mahp) == 2) {
        head = insertLast(head, malop,mahp);
    }
    
    while(1)
    {
    	printf("-------------------------\n");
    	printf("1. Hien thi thoi khoa bieu\n");
    	printf("2. Tim kiem thong tin\n");
    	printf("3. Them lop vao dau danh sach\n");
    	printf("4. Them lop vao cuoi danh sach\n");
    	printf("5. Xoa thong tin\n");
    	printf("6. Luu ra file\n");
    	printf("7. Dem so luong lop\n");
    	printf("8. Exit\n");
    	printf("-------------------------\n");
    	printf("Vui long chon chuc nang:\n");
    	int choice;
    	scanf("%d", &choice);
    	if (choice == 1)
    	{
    		printList(head);
		}
		else if (choice == 2)
    	{
    		printf("Vui long nhap ma hoc phan: ");
    		scanf("%s", mahp);
    		findSub(head,mahp);
		}
		else if (choice == 3)
		{
			printf("Vui long nhap ma lop: ");
			scanf("%s", malop);
			printf("Vui long nhap ma hoc phan: ");
			scanf("%s", mahp);
			head = insertHead(head,malop,mahp);
			printList(head);
		}
		else if (choice == 4)
		{
			printf("Vui long nhap ma lop: ");
			scanf("%s", malop);
			printf("Vui long nhap ma hoc phan: ");
			scanf("%s", mahp);
			head = insertLast(head,malop,mahp);
			printList(head);
		}
		else if (choice == 5)
		{
			printf("Vui long nhap ma hoc lop: ");
    		scanf("%s", malop);
    		head = deleteClass(head,malop);
    		printList(head);
		}
		else if (choice == 6)
		{
			FILE *f1=fopen("C:\\Users\\admin\\Desktop\\C Basic\\Schedule1.txt","w");
            for (Node p = head; p != NULL; p = p->next)
			{
                fprintf(f1,"%s\t",p->malop);
                fprintf(f1,"%s",p->mahp);
                fprintf(f1,"\n");
			}
        	fclose(f1);
		}
		else if (choice == 7)
		{
			
		}
		else if (choice == 8)
			break;
	}
    fclose(f3);

    return 0;
}

