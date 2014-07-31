#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 6005
inline int max(int a,int b){return a>b?a:b;}
int N;
int Rating[MAXN];
struct eList
{
	int Head[MAXN],Pre[MAXN*2],V[MAXN*2],tot;
	void AddEdge(int a,int b)
	{
		++tot;V[tot]=b;Pre[tot]=Head[a];Head[a]=tot;
	}
}G;
int Rd[MAXN];
int F[MAXN][2];
void DP(int now)
{
	for (int p=G.Head[now];p;p=G.Pre[p])
	{
		DP(G.V[p]);
	}
	F[now][1]=Rating[now];
	for (int p=G.Head[now];p;p=G.Pre[p])
	{
		F[now][1]+=F[G.V[p]][0];
	}
	F[now][0]=0;
	for (int p=G.Head[now];p;p=G.Pre[p])
	{
		F[now][0]+=max(F[G.V[p]][0],F[G.V[p]][1]);
	}
}
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;++i) scanf("%d",&Rating[i]);
	for (int i=1;i<N;++i)
	{
		int a,b;scanf("%d%d",&a,&b);
		G.AddEdge(b,a);
		Rd[a]=1;
	}
	int Boss;
	for (int i=1;i<=N;++i)
	{
		if (!Rd[i]) {Boss=i;break;}
	}
	DP(Boss);
	printf("%d\n",max(F[Boss][0],F[Boss][1]));
	return 0;
}
