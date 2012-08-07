#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 500000
#define MOD 1000000009
int f[MAXN+2];
int main()
{
	f[0]=1;
	f[1]=2;
	for (int i=2;i<=MAXN;++i)
	{
		f[i]=f[i-1]+f[i-2];
		if (f[i]>=MOD) f[i]-=MOD;
	}
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;++i)
	{
		int a;
		scanf("%d",&a);
		printf("%d\n",f[a]);
	}
	return 0;
}
