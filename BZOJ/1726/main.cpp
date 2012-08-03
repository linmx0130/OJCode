#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 5002
#define MAXM 200002
class eList
{
public:
	int tot,Head[MAXN],Pre[MAXM],V[MAXM],W[MAXM];
	void _AddEdge(int a,int b,int c)
	{
		++tot;
		V[tot]=b;
		W[tot]=c;
		Pre[tot]=Head[a];
		Head[a]=tot;
	}
	void AddEdge(int a,int b,int c)
	{
		_AddEdge(a,b,c);
		_AddEdge(b,a,c);
	}
}g;
int n,r;
int dis1[MAXN],dis2[MAXN];
int q[MAXM*10];
bool inqueue[MAXN];
void spfa()
{
	memset(dis1,60,sizeof(dis1));
	memset(dis2,60,sizeof(dis2));
	dis1[1]=0;
	int qh=0,qt=1;
	inqueue[1]=1;
	q[1]=1;
	while (qh<qt)
	{
		int now=q[++qh];
		for (int p=g.Head[now];p;p=g.Pre[p])
		{
			bool change=0;
			int t=dis1[now]+g.W[p];
			if (dis1[g.V[p]]>t)
			{
				dis2[g.V[p]]=dis1[g.V[p]];
				dis1[g.V[p]]=t;
				change=1;
			}else 
			{
				if (dis2[g.V[p]]>t && dis1[g.V[p]]<t)
				{
					dis2[g.V[p]]=t;
					change=1;
				}
			}
			t=dis2[now]+g.W[p];
			if (dis2[g.V[p]]>t && dis1[g.V[p]]<t)
			{
				dis2[g.V[p]]=t;
				change=1;
			}
			if (change&&(!inqueue[g.V[p]]))
			{
				q[++qt]=g.V[p];
				inqueue[g.V[p]]=1;
			}
		}
		inqueue[now]=0;
	}
}
int main()
{
	scanf("%d%d",&n,&r);
	for (int i=1;i<=r;++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		g.AddEdge(x,y,z);
	}
	spfa();
	printf("%d\n",dis2[n]);
	return 0;
}
