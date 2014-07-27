#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXP 40005
#define MAXN 205
#define oo 0x3f3f3f3f
int N,P,T;
struct eNode
{
	int u,v,w;
}E[MAXP];
bool cmp(const eNode & a,const eNode & b){return a.w<b.w;}
struct eList
{
	int Head[MAXN],V[MAXP*2],U[MAXP*2],Cap[MAXP*2],Pre[MAXP*2],tot;
	void AddEdge(int a,int b,int c)
	{
		++tot;U[tot]=a;V[tot]=b;Cap[tot]=c;
		Pre[tot]=Head[a];Head[a]=tot;
		++tot;U[tot]=b;V[tot]=a;Cap[tot]=c;
		Pre[tot]=Head[b];Head[b]=tot;
	}
	void Init()
	{
		tot=1;memset(Head,0,sizeof(Head));
	}
}G;
int Count[MAXN],Path[MAXN],Dist[MAXN],Stack[MAXN],NowHead[MAXN],MaxFlow;
void Sap(int N,int S,int T)
{
	memcpy(NowHead,G.Head,sizeof(G.Head));
	memset(Count,0,sizeof(Count));
	memset(Dist,0,sizeof(Dist));
	MaxFlow=0;Count[0]=N;
	int x=S,MinFlow=oo;
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
				tmp=p;MinDist=Dist[G.V[p]];
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
	scanf("%d%d%d",&N,&P,&T);
	for (int i=1;i<=P;++i)
	{
		scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
	}
	std::sort(E+1,E+P+1,cmp);
	int L=1,R=P;
	while (L<R)
	{
		int mid=(L+R)>>1;
		G.Init();
		for (int i=1;i<=mid;++i)
		{
			G.AddEdge(E[i].u,E[i].v,1);
		}
		Sap(N,1,N);
		if (MaxFlow>=T) R=mid;
		else L=mid+1;
	}
	printf("%d\n",E[L].w);
	return 0;
}
