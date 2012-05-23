#include <cstdio>

#define MAXN 1000002
int n;
int Connect[MAXN*2],Pre[MAXN*2],D[MAXN*2],tot;
int v[MAXN*2],link[MAXN*2];
inline void addedge(int x,int y){
	tot++;
	D[tot]=y;
	Pre[tot]=Connect[x];
	Connect[x]=tot;
}
bool find(int x,int y){
	for (int p=Connect[x];p;p=Pre[p]){
		if (v[D[p]]!=y){
			v[D[p]]=y;
			int q=link[D[p]];
			link[D[p]]=x;
			if (!q||find(q,y)) return true;
			link[D[p]]=q;
		}
	}
	return false;
}
inline void solve(){
	for (int i=1;i<=10002;++i){
		if (!find(i,i)){
			printf("%d\n",i-1);
			return;
		}
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		addedge(x,i);
		addedge(y,i);
	}
	solve();
	return 0;
}
