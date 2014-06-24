#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXM 100002
#define MAXN 10002
int N,M;
struct eList
{
	int Head[MAXN],Pre[MAXM],V[MAXM],tot;
	bool Vis[MAXM];
	void AddEdge(int a,int b)
	{
		++tot;V[tot]=b;Pre[tot]=Head[a];Head[a]=tot;
	}
}G;
int Count=0;
int Ans[MAXM],AnsT;
void DFS(int now)
{
	for (int p=G.Head[now];p;p=G.Pre[p])
	{
		if (!G.Vis[p])
		{
			G.Vis[p]=1;
			DFS(G.V[p]);
		}
	}
	printf("%d\n",now);
}
int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		G.AddEdge(a,b);
		G.AddEdge(b,a);
	}
	DFS(1);
	return 0;
}
