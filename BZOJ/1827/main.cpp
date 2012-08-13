#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 100002
int n;
long long P[MAXN];
class eList
{
public:
	int Head[MAXN],Pre[MAXN*2],V[MAXN*2],tot;
	long long W[MAXN*2];
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
}g,t;
bool done[MAXN];
long long f1[MAXN][2],f2[MAXN];
void buildtree(int now)
{
	done[now]=1;
	for (int p=g.Head[now];p;p=g.Pre[p])
	{
		if (done[g.V[p]]) continue;
		t.__AddEdge(now,g.V[p],g.W[p]);
		buildtree(g.V[p]);
	}
}

void dp1(int now)
{
	done[now]=1;
	for (int p=t.Head[now];p;p=t.Pre[p])
	{
		dp1(t.V[p]);
		f1[now][0]+=f1[t.V[p]][0];
		f1[now][1]+=f1[t.V[p]][1]+f1[t.V[p]][0]*t.W[p];
	}
	f1[now][0]+=P[now];
}

void dp2(int now)
{
	for (int p=t.Head[now];p;p=t.Pre[p])
	{
		f2[t.V[p]]=f2[now]-f1[t.V[p]][0]*t.W[p]+
				(f1[1][0]-f1[t.V[p]][0])*t.W[p];
		dp2(t.V[p]);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%lld",&P[i]);
	}
	for (int i=1;i<n;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		g.AddEdge(a,b,c);
	}
	buildtree(1);
	memset(done,0,sizeof(done));
	dp1(1);
	f2[1]=f1[1][1];
	memset(done,0,sizeof(done));
	dp2(1);
	long long ans=f2[1];
	for (int i=2;i<=n;++i)
	{
		if (ans>f2[i]) ans=f2[i];
	}
	printf("%lld\n",ans);
	return 0;
}
