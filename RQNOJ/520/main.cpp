#include <cstdio>
#include <cstring>
#define MAXN 100002
#define MAXM 500005
class eList{
public:
	int Head[MAXN],V[MAXM*2],Pre[MAXM*2],tot;
	void AddEdge(int a,int b){
		++tot;
		V[tot]=b;
		Pre[tot]=Head[a];
		Head[a]=tot;
	}
}g1,g2;
int n,m;
int price[MAXN];
int lp[MAXN],got[MAXN];
int queue[MAXM*5];
bool inqueue[MAXN];
void spfa1(eList& g){
	memset(lp,60,sizeof(lp));
	lp[1]=price[1];
	int qt=1,qh=0;
	queue[1]=1;
	inqueue[1]=1;
	while (qh<qt){
		int now=queue[++qh];
		for (int p=g.Head[now];p;p=g.Pre[p]){
			if (lp[g.V[p]]>lp[now]){
				lp[g.V[p]]=lp[now];
				if (!inqueue[g.V[p]]){
					queue[++qt]=g.V[p];
					inqueue[g.V[p]]=1;
				}
			}
			if (lp[g.V[p]]>price[g.V[p]]){
				lp[g.V[p]]=price[g.V[p]];
				if (!inqueue[g.V[p]]){
					queue[++qt]=g.V[p];
					inqueue[g.V[p]]=1;
				}
			}
		}
		inqueue[now]=0;
	}
}
void spfa2(eList& g){
	int qt=1,qh=0;
	queue[1]=n;
	got[n]=1;
	while (qh<qt){
		int now=queue[++qh];
		for (int p=g.Head[now];p;p=g.Pre[p]){
			if (!got[g.V[p]]){
				got[g.V[p]]=1;
				queue[++qt]=g.V[p];
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",&price[i]);
	}
	for (int i=1;i<=m;++i){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		g1.AddEdge(a,b);
		g2.AddEdge(b,a);
		if (c==2){
			g1.AddEdge(b,a);
			g2.AddEdge(a,b);
		}
	}
	spfa1(g1);
	for (int i=1;i<=n;++i) lp[i]=price[i]-lp[i];
	spfa2(g2);
	int ans=0;
	for (int i=1;i<=n;++i){
		if (got[i]&&lp[i]>ans) ans=lp[i];
	}
	printf("%d\n",ans);
	return 0;
}
