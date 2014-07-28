#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 105
struct BallT
{
	double x,y,z,r;
}b[MAXN];
int N;
struct eType
{
	int u,v;
	double w;
}E[MAXN*MAXN];
bool cmp(const eType &a, const eType & b)
{
	return a.w<b.w;
}
double Sqr(double t) {return t*t;}
double GetD(int i,int j)
{
	double d=sqrt(Sqr(b[i].x-b[j].x)+Sqr(b[i].y-b[j].y)+Sqr(b[i].z-b[j].z));
	d-=b[i].r+b[j].r;
	return d<0.0?0.0:d;
}
namespace USet
{
	int S[MAXN];
	void Init(int N)
	{
		for (int i=1;i<=N;++i)S[i]=i;
	}
	int Fa(int v)
	{
		return S[v]==v?v:S[v]=Fa(S[v]);
	}
	bool Diff(int u,int v)
	{
		return Fa(u)!=Fa(v);
	}
	void Merge(int u,int v)
	{
		S[Fa(v)]=Fa(u);
	}
};
void Main()
{
	for (int i=1;i<=N;++i)
	{
		scanf("%lf%lf%lf%lf",&b[i].x,&b[i].y,&b[i].z,&b[i].r);
	}
	USet::Init(N);
	int eTot=0,NeedE=N-1;
	for (int i=1;i<=N;++i)
	{
		for (int j=i+1;j<=N;++j)
		{
			double d=GetD(i,j);
			if (d==0) USet::Merge(i,j),NeedE--;
			else
			{
				++eTot;E[eTot].u=i;E[eTot].v=j;E[eTot].w=d;
			}
		}
	}
	std::sort(E+1,E+eTot+1,cmp);
	double Ans=0;
	for (int i=1;i<=eTot && NeedE ;++i)
	{
		if (USet::Diff(E[i].u,E[i].v))
		{
			USet::Merge(E[i].u,E[i].v);
			Ans+=E[i].w;
		}
	}
	printf("%.3f\n",Ans);
}
int main()
{
	while (scanf("%d",&N),N)
	{
		Main();
	}
	return 0;
}
