#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXB 25002
#define MAXN 50002
#define MAXM 200002
class eList
{
public:
	int tot,Head[MAXN],Pre[MAXM],V[MAXM],W[MAXM];
	void __AddEdge(int a,int b,int c)
	{
		++tot;
		V[tot]=b;
		W[tot]=c;
		Pre[tot]=Head[a];
		Head[a]=tot;
	}
	void AddEdge(int a,int b,int c)
	{
		__AddEdge(a,b,c);
		__AddEdge(b,a,c);
	}
}g;
int B,N,M;
int queue[MAXM*20];
bool inqueue[MAXN];
int dis[MAXN];
void spfa()
{
	queue[1]=1;
	int qh=0,qt=1;
	inqueue[1]=1;
	memset(dis,60,sizeof(dis));
	dis[1]=0;
	while (qh<qt)
	{
		int now=queue[++qh];
		for (int p=g.Head[now];p;p=g.Pre[p])
		{
			if (dis[now]+g.W[p]<dis[g.V[p]])
			{
				dis[g.V[p]]=dis[now]+g.W[p];
				if (!inqueue[g.V[p]])
				{
					inqueue[g.V[p]]=1;
					queue[++qt]=g.V[p];
				}
			}
		}
		inqueue[now]=0;
	}
}
int main()
{
	scanf("%d%d%d",&N,&M,&B);
	for (int i=1;i<=M;++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		g.AddEdge(x,y,z);
	}
	spfa();
	for (int i=1;i<=B;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",dis[x]+dis[y]);
	}
	return 0;
}
