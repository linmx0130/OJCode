#include <cstdio>
int n;
int f[20][20];
int main(){
	scanf("%d",&n);
	f[1][1]=1;
	for (int i=2;i<=n;++i){
		for (int j=1;j<=n;++j){
			f[i][j]=f[i-1][j-1]+f[i-1][j];
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=i;j<=n;++j){
			f[i][j]=f[n-i+1][n-j+1];
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<n;++j) printf("%d ",f[i][j]);
		printf("%d\n",f[i][n]);
	}
	return 0;
}
