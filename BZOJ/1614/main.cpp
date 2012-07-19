#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 1002
#define MAXP 20002
int n,m,k;
class eList
{
public:
	int Head[MAXN],Pre[MAXP],V[MAXP],W[MAXP],tot;
	void __AddEdge(int a,int b,int c)
	{
		++tot;
		W[tot]=c;
		V[tot]=b;
		Pre[tot]=Head[a];
		Head[a]=tot;
	}
	void AddEdge(int a,int b,int c)
	{
		__AddEdge(a,b,c);
		__AddEdge(b,a,c);
	}
}g;
int f[MAXN];
int q[MAXP*10];
bool inqueue[MAXN];
bool spfa(int limit)
{
	int qh=0,qt=1;
	q[1]=1;
	inqueue[1]=1;
	memset(f,60,sizeof(f));
	f[1]=0;
	while (qh<qt)
	{
		int now=q[++qh];
		for (int p=g.Head[now];p;p=g.Pre[p])
		{
			int w=(g.W[p]>limit)?1:0;
			if (f[g.V[p]]>f[now]+w)
			{
				f[g.V[p]]=f[now]+w;
				if (!inqueue[g.V[p]])
				{
					q[++qt]=g.V[p];
					inqueue[g.V[p]]=1;
				}
			}
		}
		inqueue[now]=0;
	}
	return f[n]<=k;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		g.AddEdge(x,y,z);
	}
	int l=0,r=1000001;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (spfa(mid))
		{
			r=mid;
		}
		else 
		{
			l=mid+1;
		}
	}
	if (l<1000001) printf("%d\n",l);
	else puts("-1");
	return 0;
}
