#include <cstdio>
#include <cstring>
#define MAXN 1002
int n;
int S,T;
int Connect[MAXN],Data[MAXN*2],V[MAXN*2],Pre[MAXN*2],tot;
inline void AddEdge(int x,int y,int w){
	tot++;
	Data[tot]=w;
	V[tot]=y;
	Pre[tot]=Connect[x];
	Connect[x]=tot;
	tot++;
	Data[tot]=w;
	V[tot]=x;
	Pre[tot]=Connect[y];
	Connect[y]=tot;
}
bool inqueue[MAXN];
int queue[MAXN*2];
int dist[MAXN];
inline int spfa(){
	int h=0,t=1;
	queue[1]=S;
	inqueue[S]=1;
	memset(dist,60,sizeof(dist));
	memset(inqueue,0,sizeof(inqueue));
	dist[S]=0;
	while (h<t){
		int o=queue[++h];
		for (int p=Connect[o];p;p=Pre[p]){
			if (dist[V[p]]>dist[o]+Data[p]){
				dist[V[p]]=dist[o]+Data[p];
				if (V[p]==T) return dist[T];
				if (!inqueue[V[p]]){
					inqueue[V[p]]=1;
					queue[++t]=V[p];
				}
			}
		}
	}
}
int main(){
	int Q;
	scanf("%d %d",&n,&Q);
	for (int i=1;i<n;++i){
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		AddEdge(x,y,w);
	}
	for (;Q;Q--){
		scanf("%d %d",&S,&T);
		printf("%d\n",spfa());
	}
	return 0;
}
