#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN 252
#define MAXM MAXN*MAXN
#define oo 0x7fffffff
struct eList
{
	int Head[MAXN],NowHead[MAXN],Pre[MAXM],V[MAXM],U[MAXM],Cap[MAXM],tot;
	void Init()
	{
		tot=1;
		memset(Head,0,sizeof(Head));
		memset(Pre,0,sizeof(Pre));
		memset(U,0,sizeof(U));
		memset(V,0,sizeof(V));
		memset(Cap,0,sizeof(Cap));
	}
	void AddEdge(int u,int v,int c)
	{
		tot++;
		U[tot]=u;V[tot]=v;Cap[tot]=c;
		Pre[tot]=Head[u];
		Head[u]=tot;
		tot++;
		U[tot]=v;V[tot]=u;Cap[tot]=0;
		Pre[tot]=Head[v];
		Head[v]=tot;
	}
}G;
int N,M;
int MaxFlow;
int Count[MAXN],Dist[MAXN],Path[MAXN],Stack[MAXN];
void Sap(int S,int T){
	memset(Dist,0,sizeof(Dist));
	memset(Count,0,sizeof(Count));
	int x=S,MinFlow=oo;
	Count[0]=N;
	bool flag;
	MaxFlow=0;
	for (int i=1;i<=N;++i) G.NowHead[i]=G.Head[i];
	while (Dist[S]<N)
	{
		Stack[x]=MinFlow;
		flag=0;
		for (int p=G.NowHead[x];p;p=G.Pre[p])
		{
			if (G.Cap[p] && Dist[x] ==Dist[G.V[p]]+1)
			{
				flag=1;
				G.NowHead[x]=p;
				if (MinFlow>G.Cap[p]) MinFlow=G.Cap[p];
				x=G.V[p];
				Path[x]=p;
				if (x==T)
				{
					MaxFlow+=MinFlow;
					for (;x!=S;x=G.U[Path[x]])
					{
						G.Cap[Path[x]]-=MinFlow;
						G.Cap[Path[x]^1]+=MinFlow;
					}
					MinFlow=oo;
				}
				break;
			}
		}
		if (flag) continue;
		int tmp=0,MinDist=N+1;
		for (int i=G.Head[x];i;i=G.Pre[i])
		{
			if (G.Cap[i]&&Dist[G.V[i]]<MinDist)
			{
				MinDist=Dist[G.V[i]];
				tmp=i;
			}
		}
		G.NowHead[x]=tmp;
		--Count[Dist[x]];
		tmp=Dist[x];
		Dist[x]=MinDist+1;
		++Count[Dist[x]];
		if (!Count[tmp]) break;
		if (x!=S)
		{
			x=G.U[Path[x]];MinFlow=Stack[x];
		}
	}
}
void Main()
{
	G.Init();
	for (int i=0;i<M;++i)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		G.AddEdge(u,v,c);
	}
	Sap(1,N);
	printf("%d\n",MaxFlow);
}
int main()
{
	while (scanf("%d%d",&M,&N)!=EOF)
	{
		Main();
	}
	return 0;
}
