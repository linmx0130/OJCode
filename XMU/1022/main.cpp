#include <cstdio>
int n1,m1,n2,m2;
int a[102][102];
int b[102][102];
int c[102][102];
int main(){
	scanf("%d%d",&n1,&m1);
	for (int i=1;i<=n1;++i){
		for (int j=1;j<=m1;++j){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d%d",&n2,&m2);
	for (int i=1;i<=n2;++i){
		for (int j=1;j<=m2;++j){
			scanf("%d",&b[i][j]);
		}
	}
	for (int i=1;i<=n1;++i){
		for (int k=1;k<=m1;++k){
			for (int j=1;j<=m2;++j){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for (int i=1;i<=n1;++i){
		for (int j=1;j<m2;++j){
			printf("%d ",c[i][j]);
		}
		printf("%d\n",c[i][m2]);
	}
	return 0;
}
