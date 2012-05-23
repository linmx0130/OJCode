#include <cstdio>
#define MAXN 10002
#define MAXM 502
int n,m;
int d[MAXN];
int f[MAXN][MAXM];
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",&d[i]);
	for (int i=1;i<=n;++i){
		if (f[i][0]<f[i-1][0]) f[i][0]=f[i-1][0];
		for (int j=1;j<=m;++j){
			if (f[i-1][j-1]+d[i]>f[i][j]) f[i][j]=f[i-1][j-1]+d[i];
			if ((i+j<=n)&&(f[i][j]>f[i+j][0])) f[i+j][0]=f[i][j];
		}
	}
	printf("%d\n",f[n][0]);
	return 0;
}
