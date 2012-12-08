#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXM 5005
struct Edge
{
	int u,v,w;
}d[MAXM];
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
};
namespace USet
{
	int S[105];
	int Fa(int v)
	{
		return S[v]==v?v:Fa(S[v]);
	}
	int Init(int N)
	{
		for (int i=1;i<=N;++i)S[i]=i;
	}
	void Union(int a,int b)
	{
		S[Fa(b)]=Fa(a);
	}
	bool Diff(int a,int b)
	{
		return Fa(a)!=Fa(b);
	}
};
int N,M;
int Ans;
void Kruskal(int start)
{
	USet::Init(N);
	int Tot=0;
	for (int i=start;i<=M&&Tot<N-1;++i)
	{
		if (USet::Diff(d[i].u,d[i].v))
		{
			Tot++;
			USet::Union(d[i].u,d[i].v);
			if (Tot==N-1)
			{
				if ((d[i].w-d[start].w)<Ans)Ans=d[i].w-d[start].w;
				return ;
			}
		}
	}
}
void Main()
{
	for (int i=1;i<=M;++i)
	{
		scanf("%d%d%d",&d[i].u,&d[i].v,&d[i].w);
	};
	std::sort(d+1,d+M+1,cmp);
	Ans=0x7fffffff;
	for (int i=1;i<=M-N+2;++i)
	{
		Kruskal(i);
	}
	if (Ans!=0x7fffffff) printf("%d\n",Ans);
	else puts("-1");
};
int main()
{
	while (scanf("%d%d",&N,&M),N||M)
	{
		Main();
	};
}
