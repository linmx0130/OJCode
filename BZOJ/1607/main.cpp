#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define MAXN 100002
#define MAXR 1000002
int n;
int a[MAXN],t[MAXR];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		t[a[i]]++;
	}
	for (int i=1;i<=n;++i)
	{
		int ans=0,limit=sqrt(a[i]);
		for (int j=1;j<=limit;++j)
		{
			if (a[i]%j==0) ans+=t[j]+t[a[i]/j];
			if (a[i]==j*j) ans-=t[j];
		}
		printf("%d\n",ans-1);
	}
	return 0;
}
