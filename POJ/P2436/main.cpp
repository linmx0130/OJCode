#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define LOWBIT(t) (t&(-t))
using std::max;
#define MAXN 1005
int N,D,K;
int CowD[MAXN];
int Count(int DM)
{
	int ret=0;
	for (int i=1;i<=N;++i)
	{
		if ((CowD[i] & DM)==CowD[i]) ret++;
	}
	return ret;
}
bool Cantdo(int i)
{
	int c=0;
	for (;i;i-=LOWBIT(i)) c++;
	return c>K;
}
int main()
{
	int Ans=0;
	scanf("%d%d%d",&N,&D,&K);
	for (int i=1;i<=N;++i)
	{
		int t;
		scanf("%d",&t);
		for (int j=1;j<=t;++j)
		{
			int q;
			scanf("%d",&q);q--;
			CowD[i]+=1<<q;
		}
	}
	for (int i=0;i<(1<<D);++i)
	{
		if (Cantdo(i)) continue;
		Ans=max(Ans,Count(i));
	}
	printf("%d\n",Ans);
	return 0;
}
