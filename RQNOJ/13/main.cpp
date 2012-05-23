#include <cstdio>
int n,m,x,y;
bool f[10002];
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;++i){
		scanf("%d %d",&x,&y);
		for (int j=x;j<=y;++j){
			f[j]=1;
		}
	}
	int ans=0;
	for (int i=0;i<=n;++i){
		if (!f[i]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
