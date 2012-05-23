#define R 0
#define W 1
#include <cstdio>
long long f[50][2];
int n;
int main(){
	scanf("%d",&n);
	f[1][R]=1;
	f[1][W]=1;
	for (int i=1;i<n;++i){
		f[i+1][R]+=f[i][W];    //WR
		f[i+1][W]+=f[i][R];    //RW
		f[i+2][R]+=f[i][W];    //WBR
		f[i+2][W]+=f[i][R];    //RBW
	}
	printf("%lld\n",f[n][R]+f[n][W]);
	return 0;
}
