#include <cstdio>
int n;
int a[102][102];
#define MAX(a,b) (a>b?a:b)
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
			if (!a[i][j]) a[i][j]=100000;
		}
	}
	for (int k=1;k<=n;++k){
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				if (a[i][j]>a[i][k]+a[k][j]){
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
	int ans=0;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (a[i][j]==100000){
				printf("-1\n");
				return 0;
			}
			ans=MAX(ans,a[i][j]);
		}
	}
	printf("%d\n",ans-1);
	return 0;
}
