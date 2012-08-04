#include <cstdio>
int n,M;
int m[1002],v[1002];
int f[8200],Pre[1002][8200];
bool g[1002][8200];
int out[1002],anstot;
void print(int now,int k){
	for (;now;now--){
		if (g[now][k]){
			out[anstot++]=now;
			k=Pre[now][k];
		}
	}
}
int main(){
	scanf("%d %d",&n,&M);
	for (int i=1;i<=n;++i){
		scanf("%d",&m[i]);
	}
	for (int i=1;i<=n;++i){
		scanf("%d",&v[i]);
	}
	for (int i=1;i<=n;++i){
		//if (v[i]<0) continue;
		for (int j=M;j>=m[i];--j){
			if (f[j]<f[j-m[i]]+v[i]){
				f[j]=f[j-m[i]]+v[i];
				Pre[i][j]=j-m[i];
				g[i][j]=1;
			}
			else {
				Pre[i][j]=j;
				g[i][j]=0;
			}
		}
	}
	//printf("%d\n",f[M]);
	print(n,M);
	printf("%d\n",anstot);
	if (anstot){
		for (anstot--;anstot;anstot--) printf("%d ",out[anstot]);
		printf("%d\n",out[0]);
	}
	return 0;
}
