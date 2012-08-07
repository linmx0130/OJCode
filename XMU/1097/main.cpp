#include <cstdio>
#include <algorithm>
int n,k;
int d[1000002];
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i) scanf("%d",d+i);
	std::sort(d+1,d+n+1);
	printf("%d\n",d[k]);
}
