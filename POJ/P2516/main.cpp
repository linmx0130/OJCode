#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 105
#define MAXM MAXN*MAXN
#define QSIZE MAXN+5
#define oo 0x7fffffff
struct eList
{
	int Head[MAXN],Pre[MAXM],V[MAXM],U[MAXM],Cap[MAXM],W[MAXM],tot;
	void Init()
	{
		tot=1;
		memset(Head,0,sizeof(Head));
	}
	void AddEdge(int a,int b,int c,int d)
	{
		++tot;
		U[tot]=a;V[tot]=b;Cap[tot]=c;W[tot]=d;
		Pre[tot]=Head[a];Head[a]=tot;
		++tot;
		U[tot]=b;V[tot]=a;Cap[tot]=0;W[tot]=-d;
		Pre[tot]=Head[b];Head[b]=tot;
	}
}G;
int MinCost,MaxFlow;
int Dist[MAXN],Path[MAXN];
int Q[QSIZE];bool inQ[MAXN];
int Vis[MAXN];
bool SPFA(int N,int S,int T)
{
	memset(Dist,60,sizeof(Dist));
	memset(Path,0,sizeof(Path));
	memset(Vis,0,sizeof(Vis));
	Dist[S]=0;
	int Qh=0,Qt=1;
	Q[1]=S;
	inQ[S]=1;
	Vis[S]=1;
	while (Qh!=Qt)
	{
		++Qh;if (Qh==QSIZE) Qh=0;
		int now=Q[Qh];
		for (int p=G.Head[now];p;p=G.Pre[p])
		{
			if (G.Cap[p])if (Vis[G.V[p]]<N) 
			if (Dist[G.V[p]]>Dist[now]+G.W[p])
			{
				Dist[G.V[p]]=Dist[now]+G.W[p];
				Path[G.V[p]]=p;
				Vis[G.V[p]]++;
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
	return Dist[0]!=Dist[T];
}
void MinCostFlow(int N,int S,int T)
{
	int MinFlow=oo;
	MaxFlow=0;MinCost=0;
	while (SPFA(N,S,T))
	{
		for (int x=T;x!=S;x=G.U[Path[x]])
		{
			if (MinFlow>G.Cap[Path[x]]) MinFlow=G.Cap[Path[x]];
		}
		for (int x=T;x!=S;x=G.U[Path[x]])
		{
			G.Cap[Path[x]]-=MinFlow;
			G.Cap[Path[x]^1]+=MinFlow;
		}
		MinCost+=Dist[T]*MinFlow;
		MaxFlow+=MinFlow;
	}
}
int N,M,K;
int Order[52][52],Storage[52][52],Cost[52][52][52];
void Main()
{
	memset(Order,0,sizeof(Order));
	memset(Storage,0,sizeof(Storage));
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=K;++j)
		{
			scanf("%d",&Order[i][j]);
			Order[0][j]+=Order[i][j];
		}
	}
	for (int i=1;i<=M;++i)
	{
		for (int j=1;j<=K;++j)
		{
			scanf("%d",&Storage[i][j]);
			Storage[0][j]+=Storage[i][j];
		}
	}
	for (int i=1;i<=K;++i)
	{
		for (int j=1;j<=N;++j)
		{
			for (int k=1;k<=M;++k)
			{
				scanf("%d",&Cost[i][j][k]);
			}
		}
	}
	for (int i=1;i<=K;++i)
	{
		if (Storage[0][i]<Order[0][i]) 
		{
			puts("-1");
			return ;
		}
	}
	int Ans=0;
	for (int k=1;k<=K;++k)
	{
		G.Init();
		for (int i=1;i<=N;++i)
		{
			G.AddEdge(1,i+2,Order[i][k],0);
		}
		for (int i=1;i<=M;++i)
		{
			G.AddEdge(i+N+2,2,Storage[i][k],0);
		}
		for (int i=1;i<=N;++i)
		{
			for (int j=1;j<=M;++j)
			{
				G.AddEdge(i+2,j+N+2,oo,Cost[k][i][j]);
			}
		}
		MinCostFlow(N+M+2,1,2);
		Ans+=MinCost;
	}
	printf("%d\n",Ans);
}
int main()
{
	while(scanf("%d%d%d",&N,&M,&K),N)
	{
		Main();
	}
	return 0;
}
