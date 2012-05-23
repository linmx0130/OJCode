#include <cstdio>
int V,n;
int a[35],f[20002];
inline int max(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%d\n%d",&V,&n);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	for (int i=1;i<=n;++i){
		for (int j=V;j>=a[i];--j){
			f[j]=max(f[j],f[j-a[i]]+a[i]);
		}
	}
	printf("%d\n",V-f[V]);
	return 0;
}
