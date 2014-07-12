#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 1000002
void Main()
{
	int N,L,d;
	scanf("%d%d",&L,&N);
	int Ans1=0,Ans2=0;
	for (int i=1;i<=N;++i)
	{
		scanf("%d",&d);
		int mind=L-d;
		if (d<mind) 
		{
			int k=d;
			d=mind;
			mind=k;
		}
		if (d>Ans2) Ans2=d;
		if (mind>Ans1) Ans1=mind;
	}
	printf("%d %d\n",Ans1,Ans2);
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--)
	{
		Main();
	}
	return 0;
}
