#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 100002
int n;
struct Cow
{
	int d,t;
	double pd;
}d[MAXN];
bool cmp(Cow a,Cow b)
{
	return (a.pd==b.pd)?a.t<b.t:a.pd<b.pd;
}
long long ans=0;
long long sum=0;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&d[i].t,&d[i].d);
		d[i].pd=(double)d[i].t/d[i].d;
		sum+=d[i].d;
	}
	std::sort(d+1,d+n+1,cmp);
	for (int i=1;i<=n;++i)
	{
		sum-=d[i].d;
		ans+=sum*d[i].t*2;
	}
	printf("%lld\n",ans);
	return 0;
}
