#include <cstdio>
#include <cstring>
#include <cstdlib>
#define LOWBIT(t) (t&(-t))
#define MAXN 200002
int N,M;
struct USet
{
	int S[MAXN];
	void Init(int N)
	{
		for (int i=1;i<=N;++i)
		{
			S[i]=i;
		}
	}
	int Fa(int t)
	{
		return S[t]==t?t:S[t]=Fa(S[t]);
	}
}S;
struct Tarr
{
	int D[MAXN],N;
	void Init(int n)
	{
		N=n;
		memset(D,0,sizeof(D));
	}
	void Add(int pos,int c)
	{
		for (int i=pos;i<=N;i+=LOWBIT(i)) D[i]+=c;
	}
	int Query(int pos)
	{
		int ret=0;
		for (int i=pos;i;i-=LOWBIT(i)) ret+=D[i];
		return ret;
	}
	int FindKth(int k)
	{
		int L=1,R=N;
		while (L<R)
		{
			int mid=(L+R)>>1;
			if (Query(mid)>=k) R=mid;
			else L=mid+1;
		}
		return L;
	}
}T;
int Size[MAXN],Tot;
int main()
{
	scanf("%d%d",&N,&M);
	S.Init(N);
	T.Init(N);
	Tot=N;
	for (int i=1;i<=N;++i)
	{
		T.Add(1,1);
		Size[i]=1;
	}
	for (int i=1;i<=M;++i)
	{
		int c;
		scanf("%d",&c);
		if (c==0)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a=S.Fa(a);b=S.Fa(b);
			if (a==b) continue;
			T.Add(Size[a],-1);
			T.Add(Size[b],-1);
			if(a<b)
			{
				Size[a]+=Size[b];
				S.S[b]=a;
				T.Add(Size[a],1);
			}else
			{
				Size[b]+=Size[a];
				S.S[a]=b;
				T.Add(Size[b],1);
			}
			Tot--;
		}
		if (c==1)
		{
			int k;
			scanf("%d",&k);
			k=Tot-k+1;
			printf("%d\n",T.FindKth(k));
		}
	}
	return 0;
}
