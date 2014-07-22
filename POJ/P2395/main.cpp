#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define MAXM 10005
#define MAXN 2002
int N,M;
struct eType
{
	int u,v,l;
}d[MAXM];
using std::sort;
bool cmp(const eType &a,const eType &b)
{
	return a.l<b.l;
}
int S[MAXN];
int Fa(int v)
{
	return (S[v]==v)?v:S[v]=Fa(S[v]);
}
int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;++i)
	{
		scanf("%d%d%d",&d[i].u,&d[i].v,&d[i].l);
	}
	for (int i=1;i<=N;++i) S[i]=i;
	sort(d+1,d+M+1,cmp);
	int Ans=0;
	for (int i=1;i<=M;++i)
	{
		if (Fa(d[i].u)!=Fa(d[i].v))
		{
			S[Fa(d[i].u)]=Fa(d[i].v);
			Ans=d[i].l;
		}
	}
	printf("%d\n",Ans);
	return 0;
}
