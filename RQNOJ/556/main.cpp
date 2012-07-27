#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 5002
#define MAXM 50002
#define MAXP 60002
#define MAXE 400002
#define oo 0x7fffffff
int n,m;
class eList
{
public:
	int tot,Head[MAXP],Pre[MAXE],V[MAXE],Cap[MAXE];
	void AddEdge(int a,int b,int c)
	{
		++tot;
		V[tot]=b;
		Cap[tot]=c;
		Pre[tot]=Head[a];
		Head[a]=tot;
		++tot;
		V[tot]=a;
		Cap[tot]=0;
		Pre[tot]=Head[b];
		Head[b]=tot;
	}
	eList()
	{
		tot=1;
	}
}g;
namespace MaxFlow
{
	int Count[MAXP],Dist[MAXP],NowHead[MAXP],Path[MAXP],Stack[MAXP];
	int MaxFlow=0,MinDist=0,n;
	void sap(int s,int t)
	{
		int x=s,MinFlow=oo;
		bool flag;
		memcpy(NowHead,g.Head,sizeof(NowHead));
		Count[0]=n;
		while (Dist[s]<n)
		{
			flag=0;
			Stack[x]=MinFlow;
			for (int p=NowHead[x];p;p=g.Pre[p])
			{
				if (g.Cap[p]&&Dist[x]==Dist[g.V[p]]+1)
				{
					flag=1;
					NowHead[x]=p;
					if (g.Cap[p]<MinFlow) MinFlow=g.Cap[p];
					x=g.V[p];
					Path[x]=p;
					if (x==t)
					{
						MaxFlow+=MinFlow;
						for (;x!=s;x=g.V[Path[x]^1])
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
			MinDist=n+1;
			int tmp=0;
			for (int i=g.Head[x];i;i=g.Pre[i])
			{
				if (g.Cap[i]&&Dist[g.V[i]]<MinDist)
				{
					MinDist=Dist[g.V[i]];
					tmp=i;
				}
			}
			NowHead[x]=tmp;
			--Count[Dist[x]];
			tmp=Dist[x];
			Dist[x]=MinDist+1;
			++Count[Dist[x]];
			if(!Count[tmp]) break;
			if (x!=s)
			{
				x=g.V[Path[x]^1];
				MinFlow=Stack[x];
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int T=n+m+1;
	for (int i=1;i<=n;++i)
	{
		int p;
		scanf("%d",&p);
		g.AddEdge(i,T,p);
	}
	int ans=0;
	for (int i=1;i<=m;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		ans+=c;
		g.AddEdge(0,n+i,c);
		g.AddEdge(n+i,a,oo);
		g.AddEdge(n+i,b,oo);
	}
	MaxFlow::n=n+m+2;
	MaxFlow::sap(0,T);
	printf("%d\n",ans-MaxFlow::MaxFlow);
	return 0;
}
