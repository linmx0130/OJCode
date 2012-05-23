#include <cstdio>
#include <cstring>
#define MAXN 30002
int f[4][MAXN],g[5][MAXN];
int n;
int d[MAXN];
inline int min(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&d[i]);
	}
	memset(f,60,sizeof(f));
	f[0][0]=0;
	f[1][0]=0;
	f[2][0]=0;
	f[3][0]=0;
	f[4][0]=0;

	for (int i=1;i<=3;++i){
		for (int j=1;j<=n;++j){
			if (d[j]==i){
				for (int k=0;k<=i;++k)
					f[i][j]=min(f[k][j-1],f[i][j]);
			}
			else {
				for (int k=0;k<=i;++k)
					f[i][j]=min(f[k][j-1]+1,f[i][j]);
			}
		}
	}
	int ans=min(min(f[3][n],f[2][n]),f[1][n]);
	memset(g,60,sizeof(g));
	g[4][0]=0;
	g[3][0]=0;
	g[2][0]=0;
	g[1][0]=0;
	g[0][0]=0;
	for (int i=3;i>=1;--i){
		for (int j=1;j<=n;++j){
			if (d[j]==i){
				for (int k=i;k<=3;++k)
					g[i][j]=min(g[k][j-1],g[i][j]);
			}
			else {
				for (int k=i;k<=3;++k)
					g[i][j]=min(g[k][j-1]+1,g[i][j]);
			}
		}
	}
	ans=min(min(ans,g[1][n]),min(g[2][n],g[3][n]));
	printf("%d\n",ans);
	return 0;
}
