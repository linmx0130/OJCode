#include <cstdio>
#include <cstring>
#define MAXN 2502
int m[MAXN];
int n;
int f[MAXN];
int w[MAXN];
inline int min(int a,int b){return a<b?a:b;}
int main()
{
	scanf("%d%d",&n,&m[0]);
	w[0]=m[0]+m[0];
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&m[i]);
		w[i]=w[i-1]+m[i];
	}
	memset(f,60,sizeof(f));
	f[0]=0;
	for (int i=1;i<=n;++i)
	{
		for (int j=i;j<=n;++j)
		{
			f[j]=min(f[j],f[j-i]+w[i]);
		}
	}
	printf("%d\n",f[n]-m[0]);
	return 0;
}
