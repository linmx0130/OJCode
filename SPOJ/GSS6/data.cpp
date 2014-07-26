#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
int N=100000,M=100000;
int main()
{
	srand(time(0));
	printf("%d\n",N);
	for (int i=1;i<=N;++i)
	{
		printf("%d ",rand()%20000-10000);
	}
	printf("\n%d\n",M);
	for (int i=1;i<=M;++i)
	{
		int o=rand()%4;
		if (o==0)
		{
			int pos=rand()%N+1;
			printf("I %d %d\n",pos,rand()%20000-10000);
			N++;
		}
		if (o==1)
		{
			int pos=rand()%N+1;
			printf("D %d\n",pos);
			N--;
		}
		if (o==2)
		{
			int pos=rand()%N+1;
			printf("R %d %d\n",pos,rand()%20000-10000);
		}
		if (o==3)
		{
			int x=rand()%N+1,y=rand()%N+1;
			if (x>y) {int k=x;x=y;y=k;}
			printf("Q %d %d\n",x,y);
		}
	}
}
