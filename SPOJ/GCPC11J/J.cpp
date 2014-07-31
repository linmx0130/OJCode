#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 100005
struct eList{
	int Head[MAXN],V[MAXN*2],Pre[MAXN*2],tot;
	void AddEdge(int a,int b)
	{
		++tot;V[tot]=b;Pre[tot]=Head[a];Head[a]=tot;
	}
	void AddEdge2(int a,int b)
	{
		AddEdge(a,b);
		AddEdge(b,a);
	}
	void Init()
	{
		tot=0;memset(Head,0,sizeof(Head));
	}
}G;
int N;
int Q[MAXN],Dist[MAXN],Path[MAXN];
bool Vis[MAXN];
int BFS1(int s)
{
	memset(Vis,0,sizeof(Vis));
	int Qh=0,Qt=1;
	Q[1]=s;Vis[s]=1;
	Dist[s]=0;
	while (Qh<Qt)
	{
		int now=Q[++Qh];
		for (int p=G.Head[now];p;p=G.Pre[p])
		{
			if (!Vis[G.V[p]])
			{
				Vis[G.V[p]]=1;
				Q[++Qt]=G.V[p];
				Dist[G.V[p]]=Dist[now]+1;
			}
		}
	}
	int maxt=0;
	for (int i=1;i<N;++i)
	{
		if (Dist[i]>Dist[maxt]) maxt=i;
	}
	return maxt;
}
int BFS2(int s)
{
	memset(Vis,0,sizeof(Vis));
	int Qh=0,Qt=1;
	Q[1]=s;Vis[s]=1;
	Dist[s]=0;
	while (Qh<Qt)
	{
		int now=Q[++Qh];
		for (int p=G.Head[now];p;p=G.Pre[p])
		{
			if (!Vis[G.V[p]])
			{
				Vis[G.V[p]]=1;
				Path[G.V[p]]=now;
				Q[++Qt]=G.V[p];
				Dist[G.V[p]]=Dist[now]+1;
			}
		}
	}
	int maxt=0;
	for (int i=1;i<N;++i)
	{
		if (Dist[i]>Dist[maxt]) maxt=i;
	}
	return maxt;
}
void Main()
{
	G.Init();
	scanf("%d",&N);
	for (int i=1;i<N;++i)
	{
		int a,b;scanf("%d%d",&a,&b);
		G.AddEdge2(a,b);
	}
	int Start=BFS1(0);
	int End=BFS2(Start);
	int Len=Dist[End];
	printf("%d\n",(Len+1)>>1);
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--) Main();
	return 0;
}
