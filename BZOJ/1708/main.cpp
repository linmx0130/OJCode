#include <cstdio>
#include <cstring>
#define MAXN 10002
long long f[MAXN*2];
int n,v;
int d[50];
int main(){
	scanf("%d%d",&v,&n);
	for (int i=1;i<=v;++i) scanf("%d",d+i);
	f[0]=1;
	for (int j=1;j<=v;++j){
		for (int i=d[j];i<=n;++i)
			f[i]+=f[i-d[j]];
		}
	printf("%lld\n",f[n]);
	return 0;
}
