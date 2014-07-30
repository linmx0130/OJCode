#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 505
#define oo 0x3f3f3f3f
struct eList
{
	int Head[MAXN],V[MAXN*MAXN],Pre[MAXN*MAXN],U[MAXN*MAXN],Cap[MAXN*MAXN],tot;
	void AddEdge(int a,int b,int c)
	{
		++tot;
		U[tot]=a;V[tot]=b;Cap[tot]=c;Pre[tot]=Head[a];Head[a]=tot;
		++tot;
		U[tot]=b;V[tot]=a;Cap[tot]=0;Pre[tot]=Head[b];Head[b]=tot;
	}
	void Init()
	{
		tot=1;
		memset(Head,0,sizeof(Head));
	}
}G;
int N,M,K,C;
int Mat[105][105];
int Dist[MAXN],Path[MAXN],Stack[MAXN],MaxFlow,NowHead[MAXN],Count[MAXN];
void Sap(int N,int S,int T)
{
	memset(Dist,0,sizeof(Dist));
	memset(Count,0,sizeof(Count));
	memcpy(NowHead,G.Head,sizeof(NowHead));
	MaxFlow=0;
	int x=S,MinFlow=oo;
	Count[0]=N;
	while (Dist[S]<N)
	{
		Stack[x]=MinFlow;
		bool flag=0;
		for (int p=NowHead[x];p;p=G.Pre[p])
		{
			if (G.Cap[p] && Dist[G.V[p]]+1==Dist[x])
			{
				flag=1;
				NowHead[x]=p;
				if (G.Cap[p] <MinFlow) MinFlow=G.Cap[p];
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
		if (flag )continue;
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
		Count[Dist[x]]--;
		tmp=Dist[x];
		Dist[x]=MinDist+1;
		Count[Dist[x]]++;
		if (!Count[tmp]) break;
		if (x!=S)
		{
			x=G.U[Path[x]];
			MinFlow=Stack[x];
		}
	}
}
bool Check(int time)
{
	G.Init();
	int S=N+M+M+1,T=S+1;
	int TmC=time-C;
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=M;++j)
		{
			if (Mat[i][j]<=time)
				G.AddEdge(i,j+N,1);
			if (Mat[i][j]<=TmC)
				G.AddEdge(i,j+N+M,1);
		}
	}
	for (int i=1;i<=N;++i)
	{
		G.AddEdge(S,i,1);
	}
	for (int i=1;i<=M;++i)
	{
		G.AddEdge(i+N,T,1);
		G.AddEdge(i+N+M,T,1);
	}
	Sap(T,S,T);
	return MaxFlow>=K;
}
void Main()
{
	scanf("%d%d%d%d",&N,&M,&K,&C);
	int L=0,R=0;
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=M;++j)
		{
			scanf("%d",&Mat[i][j]);
			if (Mat[i][j]>R) R=Mat[i][j];
		}
	}
	while (L<R)
	{
		int mid=(L+R)>>1;
		if (Check(mid))
		{
			R=mid;
		}else
		{
			L=mid+1;
		}
	}
	printf("%d\n",L);
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--) Main();
	return 0;
}
