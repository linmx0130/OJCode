#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <bitset>
#define MAXN 102
#define MAXM 4502
int n,m;
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
int r1[MAXN],r2[MAXN];
std::bitset<MAXN> f1[MAXN],f2[MAXN];
int q[MAXN*2];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g1.AddEdge(x,y);
		g2.AddEdge(y,x);
		r1[y]++;r2[x]++;
	}
	int qh=0,qt=0;
	for (int i=1;i<=n;++i)
	{
		if (!r1[i]) q[++qt]=i;
	}
	while (qh<qt)
	{
		int now=q[++qh];
		f1[now][now]=1;
		for (int p=g1.Head[now];p;p=g1.Pre[p])
		{
			f1[g1.V[p]]|=f1[now];
			if (!(--r1[g1.V[p]]))
			{
				q[++qt]=g1.V[p];
			}
		}
	}
	qh=qt=0;
	for (int i=1;i<=n;++i)
	{
		if (!r2[i]) q[++qt]=i;
	}
	while (qh<qt)
	{
		int now=q[++qh];
		f2[now][now]=1;
		for (int p=g2.Head[now];p;p=g2.Pre[p])
		{
			f2[g2.V[p]]|=f2[now];
			if (!(--r2[g2.V[p]]))
			{
				q[++qt]=g2.V[p];
			}
		}
	}
	int ans=0;
	for (int i=1;i<=n;++i)
	{
		if ((f1[i]|f2[i]).count()==n) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
