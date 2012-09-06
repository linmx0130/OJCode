#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 50002
int n;
struct DType
{
	int s,num;
}s[MAXN];
bool cmp(DType a,DType b)
{
	return a.s>b.s;
}
class eList
{
public:
	int Head[MAXN*2],Pre[MAXN*2],V[MAXN*2],tot;
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
}g;
namespace Set
{
	int s[MAXN];
	void init(int n)
	{
		for (int i=1;i<=n;++i)
		{
			s[i]=i;
		}
	}
	int find(int now)
	{
		/*
		int root=now;
		for (int v=now;s[v]!=v;v=s[v])
		{
			root=s[v];
		}
		for (int v=now;s[v]!=v;)
		{
			int tmp=s[v];
			s[v]=root;
			v=tmp;
		}
		return root;
		*/
		if (s[now]==now) return now;
		return s[now]=find(s[now]);
	}
	void merge(int a,int b)
	{
		int fa=find(a),fb=find(b);
		if (fa>fb)s[fb]=fa;else s[fa]=fb;
	}
};
int ans;
bool done[MAXN];
namespace LCA
{
	int deepth[MAXN];
	bool done[MAXN];
	int f[MAXN][18];
	void get_deepth(int now)
	{
		done[now]=1;
		for (int p=g.Head[now];p;p=g.Pre[p])
		{
			if (done[g.V[p]]) continue;
			deepth[g.V[p]]=deepth[now]+1;
			get_deepth(g.V[p]);
		}
		done[now]=0;
	}
	inline int dpow(int j)
	{
		return 1<<j;
	}
	void get_f(int now,int fa)
	{
		done[now]=1;
		f[now][0]=fa;
		for (int j=1;dpow(j)<=deepth[now];++j)
		{
			f[now][j]=f[f[now][j-1]][j-1];
		}
		for (int p=g.Head[now];p;p=g.Pre[p])
		{
			if (done[g.V[p]]) continue;
			get_f(g.V[p],now);
		}
		done[now]=0;
	}
	void lca_pre()
	{
		deepth[1]=1;
		done[1]=1;
		get_deepth(1);
		get_f(1,0);
	}
	int lca_find(int a,int b)
	{
		if (deepth[a]<deepth[b])
		{
			int k=a;
			a=b;
			b=k;
		}
		int delta=deepth[a]-deepth[b];
		for (int i=0;(1<<i)<=delta;++i)
		{
			if (delta&(1<<i)) a=f[a][i];
		}
		int limit=deepth[a];
		if (a==b) return a;
		for (int i=log2(limit);i>=0;--i)
		{
			if ((1<<i)>deepth[a]) continue;
			if (f[a][i]!=f[b][i])
			{
				a=f[a][i];
				b=f[b][i];
			}
			if (i==0) break;
		}
		return f[a][0];
	}
};
int longest[MAXN][2];
void Work(int now,int S)
{
	done[now]=1;
	for (int p=g.Head[now];p;p=g.Pre[p])
	{
		if (done[g.V[p]])
		{
			//merge
			int nowroot=Set::find(now);
			int A[4]={
					longest[Set::find(g.V[p])][0],
					longest[Set::find(g.V[p])][1],
					longest[nowroot][0],
					longest[nowroot][1]};
			int newa,newb,newmax=0;
			int tmp;
			//saimon
			for (int i=0;i<3;++i)
			{
				for (int j=i+1;j<4;++j)
				{
					tmp=LCA::deepth[A[i]]+
						LCA::deepth[A[j]]-
						LCA::deepth[LCA::lca_find(A[i],A[j])]*2+1;
					if (tmp>newmax)
					{
						newmax=tmp;
						newa=A[i];newb=A[j];
					}
				}
			}
			Set::merge(now,g.V[p]);
			nowroot=Set::find(now);
			longest[nowroot][0]=newa;
			longest[nowroot][1]=newb;
			if (S*newmax>ans) ans=S*newmax;
		}
	}
}
int main()
{
	scanf("%d",&n);
	Set::init(n);
	for (int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		s[i].s=t;
		s[i].num=i;
		longest[i][0]=longest[i][1]=i;
	}
	std::sort(s+1,s+n+1,cmp);
	for (int i=1;i<n;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		g.AddEdge2(a,b);
	}
	LCA::lca_pre();
	ans=s[1].s;
	done[s[1].num]=1;
	for (int i=2;i<=n;++i)
	{
		Work(s[i].num,s[i].s);
	}
	printf("%d\n",ans);
	return 0;
}
