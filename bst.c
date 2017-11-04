#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int val;
	struct node* lptr;
	struct node* rptr;
}bst;
bst *root;
bst* allocate()
{
	return ((bst*)malloc(sizeof(bst)));
}
/*void insert(bst* h, int value)
{
	bst *p;
	//temp = root;
	p = allocate(); 
	if(h->lptr == NULL && h->rptr == NULL)
		{
			p->val = value;
			p->lptr = NULL;
			p->rptr = NULL;
			if(h->val >= value)
				h->lptr = p;
			else
				h->rptr = p;
		}
	else
	{
		if(value <= h->val)
			insert(h->lptr ,value);
		else
			insert(h->rptr ,value);
	}
}*/
void insert(bst *h, int value)
{
	bst *p;
	p = allocate();
	p->val = value;
	p->lptr = NULL;
	p->rptr = NULL;
	if(h->val >= value)
	{
		if(h->lptr == NULL)
			h->lptr = p;
		else
			insert(h->lptr, value); 
	}
	else
	{
		if(h->rptr == NULL)
			h->rptr = p;
		else
			insert(h->rptr, value);
	}
}

void inorder(bst* p)
{
if(p == NULL)
	return;
inorder(p->lptr);
printf("%d\t", p->val);
inorder(p->rptr);
//printf("\n");
}

bst* search(bst *t, int x)
{
	if(t == NULL) return NULL;
	else
	{
		if(x < t->val)
			return search(t->lptr, x);
		else if(x > t->val)
			return search(t->rptr, x);
		else
			return t;
	}
}

int main()
{
	root = allocate();
	int i = 1,v,n,vr;
	printf("Enter number of nodes to insert: ");
	scanf("%d", &n);
	printf("Enter value of the root node: ");
	scanf("%d", &vr);
	root->val = vr;
	root->lptr = NULL;
	root->rptr = NULL; 
	printf("Enter values:\n");
	for(int i=1; i<n ;i++)
	{
		scanf("%d", &v);
		insert(root, v);
		//printf("Enter 0 to exit\n");
		//scanf("%d", &i);
	}
	inorder(root);

	int vs;
	bst *t;
	printf("\nEnter element to search: ");
	scanf("%d", &vs);
	t = search(root, vs);
	if(t != NULL)
		printf("Found !!\n");
	else 
		printf("Not found!!\n");

	return 0;
}