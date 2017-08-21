#include <cstdio>
#include <cstdlib>
#include <ctime>

const int SIZE=100;

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
int positive(int v[],int s,int p,int n);

int main()
{
	srand(time(NULL));
	node *first=NULL;
  int vetb[SIZE]={0};
	int i=0;
	int x=0;

	for (i=0;i<SIZE;++i)
	{
		first=insert(first,rand()%100);
	}
	show(first,0);
	printf("\n");
	first=deleteeq(first);
	show(first,0);
	printf("\n");

	for (i=0;i<SIZE;++i)
	{
		vetb[i]=rand()%100;
	}

	printf("Il vettore ha %d numeri positivi\n",positive(vetb,SIZE,0,0));
	printf("Che numero vuoi cercare? ");
	scanf("%d",&x);

	if (search(vetb,SIZE,0,x))
	{
		printf("Il numero esiste nel vettore!\n");
	}
	else
	{
		printf("Il numero non esiste nel vettore!\n");
	}

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

int positive(int v[],int s,int p,int n)
{
	if (p!=s)
	{
		if (v[p]>0)
		{
			return positive(v,s,p+1,n+1);
		}
		else
		{
			return positive(v,s,p+1,n);
		}
	}

	return n;
}
