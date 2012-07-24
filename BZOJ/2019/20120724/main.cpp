#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 222
int D,P,n,F,S;
class eList
{
public:
	int tot,Head[MAXN*2],Pre[MAXN*20],V[MAXN*20],W[MAXN*20];
	void AddEdge(int a,int b,int c)
	{
		++tot;
		V[tot]=b;
		W[tot]=c;
		Pre[tot]=Head[a];
		Head[a]=tot;
	}
}g;
int queue[MAXN*200],dis[MAXN*2];
bool inqueue[MAXN*2];
int found[MAXN*2];
bool no_soluton;
void spfa()
{
	inqueue[S]=1;
	memset(dis,200,sizeof(dis));
	dis[S]=0;
	queue[1]=S;
	int qh=0,qt=1;
	found[S]++;
	while (qh<qt)
	{
		int now=queue[++qh];
		for (int p=g.Head[now];p;p=g.Pre[p])
		{
			if (dis[now]+g.W[p]>dis[g.V[p]])
			{
				dis[g.V[p]]=dis[now]+g.W[p];
				if ((++found[g.V[p]])>=(n<<1)) 
				{
					no_soluton=1;
					break;
				}
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
	scanf("%d%d%d%d%d",&D,&P,&n,&F,&S);
	for (int i=1;i<=n;++i)
	{
		g.AddEdge(i,i+n,D);
	}
	for (int i=1;i<=P;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g.AddEdge(x+n,y,0);
	}
	for (int i=1;i<=F;++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		g.AddEdge(x+n,y,-z);
	}
	spfa();
	if (no_soluton)
	{
		puts("-1");
		return 0;
	}
	int ans=0;
	for (int i=1;i<=(n<<1);++i)
	{
		if (dis[i]>ans) ans=dis[i];
	}
	printf("%d\n",ans);
	return 0;
}
