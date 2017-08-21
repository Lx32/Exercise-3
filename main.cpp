#include <cstdio>
#include <cstdlib>
#include <ctime>

const int SIZE=10;

struct node
{
	int val;
	node *next;
};

int vet[SIZE]={0};
int pos=0;

node *insert(node *ptr,int x);
node *deleteeq(node *ptr);
void show(node *ptr,int i);
bool search(int v[],int s,int p,int x);

int main()
{
	srand(time(NULL));
	node *first=NULL;
	int i=0;

	for (i=0;i<SIZE;++i)
	{
		first=insert(first,rand()%100);
	}
	show(first,0);
	printf("\n");
	first=deleteeq(first);
	show(first,0);
	printf("\n");

	system("pause");

	return 0;
}

node *insert(node *ptr,int x)
{
	node *newptr=NULL;

	if (ptr==NULL)
	{
		newptr=ptr;
		ptr=(node *)malloc(sizeof(node));
		ptr->val=x;
		ptr->next=newptr;
	}
	else
	{
		ptr->next=insert(ptr->next,x);
	}

	return ptr;
}

node *deleteeq(node *ptr)
{
	if (ptr!=NULL)
	{
		if (!search(vet,pos,0,ptr->val))
		{
			vet[pos++]=ptr->val;
			ptr->next=deleteeq(ptr->next);
		}
		else
		{
			node *oldptr=ptr;
			ptr=ptr->next;
			free(oldptr);
			ptr=deleteeq(ptr);
		}
	}

	return ptr;
}

void show(node *ptr,int i)
{
	if (ptr!=NULL)
	{
		printf("%d -- %d\n",i,ptr->val);
		show(ptr->next,i+1);
	}
}

bool search(int v[],int s,int p,int x)
{
	if (p==s)
	{
		return false;
	}
	else
	{
		if (v[p]==x)
		{
			return true;
		}
		else
		{
			return search(v,s,p+1,x);
		}
	}

	return false;
}
