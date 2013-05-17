#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 1000
#define MAXM 20005
#define oo 0x7fffffff
struct eList
{
	int tot,NowHead[MAXN],Head[MAXN],Pre[MAXM],V[MAXM],U[MAXM],Cap[MAXM];
	void AddEdge(int a,int b,int c)
	{
		++tot;
		V[tot]=b;U[tot]=a;Cap[tot]=c;
		Pre[tot]=Head[a];Head[a]=tot;
		++tot;
		V[tot]=a;U[tot]=b;Cap[tot]=0;
		Pre[tot]=Head[b];Head[b]=tot;
	}
	void Clean()
	{
		memset(Head,0,sizeof(Head));
		memset(Pre,0,sizeof(Pre));
		tot=1;
	}
	eList()
	{tot=1;
	}
}g;
int Dist[MAXN],Count[MAXN],Stack[MAXN],Path[MAXN];
int sap(int s,int t,int n)
{
	int x=s,MinFlow=oo,MaxFlow=0;Count[0]=n;
	bool flag;
	memcpy(g.NowHead,g.Head,sizeof(g.NowHead));
	memset(Dist,0,sizeof(Dist));
	while (Dist[s]<n)
	{
		Stack[x]=MinFlow;
		flag=0;
		for (int p=g.NowHead[x];p;p=g.Pre[p])
		{
			if (g.Cap[p]&&Dist[x]==Dist[g.V[p]]+1)
			{
				flag=1;
				g.NowHead[x]=p;
				if (MinFlow>g.Cap[p]) MinFlow=g.Cap[p];
				x=g.V[p];Path[x]=p;
				if (x==t)
				{
					MaxFlow+=MinFlow;
					for (;x!=s;x=g.U[Path[x]])
					{
						g.Cap[Path[x]]-=MinFlow;
						g.Cap[Path[x]^1]+=MinFlow;
					}
					MinFlow=oo;
				}
				break;
			}
		}
		if (flag) continue;
		int tmp=0,MinDist=n+1;
		for (int i=g.Head[x];i;i=g.Pre[i])
		{
			if (g.Cap[i]&&Dist[g.V[i]]<MinDist)
			{
				MinDist=Dist[g.V[i]];tmp=i;
			}
		}
		g.NowHead[x]=tmp;
		--Count[Dist[x]];tmp=Dist[x];Dist[x]=MinDist+1;++Count[Dist[x]];
		if (!Count[tmp]) break;
		if (x!=s) 
		{
			x=g.U[Path[x]];
			MinFlow=Stack[x];
		}
	}
	return MaxFlow;
}
int MovieList[25][10];
int DayList[52][7];
void Solve()
{
	g.Clean();
	memset(MovieList,0,sizeof(MovieList));
	memset(DayList,0,sizeof(DayList));
	int N;
	scanf("%d",&N);
	int Sum=0;
//	fprintf(stderr,"Map start building!\n");
	for (int i=1;i<=N;++i)
	{
		for (int j=0;j<9;++j)
		{
			scanf("%d",&MovieList[i][j]);
		}
	}
	int Ptot=2; //1 for S and 2 for T
//	fprintf(stderr,"Read!\n");
	for (int i=1;i<=N;++i)
	{
		MovieList[i][9]=++Ptot;
		g.AddEdge(1,Ptot,MovieList[i][7]);
		Sum+=MovieList[i][7];
	}
//	fprintf(stderr,"Map built 1!");
	for (int i=1;i<=50;++i)
	{
		for (int j=0;j<7;++j)
		{
			DayList[i][j]=++Ptot;
			g.AddEdge(DayList[i][j],2,1);
		}
	}
//	fprintf(stderr,"Map built 2!");
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=MovieList[i][8];++j)
		{
			for (int k=0;k<7;++k)
			{
				if (MovieList[i][k]) g.AddEdge(MovieList[i][9],DayList[j][k],1);
			}
		}
	}
	if (sap(1,2,Ptot)==Sum) puts("Yes");
	else puts("No");
}
int main()
{
	freopen("1698.in","r",stdin);
	//freopen("1698.i","r",stdin);
	int T;
	scanf("%d",&T);
	for (;T;T--) Solve();
	return 0;
}
