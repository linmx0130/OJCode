#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 235
#define MAXM MAXN*MAXN
#define oo 0x7fffffff
int K,C,M,N;
int Dis[MAXN][MAXN];
struct eList
{
	int Head[MAXN],Pre[MAXM],V[MAXM],U[MAXM],Cap[MAXM],tot;
	void Init()
	{
		tot=1;
		memset(Head,0,sizeof(Head));
	}
	void AddEdge(int a,int b,int c)
	{
		++tot;
		U[tot]=a;V[tot]=b;Cap[tot]=c;
		Pre[tot]=Head[a];Head[a]=tot;
		++tot;
		U[tot]=b;V[tot]=a;Cap[tot]=0;
		Pre[tot]=Head[b];Head[b]=tot;
	}
}G;
void Floyd()
{
	for (int k=1;k<=N;++k)
	{
		for (int i=1;i<=N;++i)
		{
			for (int j=1;j<=N;++j)
			{
				if (Dis[i][j]>Dis[i][k]+Dis[k][j]) Dis[i][j]=Dis[i][k]+Dis[k][j];
			}
		}
	}
}
int Path[MAXN],Stack[MAXN],MaxFlow,Dist[MAXN],Count[MAXN];
int NowHead[MAXN];
void Sap(int N,int S,int T)
{
	MaxFlow=0;
	memcpy(NowHead,G.Head,sizeof(NowHead));
	memset(Dist,0,sizeof(Dist));
	memset(Count,0,sizeof(Count));
	int x=S,MinFlow=oo;
	Count[0]=N;
	bool flag;
	while (Dist[S]<N)
	{
		Stack[x]=MinFlow;
		flag=0;
		for (int p=NowHead[x];p;p=G.Pre[p])
		{
			if (G.Cap[p] &&Dist[x]==Dist[G.V[p]]+1)
			{
				flag=1;
				NowHead[x]=p;
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
		for (int p=G.Head[x];p;p=G.Pre[p])
		{
			if (G.Cap[p] && Dist[G.V[p]]<MinDist )
			{
				MinDist=Dist[G.V[p]];
				tmp=p;
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
			MinDist=Stack[x];
		}
	}
}
bool Check(int Ans)
{
	int S=N+1,T=N+2;
	G.Init();
	for (int i=1;i<=K;++i)
	{
		G.AddEdge(S,i,M);
	}
	for (int i=K+1;i<=N;++i)
	{
		G.AddEdge(i,T,1);
	}
	for (int i=1;i<=K;++i)
	{
		for (int j=K+1;j<=N;++j)
		{
			if (Dis[i][j]<=Ans) G.AddEdge(i,j,1);
		}
	}
	Sap(N+2,S,T);
	return MaxFlow==C;
}
void Main()
{
	N=K+C;
	int L=1,R=0;
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=N;++j)
		{
			scanf("%d",&Dis[i][j]);
			if (Dis[i][j]==0 && i!=j) Dis[i][j]=0x7000000;
		}
	}
	Floyd();
	for (int i=1;i<=K;++i)
	{
		for (int j=K+1;j<=N;++j) if (R<Dis[i][j]) R=Dis[i][j];
	}
	while (L<R)
	{
		int mid=(L+R)>>1;
		if (Check(mid))
		{
			R=mid;
		}
		else 
		{
			L=mid+1;
		}
	}
	printf("%d\n",L);
}
int main()
{
	while (scanf("%d%d%d",&K,&C,&M)!=EOF)
	{
		Main();
	}
	return 0;
}
