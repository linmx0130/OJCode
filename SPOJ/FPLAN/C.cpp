#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 100005
#define MAXM 200005
int N,M;
struct eList
{
	int Head[MAXN],V[MAXM],Pre[MAXM],tot;
	void AddEdge(int a,int b)
	{++tot;V[tot]=b;Pre[tot]=Head[a];Head[a]=tot;}
	void Init()
	{
		tot=0;
		memset(Head,0,sizeof(Head));
	}
}G;
int DFN[MAXN],LOW[MAXN],Stack[MAXN],St,TimeS;
bool inS[MAXN];
int SCC[MAXN],SCCt,Rd[MAXN];
void Tarjan(int u)
{
	DFN[u]=LOW[u]=++TimeS;
	Stack[++St]=u;
	inS[u]=1;
	for (int p=G.Head[u];p;p=G.Pre[p])
	{
		if (!DFN[G.V[p]])
		{
			Tarjan(G.V[p]);
			if (LOW[G.V[p]]<LOW[u]) LOW[u]=LOW[G.V[p]];
		}else if (inS[G.V[p]])
		{
			if (DFN[G.V[p]]<LOW[u]) LOW[u]=DFN[G.V[p]];
		}
	}
	if (DFN[u]==LOW[u])
	{
		int v;
		++SCCt;
		do
		{
			v=Stack[St--];
			inS[v]=0;
			SCC[v]=SCCt;
		}while (u!=v);
	}
}
void Main()
{
	G.Init();
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;++i)
	{
		int a,b;scanf("%d%d",&a,&b);
		G.AddEdge(a,b);
	}
	SCCt=0;St=0;
	memset(DFN,0,sizeof(DFN));
	memset(LOW,0,sizeof(LOW));
	for (int i=0;i<N;++i) if (!DFN[i]) Tarjan(i);
	memset(Rd,0,sizeof(Rd));
	for (int u=0;u<N;++u)
	{
		for (int p=G.Head[u];p;p=G.Pre[p])
		{
			if (SCC[G.V[p]]!=SCC[u])
			{
				Rd[SCC[G.V[p]]]++;
			}
		}
	}
	int Rd0Count=0,point;
	for (int i=1;i<=SCCt;++i)
	{
		if (Rd[i]==0) {Rd0Count++;point=i;}
	}
	if (Rd0Count>1)
	{
		puts("Confused\n");
		return ;
	}
	for (int i=0;i<N;++i)
	{
		if (SCC[i]==point) printf("%d\n",i);
	}
	puts("");
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--) Main();
	return 0;
}
