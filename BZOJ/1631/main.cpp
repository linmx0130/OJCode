#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 1002
#define MAXM 100002
class eList
{
public:
	int Head[MAXN],Pre[MAXM],V[MAXM],W[MAXM],tot;
	void AddEdge(int a,int b,int c)
	{
		++tot;
		V[tot]=b;
		W[tot]=c;
		Pre[tot]=Head[a];
		Head[a]=tot;
	}
}g1,g2;
int n,m,x;
int dis1[MAXN],dis2[MAXN];
int q[MAXM*10];
bool inqueue[MAXN];
void spfa(eList &g,int* dis)
{
	int qh=0,qt=1;
	q[1]=x;
	dis[x]=0;
	inqueue[x]=1;
	while (qh<qt)
	{
		int now=q[++qh];
		for (int p=g.Head[now];p;p=g.Pre[p])
		{
			if (dis[g.V[p]]>dis[now]+g.W[p])
			{
				dis[g.V[p]]=dis[now]+g.W[p];
				if (!inqueue[g.V[p]])
				{
					inqueue[g.V[p]]=1;
					q[++qt]=g.V[p];
				}
			}
		}
		inqueue[now]=0;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&x);
	for (int i=1;i<=m;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		g1.AddEdge(a,b,c);
		g2.AddEdge(b,a,c);
	}
	memset(dis1,60,sizeof(dis1));
	spfa(g1,dis1);
	memset(dis2,60,sizeof(dis2));
	spfa(g2,dis2);
	int ans=0;
	for (int i=1;i<=n;++i)
	{
		if(dis1[i]+dis2[i]>ans) ans=dis1[i]+dis2[i];
	}
	printf("%d\n",ans);
	return 0;
}
