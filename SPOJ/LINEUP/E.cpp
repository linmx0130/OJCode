#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 110
#define oo 0x3f3f3f3f
inline int min(int a,int b){return a<b?a:b;}
struct eList
{
	int Head[MAXN],V[MAXN*MAXN],U[MAXN*MAXN],Cap[MAXN*MAXN],tot,Pre[MAXN*MAXN],W[MAXN*MAXN];	
	void AddEdge(int a,int b,int c,int d)
	{
		++tot;
		V[tot]=b;U[tot]=a;Cap[tot]=c;W[tot]=d;
		Pre[tot]=Head[a];Head[a]=tot;
		++tot;
		V[tot]=a;U[tot]=b;Cap[tot]=0;W[tot]=-d;
		Pre[tot]=Head[b];Head[b]=tot;
	}
	void Init()
	{
		tot=1;
		memset(Head,0,sizeof(Head));
	}
}G;
#define QSIZE 400000
int Q[QSIZE],Path[MAXN],Dist[MAXN],Flow[MAXN];
bool inQ[MAXN];
bool Spfa(int S,int T)
{
	memset(Dist,60,sizeof(Dist));
	memset(Flow,0,sizeof(Flow));
	memset(Path,0,sizeof(Path));
	int Qh=0,Qt=1;inQ[S]=1;
	Q[1]=S;Dist[S]=0;Flow[S]=oo;
	while (Qh!=Qt)
	{
		++Qh;if (Qh==QSIZE) Qh=0;
		int now=Q[Qh];
		for (int p=G.Head[now];p;p=G.Pre[p])
		{
			if (G.Cap[p] && Dist[G.V[p]]>Dist[now]+G.W[p])
			{
				Dist[G.V[p]]=Dist[now]+G.W[p];
				Flow[G.V[p]]=min(G.Cap[p],Flow[now]);
				Path[G.V[p]]=p;
				if (!inQ[G.V[p]])
				{
					inQ[G.V[p]]=1;
					++Qt;if (Qt==QSIZE) Qt=0;
					Q[Qt]=G.V[p];
				}
			}
		}
		inQ[now]=0;
	}
	return Flow[T]>0;
}
int Mat[15][15];
void Main()
{
	G.Init();
	memset(Mat,0,sizeof(Mat));
	for (int i=1;i<=11;++i)
	{
		for (int j=1;j<=11;++j)
		{
			scanf("%d",&Mat[i][j]);
		}
	}
	int S=23,T=24;
	for (int i=1;i<=11;++i)
	{
		G.AddEdge(S,i,1,0);
		G.AddEdge(i+11,T,1,0);
	}
	for (int i=1;i<=11;++i)
	{
		for (int j=1;j<=11;++j)
		{
			if (Mat[i][j])G.AddEdge(i,j+11,1,-Mat[i][j]);
		}
	}
	int Ans=0;
	while (Spfa(S,T))
	{
		Ans+=Dist[T];
		for (int x=T;x!=S;x=G.U[Path[x]])
		{
			G.Cap[Path[x]]-=Flow[T];
			G.Cap[Path[x]^1]+=Flow[T];
		}
	}
	printf("%d\n",-Ans);
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--) Main();
	return 0;
}
