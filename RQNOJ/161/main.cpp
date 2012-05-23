#include <cstdio>
#include <cstring>
#define MAXN 202
#define MAXM 505
class eList{
public:
	int tot,Head[MAXN],V[MAXM],W[MAXM],Pre[MAXM];
	void AddEdge(int a,int b){
		++tot;
		V[tot]=b;
		W[tot]=1;
		Pre[tot]=Head[a];
		Head[a]=tot;
	}
}g;
int n,a,b;
int K[MAXN];
int dist[MAXN];
int queue[MAXN*10];
bool inqueue[MAXN];
void spfa(){
	dist[a]=0;
	int qh=0,qt=1;
	queue[1]=a;
	inqueue[a]=1;
	while (qh<qt){
		int now=queue[++qh];
		for (int p=g.Head[now];p;p=g.Pre[p]){
			if (dist[g.V[p]]>dist[now]+g.W[p]){
				dist[g.V[p]]=dist[now]+g.W[p];
				if (!inqueue[g.V[p]]){
					inqueue[g.V[p]]=1;
					queue[++qt]=g.V[p];
				}
			}
		}
		inqueue[now]=0;
	}
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	if (a==b) {puts("0");return 0;}
	for (int i=1;i<=n;++i) {
		scanf("%d",K+i);
		if (i+K[i]<=n)g.AddEdge(i,i+K[i]);
		if (i-K[i]>0)g.AddEdge(i,i-K[i]);
	}
	memset(dist,60,sizeof(dist));
	int max=dist[1];
	spfa();
	if (dist[b]!=max) printf("%d\n",dist[b]);else puts("-1");
	return 0;
}
