#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct thongtin{
	char hotelID[4];
	int numOfPeople;
	int roomID;
	char date[13];
	int numOfChild;
	char requireID[8];
}LIST;

struct node{
	LIST id;
	struct node* leftChild;
	struct node* rightChild;
};

typedef struct node* Node;

Node makeNode(LIST x)
{
	Node tmp = (Node)malloc(sizeof(struct node));
	tmp->id = x;
	tmp->leftChild = NULL;
	tmp->rightChild = NULL;
	return tmp;
}

Node insert(Node r, LIST x)
{
	if (r == NULL)
	{
		Node tmp = makeNode(x);
		r = tmp;
		return r;
	}
	else if (strcmp(r->id.requireID, x.requireID) > 0)
		r->leftChild = insert(r->leftChild,x);
	else if (strcmp(r->id.requireID, x.requireID) < 0)
		r->rightChild = insert(r->rightChild,x);
	return r;
}

Node findMin(Node r)
{
	if (r == NULL)
		return NULL;
	if (r->leftChild == NULL)
		return r;
	else
		return findMin(r->leftChild);
}

Node del(Node r, LIST v)
{
	if (r == NULL)
		return NULL;
	if (strcmp(r->id.requireID, v.requireID) > 0)
		r->leftChild = del(r->leftChild,v);
	else if (strcmp(r->id.requireID, v.requireID) < 0)
		r->rightChild = del(r->rightChild,v);
	else
	{
		if (r->leftChild == NULL && r->rightChild == NULL)
		{
			free(r);
			return NULL;
		}
		else if (r->leftChild == NULL)
		{
			Node tmp = r->rightChild;
			free(r);
			return tmp;
		}
		else if (r->rightChild == NULL)
		{
			Node tmp = r->leftChild;
			free(r);
			return tmp;
		}
		else
		{
			Node tmp = findMin(r->rightChild);
			r->id = tmp->id;
			r->rightChild = del(r->rightChild,tmp->id);
		}
	}
	return r;
	
}
int n;
void preOrder(Node r)
{
	FILE *f4 = fopen("C:\\Users\\admin\\Desktop\\C Basic\\booking_orders.txt", "w");
	if (r == NULL)
		return;
	fscanf(f4, "%s %d %d %s %s %d\n", r->id.requireID , &r->id.numOfPeople, &r->id.roomID , r->id.hotelID, r->id.date, &r->id.numOfChild);
	preOrder(r->leftChild);
	preOrder(r->rightChild);
}

Node search(Node r, char v[])
{
	if (r == NULL)
		return NULL;
	if (strcmp(r->id.requireID , v) > 0)
		return search(r->leftChild,v);
	else if (strcmp(r->id.requireID , v) < 0)
		return search(r->rightChild,v);
	else
		return r;
}


void freeTree(Node r) {
    if (r == NULL) {
        return;
    }
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}

