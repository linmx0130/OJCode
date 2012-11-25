#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 100003
int N,M;
namespace USet
{
	int s[MAXN];
	void Init(int n)
	{
		for (int i=1;i<=n;++i) s[i]=i;
	}
	int Fa(int now)
	{
		return s[now]==now?s[now]:s[now]=Fa(s[now]);
	}
	bool Diff(int a,int b)
	{
		return Fa(a)!=Fa(b);
	}
	bool Same(int a,int b)
	{
		return Fa(a)==Fa(b);
	}
	void Merge(int a,int b)
	{
		s[Fa(b)]=Fa(a);
	}
};
struct LeftTree
{
	int tot,Root[MAXN],Key[MAXN],Dist[MAXN],L[MAXN],R[MAXN];
	void Init()
	{
		memset(Key,0,sizeof(Key));
		memset(Dist,0,sizeof(Dist));
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
	}
	int Merge(int a,int b)
	{
		if (!a) return b;
		if (!b) return a;
		if (Key[b]>Key[a])
		{
			int k=a;a=b;b=k;
		}
		R[a]=Merge(R[a],b);
		if (Dist[L[a]]<Dist[R[a]])
		{
			int k=L[a];
			L[a]=R[a];
			R[a]=k;
		}
		if (!R[a]) Dist[a]=0;
		else Dist[a]=Dist[R[a]]+1;
		return a;
	}
	
}H;
void Work(int a,int b)
{
	if (USet::Same(a,b)) 
	{
		puts("-1");
		return ;
	}
	int Ra=H.Root[USet::Fa(a)],Rb=H.Root[USet::Fa(b)];
	H.Key[Ra]>>=1;
	H.Key[Rb]>>=1;

	int TmpX=H.Merge(H.L[Ra],H.R[Ra]);
	H.L[Ra]=H.R[Ra]=H.Dist[Ra]=0;
	TmpX=H.Merge(TmpX,Ra);

	int TmpY=H.Merge(H.L[Rb],H.R[Rb]);
	H.L[Rb]=H.R[Rb]=H.Dist[Rb]=0;
	TmpY=H.Merge(TmpY,Rb);
	
	USet::Merge(a,b);
	H.Root[USet::Fa(a)]=H.Merge(TmpX,TmpY);
	printf("%d\n",H.Key[H.Root[USet::Fa(a)]]);
}
void Main()
{
	H.Init();USet::Init(N);
	for (int i=1;i<=N;++i)
	{
		scanf("%d",&H.Key[i]);
		H.Root[i]=i;
	}
	scanf("%d",&M);
	for (;M;M--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Work(x,y);
	}
}
int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		Main();
	}
	return 0;
}
