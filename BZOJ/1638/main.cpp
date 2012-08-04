#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
int n,m;
#define MAXN 5002
#define MAXM 50002
class eList
{
public:
	int Head[MAXN],Pre[MAXM],V[MAXM],tot;
	void AddEdge(int a,int b)
	{
		++tot;
		V[tot]=b;
		Pre[tot]=Head[a];
		Head[a]=tot;
	}
}g1,g2;
int f[MAXN],g[MAXN];
int rd[MAXN],cd[MAXN];
int q[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g1.AddEdge(x,y);
		cd[x]++;
		rd[y]++;
		g2.AddEdge(y,x);
	}
	int qh=0,qt=0;
	for (int i=1;i<=n;++i) if (!rd[i]) {q[++qt]=i;f[i]=1;}
	while (qh<qt)
	{
		int now=q[++qh];
		for (int p=g1.Head[now];p;p=g1.Pre[p])
		{
			rd[g1.V[p]]--;
			f[g1.V[p]]+=f[now];
			if (!rd[g1.V[p]])
			{
				q[++qt]=g1.V[p];
			}
		}
	}
	g[n]=1;
	qh=0,qt=0;
	for (int i=1;i<=n;++i) if (!cd[i]) {q[++qt]=i;}
	while (qh<qt)
	{
		int now=q[++qh];
		for (int p=g2.Head[now];p;p=g2.Pre[p])
		{
			cd[g2.V[p]]--;
			g[g2.V[p]]+=g[now];
			if (!cd[g2.V[p]])
			{
				q[++qt]=g2.V[p];
			}
		}
	}
	int ans=0;
	for (int i=1;i<=n;++i)
	{
		for (int p=g1.Head[i];p;p=g1.Pre[p])
		{
			ans=std::max(ans,f[i]*g[g1.V[p]]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
