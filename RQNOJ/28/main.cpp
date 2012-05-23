#include <cstdio>
#include <cstring>
#define MAXN 1000002
int n;
class eList{
public:
	int tot,Head[MAXN],Pre[MAXN*2],V[MAXN*2];
	void __AddEdge(int a,int b){
		++tot;
		V[tot]=b;
		Pre[tot]=Head[a];
		Head[a]=tot;
	}
	void AddEdge(int a,int b){
		__AddEdge(a,b);
		__AddEdge(b,a);
	}
}g;
int Apos,Bpos;
int fa[MAXN];
bool clicked[MAXN];
void buildtree(int t){
	clicked[t]=1;
	for (int p=g.Head[t];p;p=g.Pre[p]){
		if (clicked[g.V[p]]) continue;
		fa[g.V[p]]=t;
		buildtree(g.V[p]);
	}
}
bool Apath[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		g.AddEdge(x,y);
	}
	scanf("%d%d",&Apos,&Bpos);
	buildtree(1);
	while (Apos){
		Apath[Apos]=1;
		Apos=fa[Apos];
	}
	while (Bpos){
		if (Apath[Bpos]){
			printf("%d\n",Bpos);
			return 0;
		}
		Bpos=fa[Bpos];
	}
	return 0;
}
