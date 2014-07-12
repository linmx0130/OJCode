#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 1020
#define MAXM 100005
struct eList
{
	int Head[MAXN],Pre[MAXM],V[MAXM],U[MAXM],Cap[MAXM],tot;
	void AddEdge(int a,int b,int c)
	{
		++tot;
		U[tot]=a;V[tot]=b;Cap[tot]=c;
		Pre[tot]=Head[a];Head[a]=tot;
		++tot;
		U[tot]=b;V[tot]=a;Cap[tot]=0;
		Pre[tot]=Head[b];Head[b]=tot;
	}
	void Init()
	{
		tot=1;
		memset(Head,0,sizeof(Head));
	}
}G;
int N,K;
int D[10002][2];
int Dist[MAXN],Count[MAXN],Path[MAXN],Stack[MAXN],NowHead[MAXN],MaxFlow;
#define oo 0x3f3f3f3f
void Sap(int N,int S,int T)
{
	MaxFlow=0;
	memset(Dist,0,sizeof(Dist));
	memset(Count,0,sizeof(Count));
	memcpy(NowHead,G.Head,sizeof(NowHead));
	Count[0]=N;
	int x=S,MinFlow=oo;
	bool flag;
	while (Dist[S]<N)
	{
		Stack[x]=MinFlow;
		flag=0;
		for (int p=NowHead[x];p;p=G.Pre[p])
		{
			if (G.Cap[p] && Dist[G.V[p]]+1==Dist[x])
			{
				NowHead[x]=p;
				flag=1;
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
			if (G.Cap[p] && Dist[G.V[p]]<MinDist)
			{
				MinDist=Dist[G.V[p]];
				tmp=p;
			}
		}
		NowHead[x]=tmp;
		tmp=Dist[x];
		--Count[Dist[x]];
		Dist[x]=MinDist+1;
		++Count[Dist[x]];
		if (!Count[tmp])
		{
			break;
		}
		if (x!=S)
		{
			x=G.U[Path[x]];
			MinFlow=Stack[x];
		}
	}
}
int main()
{
	scanf("%d%d",&N,&K);
	G.Init();
	for (int i=1;i<=K;++i)
	{
		scanf("%d%d",&D[i][0],&D[i][1]);
		G.AddEdge(D[i][0],D[i][1]+N,1);
	}
	int S=N+N+1,T=N+N+2;
	for (int i=1;i<=N;++i)
	{
		G.AddEdge(S,i,1);
		G.AddEdge(i+N,T,1);
	}
	Sap(N+N+2,S,T);
	printf("%d\n",MaxFlow);
	return 0;
}
