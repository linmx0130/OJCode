#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#define MAXN 1002
#define MAXM 1002

struct TNode 
{
	int x,y;
}d[MAXN];
struct Edge
{
	int a,b;
	double w;
}e[MAXN*MAXN];
int n,m,etot;
int Set[MAXN];
int Set_fa(int v)
{
	return (Set[v]==v)?v:Set_fa(Set[v]);
}
inline void Set_union(int a,int b)
{
	int fa=Set_fa(a),fb=Set_fa(b);
	Set[fb]=fa;
}
bool operator< (Edge a,Edge b)
{
	return a.w<b.w;
}
inline long long sqr(long long a){return a*a;}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) Set[i]=i;
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&d[i].x,&d[i].y);
	}
	for (int i=1;i<=n;++i)
	{
		for (int j=i+1;j<=n;++j)
		{
			++etot;
			e[etot].a=i;e[etot].b=j;
			e[etot].w=sqrt(sqr(d[i].x-d[j].x)+sqr(d[i].y-d[j].y));
		}
	}
	std::sort(e+1,e+etot+1);
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Set_union(x,y);
	}
	int left=n-1-m;
	double ans=0;
	for (int i=1;i<=etot&&left;++i)
	{
		if (!(Set_fa(e[i].a)==Set_fa(e[i].b)))
		{
			ans+=e[i].w;
			Set_union(e[i].a,e[i].b);
			left--;
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}
