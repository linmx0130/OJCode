#include <cstdio>
#include <cstring>
#include <cstring>
#define MAXN 250
#define MAXM MAXN*MAXN
#define oo 0x7fffffff
class eList
{
public:
	int Head[MAXN],Pre[MAXM],V[MAXM],tot;
	void AddEdge(int a,int b)
	{
		++tot;V[tot]=b;Pre[tot]=Head[a];Head[a]=tot;
	}
	void Init()
	{
		tot=0;memset(Head,0,sizeof(Head));
	}
};
class eList4Flow : public eList
{
public:
	int U[MAXM],Cap[MAXM];
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
		tot=1;memset(Head,0,sizeof(Head));
	}
};
eList G0;
eList4Flow G;
int PointMark[MAXN][2],Pt;
int Count[MAXN],Dist[MAXN],Path[MAXN],Stack[MAXN],MaxFlow;
int NowHead[MAXN];
void SAP(int S,int T)
{
	MaxFlow=0;
	int x=S,MinFlow=oo;
	memset(Count,0,sizeof(Count));
	memset(Dist,0,sizeof(Dist));
	Count[0]=Pt;
	bool flag;
	memcpy(NowHead,G.Head,sizeof(NowHead));
	while (Dist[S]<Pt)
	{
		Stack[x]=MinFlow;
		flag=0;
		for (int p=NowHead[x];p;p=G.Pre[p])
		{
			if (G.Cap[p] && Dist[G.V[p]]==Dist[x]-1)
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
		int tmp=0,MinDist=Pt+1;
		for (int p=G.Head[x];p;p=G.Pre[p])
		{
			if (G.Cap[p] && Dist[G.V[p]] <MinDist)
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
			MinFlow=Stack[x];
		}
	}
}
void Main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	G0.Init();
	G.Init();
	for (int i=1;i<=M;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		G0.AddEdge(a,b);
	}
	for (int i=1;i<=N;++i)
	{
		G.AddEdge(1,PointMark[i][0],1);
		G.AddEdge(PointMark[i][1],2,1);
		for (int p=G0.Head[i];p;p=G0.Pre[p])
		{
			G.AddEdge(PointMark[i][0],PointMark[G0.V[p]][1],1);
		}
	}
	SAP(1,2);
	printf("%d\n",N-MaxFlow);
}
int main()
{
	int T;
	Pt=2;
	for (int i=1;i<=120;++i)
	{
		PointMark[i][0]=++Pt;
		PointMark[i][1]=++Pt;
	}
	for (scanf("%d",&T);T;T--) Main();
	return 0;
}
