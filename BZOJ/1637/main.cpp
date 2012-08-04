#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 50002
struct DType
{
	int id,x;
}d[MAXN];
bool cmp(DType a,DType b){return a.x<b.x;}
int n;
int delta[MAXN];
int _first[MAXN*2],*first;
int main()
{
	scanf("%d",&n);
	first=_first+MAXN;
	memset(_first,200,sizeof(_first));
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&d[i].id,&d[i].x);
	}
	std::sort(d+1,d+n+1,cmp);
	int ans=0;
	for (int i=1;i<=n;++i)
	{
		delta[i]=delta[i-1]+(d[i].id?1:-1);
		if (first[delta[i]]<0) first[delta[i]]=i;
		else if (d[i].x-d[first[delta[i]]+1].x>ans) ans=d[i].x-d[first[delta[i]]+1].x;
	}
	printf("%d\n",ans);
	return 0;
}
