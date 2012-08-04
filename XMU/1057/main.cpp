#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 102
int n,m,c;
int s[MAXN],t[MAXN];
long long tmp;
long long solve(int now)
{
	long long ret=0;
	for (int i=1;i<=n;++i)
	{
		if (now>=s[i])ret+=(now-s[i])/t[i]+1;
	}
	return ret;
}
int main()
{
	scanf("%d%d%d",&n,&m,&c);
	m-=c;
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&s[i],&t[i]);
	}
	int l=0,r=1000000001;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (solve(mid)<m)
		{
			l=mid+1;
		}
		else 
		{
			r=mid;
		}
	}
	if (l==1000000001) 
	{puts("0");return 0;}
	tmp=solve(l);
	for (int i=n;i;--i)
	{
		if (!((l-s[i])%t[i])) 
		{
			if (tmp==m) {
				printf("%d\n",i);
				return 0;
			}else tmp--;
		}
	}
}
