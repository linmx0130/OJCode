#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 2002
int a[MAXN],b[MAXN],n,ans=0x7fffffff;
int f[MAXN][MAXN],g[MAXN][MAXN];
inline int min(int a,int b) {return a<b?a:b;}
inline int abs(int a){return a>0?a:-a;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	memcpy(b,a,sizeof(b));
	std::sort(b+1,b+n+1);
	memset(f,60,sizeof(f));
	memset(f[0],0,sizeof(f[0]));
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=n;++j)
		{
			f[i][j]=min(f[i][j],f[i-1][j]+abs(a[i]-b[j]));
			f[i][j]=min(f[i][j],f[i][j-1]);
		}
	}
	for (int i=1;i<=n;++i) ans=min(ans,f[n][i]);
	memset(g,60,sizeof(g));
	memset(g[0],0,sizeof(g[0]));
	for (int i=1;i<=n;++i)
	{
		for (int j=n;j>=1;--j)
		{
			g[i][j]=min(g[i][j],g[i-1][j]+abs(a[i]-b[j]));
			g[i][j]=min(g[i][j],g[i][j+1]);
		}
	}
	for (int i=1;i<=n;++i) ans=min(ans,g[n][i]);
	printf("%d\n",ans);
}
