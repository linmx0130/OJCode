#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 30
#define MAXE 5000
int N,M;
int NodeWeight[MAXN];
int Map[MAXN][MAXN];
int Ans[MAXN];
double AnsT;
int Stack[MAXN];
struct EType
{
	int u,v,w;
}EList[MAXE];
bool cmp(EType a,EType b)
{
	return a.w<b.w;
}
namespace USet
{
	int S[MAXN];
	void init(int N)
	{
		for (int i=1;i<=N;++i) S[i]=i;
	}
	int Fa(int a)
	{
		return S[a]==a?a:S[a]=Fa(S[a]);
	}
	bool Diff(int a,int b)
	{
		return Fa(a)!=Fa(b);
	}
	void Merge(int a,int b)
	{
		S[Fa(b)]=Fa(a);
	}
};
bool Used[MAXN];
int CheckAns()
{
	int Etot=0;
	for (int i=1;i<N;++i)
	{
		if (!Used[i]) continue;
		for (int j=i+1;j<=N;++j)
		{
			if (!Used[j]) continue;
			++Etot;
			EList[Etot].u=i;
			EList[Etot].v=j;
			EList[Etot].w=Map[i][j];
		}
	}
	std::sort(EList+1,EList+Etot+1,cmp);
	USet::init(N);
	int Got=1;
	int Ret=0;
	for (int i=1;i<=Etot&&Got<M;++i)
	{
		if (USet::Diff(EList[i].u,EList[i].v))
		{
			USet::Merge(EList[i].u,EList[i].v);
			Got++;
			Ret+=EList[i].w;
		}
	}
	return Ret;
}
void Search(int now,int last)
{
	if (now>M)
	{
		double Tmp=CheckAns();
		int T=0;
		for (int i=1;i<=M;++i)
		{
			T+=NodeWeight[Stack[i]];
		}
		Tmp/=T;
		if (Tmp<AnsT)
		{
			AnsT=Tmp;
			memcpy(Ans,Stack,sizeof(Ans));
		}
		return ;
	}
	for (int i=last+1;i<=N;++i)
	{
		Used[i]=1;
		Stack[now]=i;
		Search(now+1,i);
		Used[i]=0;
	}
}
void Main()
{
	AnsT=0x7ffffff0;
	for (int i=1;i<=N;++i) scanf("%d",&NodeWeight[i]);
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=N;++j)
		{
			scanf("%d",&Map[i][j]);
		}
	}
	Search(1,0);
	for (int i=1;i<M;++i) printf("%d ",Ans[i]);
	printf("%d\n",Ans[M]);
}
int main()
{
	while (~scanf("%d%d",&N,&M))
	{
		if (N==0) return 0;
		Main();
	}
	return 0;
}
