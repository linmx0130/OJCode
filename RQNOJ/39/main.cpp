#include <cstdio>
#define MAXM 35005
#define MAXN 25
#define MAX(a,b) (a>b?a:b)
int m,n;
int a[MAXN];
int f[MAXM];
int main(){
	scanf("%d %d",&m,&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (int i=1;i<=n;++i){
		for (int j=m;j>=a[i];j--){
			f[j]=MAX(f[j],f[j-a[i]]+a[i]);
		}
	}
	printf("%d\n",f[m]);
	return 0;
}

