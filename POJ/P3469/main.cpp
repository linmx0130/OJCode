#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 20015
#define MAXM 600002
#define oo 0x7fffffff
int A[MAXN],B[MAXN];
int N,M;
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
	void AddEdge2(int a,int b,int c)
	{
		++tot;
		U[tot]=a;V[tot]=b;Cap[tot]=c;
		Pre[tot]=Head[a];Head[a]=tot;
		++tot;
		U[tot]=b;V[tot]=a;Cap[tot]=c;
		Pre[tot]=Head[b];Head[b]=tot;
	}
	void Init()
	{
		tot=1;
	}
}G;
int Count[MAXN],Dist[MAXN],Path[MAXN],Stack[MAXN],NowHead[MAXN],MaxFlow;
void Sap(int N,int S,int T)
{
	memcpy(NowHead,G.Head,sizeof(NowHead));
	Count[0]=N;
	MaxFlow=0;
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
			if (G.Cap[p] && Dist[G.V[p]]<MinDist)
			{
				tmp=p;
				MinDist=Dist[G.V[p]];
			}
		}
		NowHead[x]=tmp;
		tmp=Dist[x];
		--Count[Dist[x]];
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
int main()
{
	G.Init();
	scanf("%d%d",&N,&M);
	int S=N+1,T=N+2;
	for (int i=1;i<=N;++i)
	{
		scanf("%d%d",&A[i],&B[i]);
		G.AddEdge(S,i,B[i]);
		G.AddEdge(i,T,A[i]);
	}
	for (int i=1;i<=M;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		G.AddEdge2(a,b,c);
	}
	Sap(N+2,S,T);
	printf("%d\n",MaxFlow);
	return 0;
}
