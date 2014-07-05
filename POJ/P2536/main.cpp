#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 205
#define MAXM MAXN*MAXN
#define oo 0x7fffffff
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
		++tot;U[tot]=a;V[tot]=b;Cap[tot]=c;
		Pre[tot]=Head[a];Head[a]=tot;
		++tot;U[tot]=b;V[tot]=a;Cap[tot]=0;
		Pre[tot]=Head[b];Head[b]=tot;
	}
}G;
inline double Sqr(double t) {return t*t;}
int N,M,S,V;
double Hole[MAXN][2],Gopher[MAXN][2];
int Count[MAXN],Dist[MAXN],Path[MAXN],MaxFlow,Stack[MAXN],NowHead[MAXN];
void Sap(int N,int S,int T)
{
	memset(Count,0,sizeof(Count));
	memset(Dist,0,sizeof(Dist));
	MaxFlow=0;
	int x=S,MinFlow=oo;
	Count[0]=N;
	memcpy(NowHead,G.Head,sizeof(NowHead));
	bool flag;
	while (Dist[S]<N)
	{
		Stack[x]=MinFlow;
		flag=0;
		for (int p=G.Head[x];p;p=G.Pre[p])
		{
			if (G.Cap[p]&&Dist[x]==Dist[G.V[p]]+1)
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
			if (G.Cap[p] && Dist[G.V[p]]<MinDist)
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
	double Dis=Sqr(S*V);
	for (int i=1;i<=N;++i)
	{
		scanf("%lf%lf",&Gopher[i][0],&Gopher[i][1]);
	}
	for (int i=1;i<=M;++i)
	{
		scanf("%lf%lf",&Hole[i][0],&Hole[i][1]);
	}
	G.Init();
	int Pt=2;
	for (int i=1;i<=N;++i)
	{
		G.AddEdge(1,i+2,1);
	}
	for (int i=1;i<=M;++i)
	{
		G.AddEdge(i+N+2,2,1);
	}
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=M;++j)
		{
			if (Sqr(Gopher[i][0]-Hole[j][0])+Sqr(Gopher[i][1]-Hole[j][1])<Dis)
			{
				G.AddEdge(i+2,j+N+2,1);
			}
		}
	}
	Sap(N+M+2,1,2);
	printf("%d\n",N-MaxFlow);
}
int main()
{
	while (scanf("%d%d%d%d",&N,&M,&S,&V)!=EOF)
	{
		Main();
	}
	return 0;
}
