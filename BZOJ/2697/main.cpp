#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 10002
int n,m;
long long c[MAXN];
long long ans=0;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
	{
		scanf("%lld",&c[i]);
	}
	std::sort(c+1,c+m+1);
	long long dis=n-1;
	for (int i=m;i&&dis>0;--i)
	{
		ans+=dis*c[i];
		dis-=2;
	}
	printf("%lld\n",ans);
	return 0;
}
