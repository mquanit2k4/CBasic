#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)

struct node {
	int data;
	node *next;
};

typedef struct node* Node;

int sizeList (Node head)
{
	int count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}


void duyetDS (Node head)
{
	while (head != NULL)
	{
		cout << head->data <<' ';
		head = head->next;	
	}	
	cout<<endl;
} 
Node makeNode(int x)
{
	Node newNode = new node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void insertHead (Node &head, int x)
{
	Node tmp = makeNode(x);
	tmp->next = head;
	head = tmp;
}

void insertLast (Node &head, int x)
{
	Node tmp = makeNode(x);
	if (head == NULL)
	{
		head = tmp;
		return;
	}
	Node i = head; // phai chay bang bien trung gian, neu chay = head sau khi chay xong head se bi thay doi, khi do se mat cac node phia truoc
	while (i->next != NULL)
		i = i->next;
	i->next = tmp;
}

void insertMiddle (Node &head , int x, int pos)
{
	int n = sizeList(head);
	Node tmp = makeNode(x);
	if (pos < 1 || pos > n)
		return;
	if (pos == 1)
	{
		insertHead(head, x);
		return;
	}
	Node j = head;
	for (int i = 1 ; i <= pos - 2 ; i++)
		j = j->next;
	tmp->next = j->next;
	j->next = tmp;
}


void deleteHead (Node &head)
{
	if (head == NULL)
		return;
	Node tmp = head;
	head = head->next;
	delete tmp;
}

void deleteLast (Node &head)
{
	int n = sizeList(head);
	if (n == 0)
		return;
	if (n == 1)
	{
		delete head;
		return;
	}
	Node tmp = head;
	for (int i = 1; i <= n-2 ; i++)
		tmp = tmp->next;
	tmp->next = NULL;
		
}

void deleteMiddle (Node &head, int pos)
{
	int n = sizeList(head);
	if (pos < 1 || pos > n)
		return;
	if (pos == 1)
	{
		deleteHead(head);
		return;
	}
	if (pos == n)
	{
		deleteLast(head);
		return;
	}		
	Node tmp = NULL;
	Node j = head;
	for (int i = 1; i <= pos - 2 ; i++)
		j = j->next;
	tmp = j->next;
	j->next = tmp->next;
	delete tmp;
}
int main()
{	
	Node head = NULL;
	while(1)
	{
		cout << "------------------LINKED LIST------------------\n";
		cout << "1. Duyet danh sach lien ket\n";
		cout << "2. Them 1 node vao dau DSLK\n";
		cout << "3. Them 1 node vao cuoi DSLK\n";
		cout << "4. Them 1 node vao giua DSLK\n";
		cout << "5. Xoa 1 node o dau DSLK\n";
		cout << "6. Xoa 1 node o cuoi DSLK\n";
		cout << "7. Xoa 1 node o giua DSLK\n";
		cout << "8.EXIT\n";
		cout << "-----------------------------------------------\n";
		cout << "Nhap lua chon cua ban: "; int lc; cin >> lc;
		if (lc == 1)
			duyetDS(head);
		else if (lc == 2)
		{
			cout << "Nhap gia tri can them: "; int x; cin >> x;
			insertHead(head, x);
		}
		else if (lc == 3)
		{
			cout << "Nhap gia tri can them: "; int x; cin >> x;
			insertLast(head, x);
		}
		else if (lc == 4)
		{
			cout << "Nhap gia tri can them: "; int x; cin >> x;
			cout << "Nhap vi tri can them: "; int pos; cin >> pos;
			insertMiddle(head, x, pos);
		}
		else if(lc == 5)
		{
			deleteHead(head);
		}
		else if (lc == 6)
		{
			deleteLast(head);
		}
		else if (lc == 7)
		{
			cout << "Nhap vi tri can xoa: "; int vt; cin >> vt;
			deleteMiddle (head, vt);
		}
		else if(lc == 8)
			return 0;
	}

	return 0;	
}
