#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using std::sort;
#define MAXN 502
#define eps 2e-5
int S,N;
int P[MAXN][2];
int Record[MAXN],RTot;
inline int Sqr(int t) {return t*t;}
inline int Dis2(int a,int b)
{
	return Sqr(P[a][0]-P[b][0])+Sqr(P[a][1]-P[b][1]);
}
namespace USet
{
	int S[MAXN];
	void Init(int N)
	{
		for (int i=1;i<=N;++i) S[i]=i;
	}
	int Fa(int a)
	{
		return (S[a]==a)?a:S[a]=Fa(S[a]);
	}
	bool Same(int a,int b)
	{
		return (Fa(a)==Fa(b));
	}
	void Merge(int a,int b)
	{
		S[Fa(b)]=Fa(a);
	}
};
struct eType
{
	int u,v,dis;
}G[MAXN*MAXN];
int eTot;
bool cmp(const eType & a,const eType & b)
{
	return a.dis<b.dis;
}
void Main()
{
	scanf("%d%d",&S,&N);
	for (int i=1;i<=N;++i)
	{
		scanf("%d%d",&P[i][0],&P[i][1]);
	}
	eTot=0;
	for (int i=1;i<=N;++i)
	{
		for (int j=i+1;j<=N;++j)
		{
			++eTot;G[eTot].u=i;G[eTot].v=j;G[eTot].dis=Dis2(i,j);	
		}
	}
	std::sort(G+1,G+eTot+1,cmp);
	USet::Init(N);
	int EAX=0;
	for (int i=1;i<=eTot;++i)
	{
		if (!USet::Same(G[i].u,G[i].v))
		{
			USet::Merge(G[i].u,G[i].v);
			++EAX;
			if (EAX+S==N)
			{
				printf("%.2f\n",sqrt((double)G[i].dis));
				break;
			}
		}
	}
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--)
	{
		Main();
	}
	return 0;
}
