#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int data;
	struct node *next;	
};

typedef struct node* Node;

Node makeNode(int x)
{
	Node newNode = (Node)malloc(sizeof(struct node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void duyetEven (Node head)
{
	while (head != NULL)
	{
		if (head->data % 2 == 1)
		{
			printf("%d ", head->data);	
		}
		head = head->next;
	}	
} 

void duyetOdd (Node head)
{
	while (head != NULL)
	{
		if (head->data % 2 == 0)
		{
			printf("%d ", head->data);
				
		}
		head = head->next;
	}	
} 

Node insertHead (Node head, int x)
{
	Node i = head;
	int check = 0;
	while (i != NULL)
	{
		if (i->data == x)
		{
			check = 1; 
			break;
		}
		i = i->next;
	}
	if (check)
		return head;
	else if (x > 0)
	{
		Node tmp = makeNode(x);
		tmp->next = head;
		head = tmp;
	}
	else 
		return head;
	return head;
}

//Node insertLast(Node head, int x)
//{
//	Node q = makeNode(x);
//	if(head == NULL)
//		return q;
//	
//	Node p = head;
//	while(p->next != NULL)
//		p = p->next;
//	p->next = q;
//	return head;
//}

Node insertLast (Node head , int x)
{
	Node i = head;
	int check = 0;
	while (i != NULL )
	{
		if (i->data == x)
		{
			check = 1; 
			break;
		}
		i = i->next;
	}
	if (check)
		return head;
	else if (x > 0)
	{
		Node tmp = makeNode(x);
		if (head == NULL)
		{
			head = tmp;
			return head;
		}
		Node i = head; // phai chay bang bien trung gian, neu chay = head sau khi chay xong head se bi thay doi, khi do se mat cac node phia truoc
		while (i->next != NULL)
			i = i->next;
		i->next = tmp;
	}
	else 
		return head;
	return head;
}

void duyetDS (Node head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;	
	}	
} 

void freeList(Node head){
	Node tmp;
	while(head!=NULL){
		tmp=head->next;
		free(head);
		head=tmp;
	}
}

int main()
{
	Node r = NULL;
	while(1)
	{
		char choice[20];
		scanf("%s", choice);
		if (strcmp(choice,"InsertHead") == 0)
		{
			int x;
			scanf("%d", &x);
			r = insertHead(r,x);
		}
		else if (strcmp(choice,"InsertTail") == 0)
		{
			int x;
			scanf("%d", &x);
			r = insertLast(r,x);
		}
		else if (strcmp(choice, "Print") == 0)
		{
			int x;
			scanf("%d", &x);
			if (x == 0)
			{
				duyetDS(r);
				freeList(r);
				return 0;
			}
			else
			{
				duyetOdd(r);
				duyetEven(r);
				freeList(r);
				return 0;
			}
		}
	}
}