int main()
{
	Node r = NULL;
	int n;
	FILE *f3 = fopen("C:\\Users\\admin\\Desktop\\C Basic\\booking_orders.txt", "r");
	if (f3 == NULL) {
		printf("Khong the mo tep.");
		return 1;
	}
	fscanf(f3, "%d", &n);
	LIST infor[n+1];
	for(int i = 0 ; i < n ; i++)
	{
		fscanf(f3, "%s %d %d %s %s %d", infor[i].requireID , &infor[i].numOfPeople, &infor[i].roomID , infor[i].hotelID, infor[i].date, &infor[i].numOfChild);
		r = insert(r, infor[i]);
	}
	fclose(f3);
	int choice = 0;
	while(1)
	{
		printf("----------------------------\n"
		   "Chuong trinh quan ly dat phong\n"
           "Vui long chon mot trong cac chuc nang sau\n"
           "[1] Doc du lieu tu file log\n"
           "[2] Kiem tra so luong yeu cau khong hop le\n"
           "[3] Tra cuu theo ma yeu cau\n"
           "[4] Thay doi yeu cau\n"
           "[5] Huy yeu cau\n"
           "[6] Luu danh sach yeu cau ra file\n"
           "[7] (OP1) Thong ke khach san duoc ua thich nhat\n"
           "[8] (OP2) Ngay khong hop le\n"
           "[9] (OP3) Ngay khong hop le\n"
           "[10] Thoat\n"
		   "----------------------------\n");
    	scanf("%d", &choice);
		if (choice == 1)
		{
			printf("So yeu cau doc duoc la %d\n", n);
			for(int i = 0 ; i < n ; i++)
				printf("%s %d %d %s %s %d\n", infor[i].requireID , infor[i].numOfPeople, infor[i].roomID , infor[i].hotelID, infor[i].date, infor[i].numOfChild);
		}
		else if (choice == 2)
		{
			int check = 0;
			for (int i = 0 ; i < n ; i++)	
				if (infor[i].numOfPeople - infor[i].numOfChild < infor[i].numOfChild)
					check++;
			printf("So luong yeu cau khong hop le la %d\n", check);
		}
		else if (choice == 3)
		{
			char maYeuCau[8];
			printf("Nhap ma yeu cau can tim: ");
			scanf("%s", maYeuCau);
			Node tmp = search(r, maYeuCau);
			if (tmp != NULL)
			{
				printf("Thong tin yeu cau can tim la: %s %d %d %s %s %d\n", tmp->id.requireID , tmp->id.numOfPeople, tmp->id.roomID , tmp->id.hotelID, tmp->id.date, tmp->id.numOfChild);
			}
			else
				printf("Not Found\n");
		}
		else if (choice == 4)
		{
			printf("Nhap ma yeu cau can thay doi: ");
			char maYeuCau[8];
			scanf("%s", maYeuCau);
			Node tmp = search(r, maYeuCau);
			if (tmp != NULL)
			{
				printf("Thong tin yeu cau can thay doi la: %s %d %d %s %s %d\n", tmp->id.requireID , tmp->id.numOfPeople, tmp->id.roomID , tmp->id.hotelID, tmp->id.date, tmp->id.numOfChild);
				while(1)
				{
					int luachon;
					printf("Ban chi cho the thay doi cac thong tin sau:\n"
						   "[1] So nguoi\n"
						   "[2] So tre em\n"
						   "[3] Ngay dat phong\n"
						   "[4] Thoat\n");
					printf("Vui long chon thong tin can thay doi: ");
					scanf("%d", &luachon);
					if (luachon == 1)
					{
						printf("Nhap so nguoi: ");
						scanf("%d", &tmp->id.numOfPeople);
						if (tmp->id.numOfPeople - tmp->id.numOfChild < tmp->id.numOfChild)
							printf("So luong nguoi thay doi khong hop le\n");

					}
					else if (luachon == 2)
					{
						printf("Nhap so tre em: ");
						scanf("%d", &tmp->id.numOfChild);
						if (tmp->id.numOfPeople - tmp->id.numOfChild < tmp->id.numOfChild)
							printf("So luong tre em thay doi khong hop le\n");
					}
					else if (luachon == 3)
					{
						printf("Nhap ngay dat phong: ");
						scanf("%s", tmp->id.date);
		
					}
					else if (luachon == 4)
						break;
				}
				
			}
			else
				printf("Not Found\n");
		}
		else if (choice == 5)
		{
			printf("Nhap ma yeu cau can huy: ");
			char maYeuCau[8];
			scanf("%s", maYeuCau);
			Node tmp = search(r, maYeuCau);
			if (tmp != NULL)
			{
				printf("Thong tin yeu cau can huy la: %s %d %d %s %s %d\n", tmp->id.requireID , tmp->id.numOfPeople, tmp->id.roomID , tmp->id.hotelID, tmp->id.date, tmp->id.numOfChild);
				r = del(r, tmp->id);
				n--;
				printf("%d\n", n);
				printf("Huy yeu cau thanh cong\n");
			}
			else
				printf("Not Found\n");
		}
		else if (choice == 6)
		{ 	
			FILE *f4 = fopen("C:\\Users\\admin\\Desktop\\C Basic\\booking_orders.txt", "w");
			if (f4 == NULL) {
				printf("Could not open file for writing.\n");
				return 1;
			}
			fprintf(f4, "%d\n", n);
			preOrder(r);
			fclose(f4);
			printf("So luong yeu cau da duoc ghi vao file la %d\n", n);
		}
		else if (choice == 7 || choice == 8 || choice == 9 || choice == 10)
		{
			free(r);
			break;
		}

	}
}