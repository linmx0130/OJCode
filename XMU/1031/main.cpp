#include <cstdio>
int a[102][102];
int c[102][102];
int n;
int main(){
	int fmax=-2147483647,flag=1;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
			if (a[i][j]>=0) flag=0;
			if ((flag)&&(a[i][j]>fmax)) fmax=a[i][j];
		}
	}
	if (flag){
		printf("%d\n",fmax);
		return 0;
	}
	int max=0;
	for (int i=1;i<=n;++i){
		for (int j=i;j<=n+1;++j){
			int tmp=0,sum=0;
			for (int k=1;k<=n;++k){
				c[k][j]=c[k][j-1]+a[k][j-1];
				sum+=c[k][j]-c[k][i];
				if (sum<0) sum=0;
				if (sum>tmp) tmp=sum;
			}
			if (tmp>max) max=tmp;
		}
	}
	printf("%d\n",max);
	return 0;
}
