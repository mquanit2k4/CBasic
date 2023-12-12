#include<stdio.h>
#include<stdlib.h>
typedef int datatype;

struct _TNode{
    datatype inf;
    struct _TNode* leftMostChild;
    struct _TNode* rightSibling;
};

typedef struct _TNode* TNode;

TNode makeNode(datatype x)
{
    TNode newNode = (TNode)malloc(sizeof(struct _TNode));
    newNode->inf = x;
    newNode->leftMostChild = NULL;
    newNode->rightSibling = NULL;
    return newNode;
}

void inOrder(TNode r)
{
    if(r == NULL) return;
	
	TNode p = r->leftMostChild;
	inOrder(p);
	printf("%d ",r->inf);
	
	if(p!=NULL) p = p->rightSibling;
	while(p!=NULL){
		inOrder(p);
		p = p->rightSibling;
	}
}

void postOrder(TNode r)
{
    if(r == NULL) return;
	
	TNode p = r->leftMostChild;
	while(p!=NULL){
		postOrder(p);
		p = p->rightSibling;
	}

	printf("%d ",r->inf);
}

void preOrder(TNode r)
{
    if(r == NULL) return;
	printf("%d ",r->inf);
	
	TNode p = r->leftMostChild;
	while(p!=NULL){
		preOrder(p);
		p = p->rightSibling;
	}
}

TNode find(TNode r, datatype x)
{
    if (r == NULL)
        return NULL;
    if (r->inf == x)
        return r;
    TNode p = r->leftMostChild;
    while (p != NULL)
    {
        TNode q = find(p, x);
        if (q != NULL)
            return q;
        p = p->rightSibling;
    }
    return NULL;
}

TNode insert(TNode r, int u , int v)
{
    // Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không chèn thêm mới)
    TNode p = find(r, v);
    if (p == NULL || find(r, u) != NULL)
        return r;
    TNode newNode = makeNode(u);
    if (p->leftMostChild == NULL)
        p->leftMostChild = newNode;
    else
    {
        TNode q = p->leftMostChild;
        while (q->rightSibling != NULL)
            q = q->rightSibling;
        q->rightSibling = newNode;
    }
    return r;
}

int main()
{
    char choice[100];
    TNode root = NULL;
    while(scanf("%s", choice) != EOF && strcmp(choice, "*") != 0)
    {
        if (strcmp(choice,"MakeRoot") == 0)
        {
            int x;
            scanf("%d", &x);
            root = makeNode(x);
        }
        else if (strcmp(choice, "Insert") == 0)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            root = insert(root, u, v);
        }
        else if (strcmp(choice, "InOrder") == 0)
        {
            inOrder(root);
            printf("\n");
        }
        else if (strcmp(choice, "PreOrder") == 0)
        {
            preOrder(root);
            printf("\n");
        }
        else if (strcmp(choice, "PostOrder") == 0)
        {
            postOrder(root);
            printf("\n");
        }
    }
}