#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
int N=300000,M=300000;
void Main()
{
	printf("%d %d\n",N,M);
	for (int i=1;i<=M;++i)
	{
		int o=rand()%2;
		int a=rand()%N+1,b=rand()%N+1;
		if (a>b){int k=a;a=b;b=k;}
		if (o)
		{
			int c;
			if (b-a+1==N)
			{
				c=0;
			}
			else c=rand()%(N-(b-a+1));
			printf("CUT %d %d %d\n",a,b,c);
		}
		else 
		{
			printf("FLIP %d %d\n",a,b);
		}

	}
}
int main()
{
	srand(time(0));
	for (int i=1;i<=5;++i) Main();
	puts("-1 -1");
}
