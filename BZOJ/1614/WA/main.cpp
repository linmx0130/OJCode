#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 1002
#define MAXP 10002
int n,p,k;
class eList
{
public:
	int Head[MAXN],Pre[MAXP*2],V[MAXP*2],W[MAXP*2],tot;
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
int f[MAXN][MAXN];
int q[MAXP*10][2];
bool inqueue[MAXN][MAXN];
inline int max(int a,int b)
{
	return a>b?a:b;
}
void spfa()
{
	int qh=0,qt=1;
	q[1][0]=1;
	q[1][1]=0;
	memset(f,60,sizeof(f));
	f[1][0]=0;
	inqueue[1][0]=1;
	while (qh<qt)
	{
		int x=q[++qh][0],y=q[qh][1];
		for (int p=g.Head[x];p;p=g.Pre[p])
		{
			if (f[g.V[p]][y]>max(f[x][y],g.W[p]))
			{
				f[g.V[p]][y]=max(f[x][y],g.W[p]);
				if (!inqueue[g.V[p]][y])
				{
					++qt;
					q[qt][0]=g.V[p];q[qt][1]=y;
					inqueue[g.V[p]][y]=1;
				}
			}
			if (y<k)
			{
				if (f[g.V[p]][y+1]>f[x][y])
				{
					f[g.V[p]][y+1]=f[x][y];
					if (!inqueue[g.V[p]][y+1])
					{
						++qt;
						q[qt][0]=g.V[p];q[qt][1]=y+1;
						inqueue[g.V[p]][y+1]=1;
					}
				}
			}
		}
		inqueue[x][y]=0;
	}
}
int main()
{
	scanf("%d%d%d",&n,&p,&k);
	for (int i=1;i<=p;++i)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		g.AddEdge(x,y,w);
	}
	spfa();
	int ans=0x7fffffff;
	for (int i=0;i<=k;++i)
	{
		if (ans>f[n][i]) ans=f[n][i];
	}
	printf("%d\n",ans);
	return 0;
}
