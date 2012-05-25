#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 1010
#define MAXM 104
struct BinTreeNode{
	int l,r,num;
}t[MAXN];
class eList{
public:
	int Head[MAXN],Pre[MAXN],V[MAXN],tot;
	void AddEdge(int a,int b){
		++tot;
		V[tot]=b;
		Pre[tot]=Head[a];
		Head[a]=tot;
	}
}g;
int w[MAXN];
int n,m,Ttot;
int buildtree(int now){
	int nownode=++Ttot;int p;
	t[nownode].num=now;
	p=g.Head[now];
	if (p){
		t[nownode].l=buildtree(g.V[p]);
	}
	int lastnode=t[nownode].l;
	for (p=g.Pre[p];p;p=g.Pre[p]){
		t[lastnode].r=buildtree(g.V[p]);
		lastnode=t[lastnode].r;
	}
	return nownode;
}
int f[MAXN][MAXM];bool done[MAXN][MAXM];
inline int max(int a,int b){
	return a>b?a:b;
}
int dp(int now,int m){
	if (done[now][m]) return f[now][m];
	done[now][m]=1;
	if (now==0) return f[now][m]=0;
	if (m==0) return f[now][m]=0;
	//not choose me!
	int ans=0;
	if (t[now].r)ans=max(ans,dp(t[now].r,m));
	//choose me and my children(left)
	for (int i=1;i<=m;++i){
		//1 for me, i-1 for left, m-i for right
		ans=max(ans,w[t[now].num]+dp(t[now].l,i-1)+dp(t[now].r,m-i));
	}
	return f[now][m]=ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",&w[i]);
	for (int i=1;i<=n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		g.AddEdge(x,y);
	}
	buildtree(0);
	printf("%d\n",dp(1,m+1));
	return 0;
}
