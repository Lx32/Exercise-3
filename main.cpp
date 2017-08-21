#include <cstdio>
#include <cstdlib>
#include <ctime>

const int SIZE=100;

int positive(int v[],int s,int p,int n);

int main()
{
	srand(time(NULL));
	int vet[SIZE]={0};
	int i=0;

	for (i=0;i<SIZE;++i)
	{
		vet[i]=rand()%100;
	}

	printf("Il vettore ha %d numeri positivi\n",positive(vet,SIZE,0,0));

	system("pause");

	return 0;
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
