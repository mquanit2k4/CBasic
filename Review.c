//#include <stdio.h>
//#include <stdlib.h>
//
//void inra(int X[] , int n)
//{
//	for (int i = 1; i <= n ; i ++)
//	{
//		printf("%d ", X[i]);
//	}
//	printf("\n");
//}
//
//int tong (int X[], int n)
//{
//	int sum = 0;
//	for( int i = 1; i <= n; i ++)
//		sum += X[i];
//	return sum;
//}
//
//void cogangtim(int k , int m , int X[], int n)
//{
//	if (X[k] != 0)
//	{
//		if (k == n)
//		{
//			if (tong(X,n) == 10)
//				inra(X,n);
//		}
//		else
//			cogangtim(k+1, m , X, n);
//	}
//	else
//	{
//		for (int j = -9 ; j <= 9 ; j++)
//		{
//			if (j == 0) continue;
//			X[k] = j;
//			if (k == n)
//			{
//				if (tong(X,n) == 10)
//					inra(X,n);
//			}
//			else
//				cogangtim(k+1, m, X, n);
//			X[k] = 0;
//		}
//	}
//}
//
//int main()
//{
//	int n, X[1001];
//	int m =2;
//	scanf("%d", &n);
//	for(int i = 1;  i<= n; i++)
//		scanf("%d", &X[i]);
//	cogangtim(1,m,X,n);
//	return 0;
//}



#include <stdio.h>
#include <stdlib.h>

typedef struct _LNode{
	int info;
	struct _LNode* next;
} Node;

void duyetList(Node * head)
{
	while( head != NULL)
	{
		printf("%d ", head->info);
		head = head->next;
	}
}

Node * makeNode(int x)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->info = x;
	newNode->next = NULL;
	return newNode;
}

void insertLast(Node** head, int x)
{
	Node * tmp = makeNode(x);
	if (*head == NULL)
	{
		
		*head = tmp;
		return;
	}
	Node *i = *head;
	while (i->next != NULL)
		i = i->next;
	i->next = tmp;
}
Node * xoa (Node *head)
{
	Node* tmp = head;
	Node* prev = NULL;
	while(tmp != NULL)
	{
		if (tmp->info % 2 != 0)
		{
			if (prev == NULL)
			{
				head = tmp->next;
				free(tmp);
				tmp = head;
			}
			else
			{
				prev->next = tmp->next;
				free(tmp);
				tmp = prev->next;
			}
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
	return head;
}

Node * tinhtonghaids(Node * head1 , Node* head2)
{
	Node * res = NULL;
	while (head1 != NULL && head2 != NULL)
	{
		
	}
}
int main()
{
	Node * head = NULL;
	int n, a[1001];
	scanf("%d", &n);
	for(int i = 0;  i < n ; i++)
	{
		scanf("%d", &a[i]);
		insertLast(&head,a[i]);
	}
	head = xoa(head);
	duyetList(head);
	return 0;	
		
}