#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 15 
int S[MAXN];
int N;
int PQ[MAXN];
void Search(int now,int last)
{
	if (now==7) 
	{
		for (int i=1;i<6;++i)
		{
			printf("%d ",S[PQ[i]]);
		}
		printf("%d\n",S[PQ[6]]);
	}
	for (int i=last+1;i<=N;++i)
	{
		PQ[now]=i;
		Search(now+1,i);
	}
}
void Main()
{
	for (int i=1;i<=N;++i)
	{
		scanf("%d",&S[i]);
	}
	Search(1,0);
}
int main()
{
	bool first=1;
	while (scanf("%d",&N),N!=0)
	{
		if (first) first=0;else puts("");
		Main();
	}
	return 0;
}
