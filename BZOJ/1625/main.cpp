#include <cstdio>
#define MAXN 3405
#define MAXM 12900
#define MAX(a,b) (a>b?a:b)
int n,m;
int w[MAXN],d[MAXN];
int f[MAXM];
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d %d",&w[i],&d[i]);
	}
	for (int i=1;i<=n;++i){
		for (int j=m;j>=w[i];--j){
			f[j]=MAX(f[j],f[j-w[i]]+d[i]);
		}
	}
	printf("%d\n",f[m]);
	return 0;
}
