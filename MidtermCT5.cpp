#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char time[9];
	char bienso[12];
	struct node* next;
};

typedef struct node* Node;

Node makeNode(char time[] , char bienso[])
{
	Node newNode = (Node)malloc(sizeof(struct node));
	strcpy(newNode->time,time);
	strcpy(newNode->bienso,bienso);
	newNode->next = NULL;
	return newNode;
}

Node insertLast(Node head, char time[], char bienso[])
{
	Node q = makeNode(time, bienso);
	if (head == NULL)
		return q;
	Node p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = q;
	return head;
}

Node deleteXe(Node head , char bienso[])
{
	if (head == NULL)
		return NULL;
	if (strcmp(head->bienso,bienso) == 0)
	{
		Node tmp = head;
		head = head->next;
		free(tmp);
		head = deleteXe(head, bienso);
		return head;
	}
	head->next = deleteXe(head->next, bienso);
	return head;
}

void list(Node head)
{
	while(head != NULL)
	{
		printf("%s\n",head->bienso);
		head = head->next;
	}
}

//void find(Node *head, char *bienso[])
//{
//	Node *i = head;
//	int vt = 0;
//	int check = 0;
//	for ( *i = head ; *i != NULL ; *i = *i -> next)
//	{
//		if (strcmp(*i->bienso,bienso) == 0)
//		{
//			printf("%d", vt);
//			check = 1;
//		}
//		vt +=1;
//	}
//	if (check == 0)
//		print("-1");
//}

Node find(Node head, char bienso[])
{
	Node i = head;
	for (i = head; i != NULL ; i = i->next)
		if (strcmp(i->bienso,bienso) == 0)
			return i;
	return NULL;
}

int count(Node head)
{
	Node i = head;
	int res = 0;
	while(i != NULL)
	{
		char check[5];
		strncpy(check,i->bienso,4);
		if (strncmp(check,"xxxx",4) != 0)
			res+=1;
		i = i->next;
	}
	return res;
}

int bill(Node head, char time[] , char bienso[])
{
	Node i = find(head, bienso);
	if (i == NULL)
		return -1;
	else
	{
		char check[5];
		strncpy(check,i->bienso,4);
		if (strncmp(check,"xxxx",4) != 0)
		{
			if (strcmp(time,"05:59:59") > 0 && strcmp(time,"18:00:00") < 0)
				return 3;
			else
				return 5;
		}
		else
			return 0;
	}
}
int billXedap(Node head, char time[] , char bienso[])
{
	Node i = find(head, bienso);
	if (i == NULL)
		return -1;
	else
	{
		char check[5];
		strncpy(check,i->bienso,4);
		if (strncmp(check,"xxxx",4) == 0)
		{
			if (strcmp(time,"05:59:59") > 0 && strcmp(time,"18:00:00") < 0)
				return 1;
			else
				return 2;
		}
		else
			return 0;
	}
}
int main()
{
	int tien = 0;
	Node head = NULL;
	char time[9], bienso[12];
	char yeucau[100];
	while(scanf("%s",time) && strcmp(time,"*"))
	{
		scanf(" %s", bienso);
		head = insertLast(head,time,bienso);
	}
	while(scanf("%s", yeucau) && strcmp(yeucau,"***"))
	{
		if (strcmp(yeucau,"list") == 0)
			list(head);
		else if (strcmp(yeucau,"find") == 0)
		{
			scanf(" %s", bienso);
			Node i = find(head, bienso);
			if (i == NULL)
				printf("-1\n");
			else
			{
				int ans = 0;
				Node t = head;
				while (t != NULL)
				{
					if (strcmp(t->bienso,i->bienso) == 0)
					{
						printf("%d\n", ans);
						break;
					}
					ans++;
				}
			}
		}
		else if (strcmp(yeucau,"in") == 0)
		{
			scanf("%s %s", time, bienso);
			Node i = find(head, bienso);
			if ( i == NULL)
			{
				head = insertLast(head, time , bienso);
				printf("1\n");
			}
			else
				printf("0\n");
		}
		else if (strcmp(yeucau,"out") == 0)
		{
			scanf("%s %s", time, bienso);
			Node i = find(head, bienso);
			if ( i == NULL)
			{
				printf("0\n");
			}
			else
			{
				tien = tien + bill(head,time,bienso) + billXedap(head,time,bienso);
				deleteXe(head,bienso);
				printf("1\n");
			}
		}
		else if (strcmp(yeucau,"cnt-moto") == 0)
		{
			printf("%d\n", count(head));
		}
		else if (strcmp(yeucau,"bill") == 0)
		{
			scanf("%s %s",time , bienso);
			printf("%d\n", bill(head,time ,bienso));
		}
		else if (strcmp(yeucau,"billall") == 0)
		{
			printf("%d\n",  tien);
		}
	}
	return 0;
}