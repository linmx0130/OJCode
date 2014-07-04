#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 105
#define MAXM MAXN*MAXN
int N;
struct eList
{
	int Head[MAXN],Pre[MAXM],V[MAXM],tot;
	void AddEdge(int a,int b)
	{
		++tot;V[tot]=b;Pre[tot]=Head[a];Head[a]=tot;
	}
}G,G2;
bool Vis[MAXN];
int Stack[MAXN],St=0;
int SCC_No[MAXN],SCC_tot;
void dfs1(int now)
{
	Vis[now]=1;
	for (int p=G.Head[now];p;p=G.Pre[p])
	{
		if (!Vis[G.V[p]])
		{
			dfs1(G.V[p]);
		}
	}
	Stack[++St]=now;
}
void dfs2(int now,int cnt)
{
	Vis[now]=1;
	SCC_No[now]=cnt;
	for (int p=G2.Head[now];p;p=G2.Pre[p])
	{
		if (!Vis[G2.V[p]])
		{
			dfs2(G2.V[p],cnt);
		}
	}
}
int Rd[MAXN],Cd[MAXN];
bool Found[MAXN][MAXN];
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		int t=0;
		do
		{
			scanf("%d",&t);
			if (t!=0) G.AddEdge(i,t),G2.AddEdge(t,i);
		}while(t!=0); 
	}
	for (int i=1;i<=N;++i) if (!Vis[i]) dfs1(i);
	memset(Vis,0,sizeof(Vis));
	for (int i=N;i>=1;--i)
	{
		if (!Vis[Stack[i]]) dfs2(Stack[i],++SCC_tot);
	}
	for (int i=N;i>=1;--i)
	{
		for (int p=G.Head[i];p;p=G.Pre[p])
		{
			if (SCC_No[i]!=SCC_No[G.V[p]])
			{
				if (!Found[SCC_No[i]][SCC_No[G.V[p]]])
				{
					Cd[SCC_No[i]]++;
					Rd[SCC_No[G.V[p]]]++;
					Found[SCC_No[i]][SCC_No[G.V[p]]]=1;
				}
			}
		}
	}
	int Ans1=0,Ans2=0;
	for (int i=1;i<=SCC_tot;++i)
	{
		if (Rd[i]==0)
		{
			Ans1++;
		}
		if (Cd[i]==0)
		{
			Ans2++;
		}
	}
	if (SCC_tot==1) Ans2=0;
	else 
	{
		if (Ans1>Ans2) Ans2=Ans1;
	}
	printf("%d\n%d\n",Ans1,Ans2);
	return 0;
}
