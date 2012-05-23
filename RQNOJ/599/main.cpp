#include <cstdio>
#define MAXM 122
#define MAXN 355
long long f[45][45][45][45];
int a[MAXN];
int n,m;
int card[5];
inline long long max(long a,long b){
	return a>b?a:b;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	for (int j=1;j<=m;++j){
		int x;
		scanf("%d",&x);
		card[x]++;
	}
	for (int i=0;i<=card[1];++i){
		for (int j=0;j<=card[2];++j){
			for (int k=0;k<=card[3];++k){
				for (int l=0;l<=card[4];++l){
					if (i) f[i][j][k][l]=f[i-1][j][k][l];
					if (j) f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k][l]);
					if (k) f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k-1][l]);
					if (l) f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k][l-1]);
					f[i][j][k][l]+=a[i+j*2+k*3+l*4];
				}
			}
		}
	}
	printf("%lld\n",f[card[1]][card[2]][card[3]][card[4]]);
	return 0;
}
