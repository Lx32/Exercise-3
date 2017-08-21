#include <cstdio>
#include <cstdlib>
#include <ctime>

const int SIZE=100;

bool search(int v[],int s,int p,int x);

int main()
{
	srand(time(NULL));
	int vet[SIZE]={0};
	int i=0;
	int x=0;

	for (i=0;i<SIZE;++i)
	{
		vet[i]=rand()%100;
	}

	printf("Che numero vuoi cercare? ");
	scanf("%d",&x);

	if (search(vet,SIZE,0,x))
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
