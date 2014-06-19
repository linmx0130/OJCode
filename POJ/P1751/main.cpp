#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using std::sort;
#define MAXN 755
int N,M,M2;
int Point[MAXN][2];
struct eType
{
	int u,v,w;
}eList[MAXN*MAXN];
int eTot;
int Sqr(int t) {return t*t;}
bool cmp(const eType & a, const eType & b)
{
	return a.w<b.w;
}
namespace USet
{
	int S[MAXN];
	void Init(int N)
	{
		for (int i=1;i<=N;++i)
		{
			S[i]=i;
		}
	}
	int Fa(int v)
	{
		return S[v]==v? v:S[v]=Fa(S[v]);
	}
	void Merge(int a, int b)
	{
		int fa=Fa(a),fb=Fa(b);
		if (fa!=fb) S[fb]=fa;
	}
	bool Diff(int a,int b)
	{
		return Fa(a)!=Fa(b);
	}
};
void Kruskal()
{
	for (int i=1;i<=eTot ;++i)
	{
		if (USet::Diff(eList[i].u,eList[i].v))
		{
			USet::Merge(eList[i].u,eList[i].v);
			printf("%d %d\n",eList[i].u,eList[i].v);
		}
	}
}
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		scanf("%d%d",&Point[i][0],&Point[i][1]);
	}
	USet::Init(N);
	for (int i=1;i<=N;++i)
	{
		for (int j=i+1;j<=N;++j)
		{
			++eTot;
			eList[eTot].u=i;
			eList[eTot].v=j;
			eList[eTot].w=Sqr(Point[i][0]-Point[j][0])+
					Sqr(Point[i][1]-Point[j][1]);
		}
	}
	sort(eList+1,eList+eTot+1,cmp);
	scanf("%d",&M);
	for (int i=1;i<=M;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		USet::Merge(a,b);
	}
	Kruskal();
	return 0;
}
