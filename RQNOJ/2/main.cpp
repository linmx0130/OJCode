#include <cstdio>
int n,m;
int f[30002];
int v[30],w[30];
#define MAX(a,b) (a>b?a:b)
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;++i) {
		scanf("%d %d",&v[i],&w[i]);
		w[i]*=v[i];
	}
	for (int i=1;i<=m;++i){
		for (int j=n;j>v[i];--j){
			f[j]=MAX(f[j],f[j-v[i]]+w[i]);
		}
	}
	printf("%d\n",f[n]);
	return 0;
}

