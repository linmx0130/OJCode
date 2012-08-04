#include <cstdio>
#define MAXN 1002
int f[MAXN][2];
int Connect[MAXN],V[MAXN*2],Pre[MAXN*2],tot;
int n;
int main(){
	scanf("%d",&n);
	int a,b;
	for (int i=1;i<n;++i){
		scanf("%d %d",&a,&b);
		a++;b++;
		du[a]++;du[b]++;
		V[++tot]=b;
		Pre[tot]=Connect[a];
		Connect[a]=tot;
		V[++tot]=a;
		Pre[tot]=Connect[b];
		Connect[b]=tot;
	}
	int ans=0,now=0;
	for (int i=1;i<=n;++i){
		int max=0;
		for (int j=1;j<=n;++j){
			if (du[max]<du[j]) max=j;
		}
		ans++;
		now+=du[max];
		if (now>=n-1) break;
		du[max]=0;
		for (int o=Connect[max];o;o=Pre[o]){
			du[V[o]]--;
		}
	}
	printf("%d\n",ans);
	return 0;
}
