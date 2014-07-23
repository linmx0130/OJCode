#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 10005
int N;
int d[MAXN];
int Sum[MAXN];
void Main()
{
	scanf("%d",&N);
	printf("%d ",N);
	scanf("%d",&N);
	int maxd=0;
	for (int i=1;i<=N;++i) 
	{
		scanf("%d",&d[i]);
		Sum[i]=Sum[i-1]+d[i];
		if (d[i]>maxd) maxd=d[i];
	}
	for (int p=1;p<=N;++p)
	{
		int Q=Sum[p];
		if (Q<maxd) continue;
		int Count=0;
		bool flag=0;
		for (int i=p+1;i<=N;++i)
		{
			Count+=d[i];
			if (Count>Q) {flag=1;break;}
			if (Count==Q) {Count=0;}
		}
		if (flag) continue;
		if (Count==0)
		{
			printf("%d\n",Q);
			return ;
		}
	}
}
int main()
{
	int P;
	scanf("%d",&P);
	for (;P;P--) Main();
	return 0;
}
