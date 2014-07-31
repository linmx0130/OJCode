#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 10004
#define MAXM 100005
int N,M;
struct eList
{
	int Head[MAXN],Pre[MAXM],V[MAXM],tot;
	void AddEdge(int a,int b)
	{
		++tot;V[tot]=b;Pre[tot]=Head[a];Head[a]=tot;
	}
	void Init()
	{
		tot=0;
		memset(Head,0,sizeof(Head));
	}
}G;
int Rd[MAXN];
bool Vis[MAXN];
bool INS[MAXN];
bool DFS(int now)
{
	Vis[now]=1;
	INS[now]=1;
	for (int p=G.Head[now];p;p=G.Pre[p])
	{
		if (INS[G.V[p]]) return 1;
		if (!Vis[G.V[p]]) if (DFS(G.V[p])) return 1;
	}
	INS[now]=0;
	return 0;
}
int Q[MAXN];
int Dist[MAXN];
int Next[MAXN];
void Main()
{
	G.Init();
	memset(Rd,0,sizeof(Rd));
	memset(Vis,0,sizeof(Vis));
	memset(INS,0,sizeof(INS));
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		G.AddEdge(a,b);
		Rd[b]++;
	}
	for (int i=1;i<=N;++i)
	{
		if (!Rd[i])
		{
			if (DFS(i)) 
			{
				puts("recheck hints");
				return ;
			}
		}
	}
	for (int i=1;i<=N;++i)
	{
		if (!Vis[i])
		{
			puts("recheck hints");
			return ;
		}
	}
	int CountRd0=0;
	for (int i=1;i<=N;++i)
	{
		if (Rd[i]==0) {CountRd0++;Q[1]=i;}
	}
	if (CountRd0>1) 
	{
		puts("missing hints");
		return ;
	}
	memset(Dist,0,sizeof(Dist));
	memset(Next,0,sizeof(Next));
	int Qh=0,Qt=1;
	while (Qh<Qt)
	{
		int now=Q[++Qh];
		for (int p=G.Head[now];p;p=G.Pre[p])
		{
			if ((--Rd[G.V[p]])==0)
			{
				Dist[G.V[p]]=Dist[now]+1;
				Q[++Qt]=G.V[p];
				Next[now]=G.V[p];
			}
		}
	}
	int EndT=1;
	for (int i=2;i<=N;++i)
	{
		if (Dist[EndT]<Dist[i]) EndT=i;
	}
	if (Dist[EndT]!=N-1) 
	{
		puts("missing hints");
		return ;
	}
	int now=Q[1];
	for (;Next[now];now=Next[now])
	{
		printf("%d ",now);
	}
	printf("%d\n",now);
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--) Main();
	return 0;
}
