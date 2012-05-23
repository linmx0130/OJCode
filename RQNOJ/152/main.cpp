#include <cstdio>
int a[12],b[12],pa,pb;
int ans;
int main(){
	pa=10;pb=10;
	int ax,bx;
	scanf("%d %d",&ax,&bx);
	for (;ax;ax/=10){
		a[pa--]=ax%10;
	}
	for (;bx;bx/=10){
		b[pb--]=bx%10;
	}
	for (int i=pa+1;i<=10;++i){
		for (int j=pb+1;j<=10;++j){
			ans+=a[i]*b[j];
		}
	}
	printf("%d\n",ans);
	return 0;
}
