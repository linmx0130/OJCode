#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 500
#define MAXM MAXN*MAXN
#define oo 0x7fffffff
int N,CountP;
struct eList
{
	int Head[MAXN],Pre[MAXM],V[MAXM],U[MAXM],Cap[MAXM],tot;
	void AddEdge(int a,int b,int c)
	{
		++tot;U[tot]=a;V[tot]=b;Cap[tot]=c;
		Pre[tot]=Head[a];Head[a]=tot;
		++tot;U[tot]=b;V[tot]=a;Cap[tot]=0;
		Pre[tot]=Head[b];Head[b]=tot;
	}
	void Init()
	{
		tot=1;
		memset(Head,0,sizeof(Head));
	}
}G;
int Time2Point[8][13];
int Count[MAXN],NowHead[MAXN],Dist[MAXN],Path[MAXN],Stack[MAXN],MaxFlow;
void Sap(int N,int S,int T)
{
	MaxFlow=0;
	memset(Count,0,sizeof(Count));
	memset(Dist,0,sizeof(Dist));
	memcpy(NowHead,G.Head,sizeof(NowHead));
	int x=S,MinFlow=oo;
	bool flag;
	while (Dist[S]<N)
	{
		flag=0;
		Stack[x]=MinFlow;
		for (int p=NowHead[x];p;p=G.Pre[p])
		{
			if (G.Cap[p] && Dist[G.V[p]]+1 == Dist[x])
			{
				flag=1;
				NowHead[x]=p;
				if (G.Cap[p]<MinFlow) MinFlow=G.Cap[p];
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
		for (int p=G.Head[x];p;p=G.Pre[p])
		{
			if (G.Cap[p] && MinDist>Dist[G.V[p]])
			{
				tmp=p;MinDist=Dist[G.V[p]];
			}
		}
		NowHead[x]=tmp;
		--Count[Dist[x]];
		tmp=Dist[x];
		Dist[x]=MinDist+1;
		++Count[Dist[x]];
		if (!Count[tmp]) break;
		if (x!=S)
		{
			x=G.U[Path[x]];
			MinFlow=Stack[x];
		}

	}
}
void Main()
{
	G.Init();
	int S=1,T=2,Pt=2;
	for (int i=1;i<=7;++i)
	{
		for (int j=1;j<=12;++j)
		{
			Time2Point[i][j]=++Pt;
		}
	}
	for (int i=1;i<=7;++i)
	{
		for (int j=1;j<=12;++j)
		{
			G.AddEdge(Time2Point[i][j],T,1);
		}
	}
	for (int i=1;i<=N;++i)
	{
		++Pt;
		G.AddEdge(S,Pt,1);
		int K;scanf("%d",&K);
		for (int i=1;i<=K;++i)
		{
			int p,q;
			scanf("%d%d",&p,&q);
			G.AddEdge(Pt,Time2Point[p][q],1);
		}
	}
	Sap(Pt,S,T);
	printf("%d\n",MaxFlow);
}
int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		Main();
	}
	return 0;
}
