#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 52
int n,m;
int d[MAXN][MAXN];
int f[MAXN*2][MAXN][MAXN];
int size[MAXN*2];
inline int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) 
	{
		for (int j=1;j<=m;++j)
		{
			scanf("%d",&d[i][j]);
		}
	}
	memset(f,200,sizeof(f));
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j)
		{
			size[i+j]++;
		}
	}
	f[2][1][1]=d[1][1];
	for (int i=3;i<=m+1;++i)
	{
		for (int j=1;j<size[i];++j)
		{
			for (int k=j+1;k<=size[i];++k)
			{
				int x1=j,y1=i-j,x2=k,y2=i-k;
				f[i][j][k]=max(max(f[i-1][j][k],f[i-1][j-1][k]),
								max(f[i-1][j][k-1],f[i-1][j-1][k-1]))
						+d[x1][y1]+d[x2][y2];
			}
		}
	}
	for (int i=m+2;i<n+m;++i)
	{
		int ii=i-m-1;
		for (int j=1;j<size[i];++j)
		{
			for (int k=j+1;k<=size[i];++k)
			{
				int x1=j+ii,y1=i-x1,x2=k+ii,y2=i-x2;
				f[i][j][k]=max(max(f[i-1][j][k],f[i-1][j+1][k]),
								max(f[i-1][j][k+1],f[i-1][j+1][k+1]))
						+d[x1][y1]+d[x2][y2];
			}
		}
	}
	f[n+m][1][1]=max(f[n+m-1][1][2],f[n+m-1][2][1])+d[n][m];
	printf("%d\n",f[n+m][1][1]);
	return 0;
}
