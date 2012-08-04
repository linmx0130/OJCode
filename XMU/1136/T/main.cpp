#include <cstdio>
int map[20][20];
int n;
int ans;
bool done[20];
#define MIN(a,b) (a<b?a:b)
void search(int now,int deep,int t){
	if (deep==n){
		if (ans>t)ans=t;
		return;
	}
	done[now]=1;
	for (int i=1;i<=n;++i){
		if (done[i]) continue;
		if (n>=10) if (ans<=t+map[i][0]+2000) return; 
		if (ans<=t+map[now][i]) continue;
		search(i,deep+1,t+map[now][i]);
	}
	done[now]=0;
}
int f[65550];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			scanf("%d",&map[i][j]);
		}
	}
	ans=2147483647;
	search(0,0,0);
	printf("%d\n",ans);
}
