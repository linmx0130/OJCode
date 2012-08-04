#include <cstdio>
int f[70000][20],map[20][20],pow[20];
int n,ans=2147483647;
bool done[70000][20];
#define MIN(a,b) (a<b?a:b)
int main(){
	scanf("%d",&n);
	pow[0]=1;
	for (int i=1;i<=n;++i) pow[i]=pow[i-1]<<1;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			scanf("%d",&map[i][j]);
		}
	}
	for (int i=1;i<=n;++i) done[pow[i-1]][i]=1;
	for (int i=1;i<pow[n];++i){
		for (int j=1;j<=n;++j){
			if ((i&(1<<(j-1)))&&(!done[i][j])){
				int t=i-(1<<(j-1));
				f[i][j]=2147483647;
				for (int k=1;k<=n;++k){
					if (t&(1<<k-1)){
						f[i][j]=MIN(f[i][j],f[t][k]+map[k][j]);
						done[i][j]=1;
					}
				}
			}
		}
	}
	for (int i=1;i<=n;++i){
		ans=MIN(ans,f[pow[n]-1][i]);
	}
	printf("%d\n",ans);
	return 0;
}
