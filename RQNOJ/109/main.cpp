#include <cstdio>
#include <cstring>
#include <string>
using std::string;
#define MAXN 502
#define MAXM 5002
int n,m;
int v[MAXN],w[MAXN];
int f[MAXN][MAXM];
int g[MAXN][MAXM][2];
void print(int now,int pri){
	if (now==0) return ;
	print(now-1,g[now][pri][0]);
	if (g[now][pri][1]) printf("%d ",now);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		int s;
		scanf("%d%d%d",&v[i],&w[i],&s);
		v[i]*=s;
		w[i]*=s;
	}
	int anst1=0,anst2=0;
	for (int i=1;i<=n;++i){
		memcpy(f[i],f[i-1],sizeof(f[i]));
		for (int j=1;j<v[i];++j) g[i][j][0]=j,g[i][j][1]=0;
		for (int j=v[i];j<=m;++j){
			g[i][j][0]=j;
			g[i][j][1]=0;
			if (f[i][j]<f[i-1][j-v[i]]+w[i]){
				f[i][j]=f[i-1][j-v[i]]+w[i];
				g[i][j][0]=j-v[i];
				g[i][j][1]=1;
			}
			if (f[i][j]>f[anst1][anst2]) {
				anst1=i,anst2=j;
			}
		}
	}
	printf("%d\n",f[anst1][anst2]);
	print(anst1,anst2);
	puts("");
	return 0;
}
