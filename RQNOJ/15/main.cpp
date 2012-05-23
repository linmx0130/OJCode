#include <cstdio>
int n,m;
int time[105],w[105];
int f[1002];
#define MAX(a,b) (a>b?a:b)
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;++i){
		scanf("%d %d",&time[i],&w[i]);
	}
	for (int i=1;i<=m;++i){
		for (int j=n;j>=time[i];--j){
			f[j]=MAX(f[j-time[i]]+w[i],f[j]);
		}
	}
	printf("%d\n",f[n]);
	return 0;
}
