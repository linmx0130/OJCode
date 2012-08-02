#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 50002
class eList
{
public:
	int Head[MAXN],Pre[MAXN*2],V[MAXN*2],tot;
	void AddEdge(int a,int b)
	{
		++tot;
		V[tot]=b;
		Pre[tot]=Head[a];
		Head[a]=tot;
	}
	void AddEdge2(int a,int b)
	{
		AddEdge(a,b);
		AddEdge(b,a);
	}
}g,t;
int n;
bool found[MAXN];
void buildtree(int now)
{
	found[now]=1;
	for (int p=g.Head[now];p;p=g.Pre[p])
	{
		if (!found[g.V[p]])
		{
			t.AddEdge(now,g.V[p]);
			buildtree(g.V[p]);
		}
	}
}
inline int max(int a,int b)
{
	return a>b?a:b;
}
int f[MAXN][2];
void dp(int now)
{
	for (int p=t.Head[now];p;p=t.Pre[p]) dp(t.V[p]);
	//0 : i didn't be chosen
	for (int p=t.Head[now];p;p=t.Pre[p])
	{
		f[now][0]+=max(f[t.V[p]][0],f[t.V[p]][1]);
	}
	//1 : i am chosen
	f[now][1]=1;
	for (int p=t.Head[now];p;p=t.Pre[p])
	{
		f[now][1]+=f[t.V[p]][0];
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g.AddEdge2(x,y);
	}
	buildtree(1);
	dp(1);
	printf("%d\n",max(f[1][0],f[1][1]));
	return 0;
}
