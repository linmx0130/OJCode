#include <cstdio>
#include <cstring>
#define MAXN 220
#define MAXM 40005
inline int abs(int a){return a>0?a:-a;}
class eList{
public:
	int tot,Head[MAXN],V[MAXM],U[MAXM],Cap[MAXM],Cost[MAXM],Pre[MAXM];
	eList(){
		tot=1;
	}
	void init(){
		tot=1;
		memset(Head,0,sizeof(Head));
		memset(V,0,sizeof(V));
		memset(U,0,sizeof(U));
		memset(Cap,0,sizeof(Cap));
		memset(Cost,0,sizeof(Cost));
		memset(Pre,0,sizeof(Pre));
	}
	void AddEdge(int a,int b,int c,int d){
//		fprintf(stderr,"%d->%d (%d,%d)\n",a,b,c,d);
		++tot;
		V[tot]=b;
		U[tot]=a;
		Cap[tot]=c;
		Cost[tot]=d;
		Pre[tot]=Head[a];
		Head[a]=tot;
		++tot;
		V[tot]=a;
		U[tot]=b;
		Cap[tot]=0;
		Cost[tot]=-d;
		Pre[tot]=Head[b];
		Head[b]=tot;
	}
}g;
int n,m,s,t;
int ans;
int dist[MAXN];
int Path[MAXN];
int queue[MAXN*MAXN*10];
bool inqueue[MAXN];
int MaxInt;
bool spfa(){
	memset(dist,60,sizeof(dist));
	memset(inqueue,0,sizeof(inqueue));
	MaxInt=dist[1];
	dist[s]=0;
	inqueue[s]=1;
	int qt=1,qh=0;
	queue[1]=s;
	while (qh<qt){
		int now=queue[++qh];
		for(int p=g.Head[now];p;p=g.Pre[p]){
			if (!g.Cap[p]) continue;
			if (dist[g.V[p]]>dist[now]+g.Cost[p]){
				dist[g.V[p]]=dist[now]+g.Cost[p];
				Path[g.V[p]]=p;
				if (!inqueue[g.V[p]]){
					inqueue[g.V[p]]=1;
					queue[++qt]=g.V[p];
				}
			}
		}
		inqueue[now]=0;
	}
	return dist[t]!=MaxInt;
}
void costflow(){
	s=0;t=202;
	while (spfa()){
		ans+=dist[t];
		int flow=0x7fffffff;
		for (int k=Path[t];k;k=Path[g.U[k]]){
			if (flow>g.Cap[k]) flow=g.Cap[k];
		}
		for (int k=Path[t];k;k=Path[g.U[k]]){
			g.Cap[k]-=flow;
			g.Cap[k^1]+=flow;
		}
	}
}
char map[MAXN][MAXN];
int homelist[MAXN][2],htot,menlist[MAXN][2],mtot;
int main(){
	while (scanf("%d%d",&n,&m),n||m){
		ans=0;
		htot=mtot=0;
		for (int i=1;i<=n;++i){
			scanf("%s",map[i]+1);
			for (int j=1;j<=m;++j){
				if (map[i][j]=='H'){
					++htot;
					homelist[htot][0]=i;
					homelist[htot][1]=j;
				}
				if (map[i][j]=='m'){
					++mtot;
					menlist[mtot][0]=i;
					menlist[mtot][1]=j;
				}
			}
		}
		g.init();
		for (int i=1;i<=htot;++i){
			for (int j=1;j<=mtot;++j){
				g.AddEdge(i,j+htot,1,abs(homelist[i][0]-menlist[j][0])+abs(homelist[i][1]-menlist[j][1]));
			}
		}
		for (int i=1;i<=htot;++i){
			g.AddEdge(0,i,1,0);
		}
		for (int i=htot+1;i<=htot+mtot;++i){
			g.AddEdge(i,202,1,0);
		}
		costflow();
		printf("%d\n",ans);
		
	//return 0;

	}
	return 0;
}
