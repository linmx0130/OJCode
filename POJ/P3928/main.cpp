#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#define MAXN 20002
#define ASIZE 100000
int N;
int A[MAXN],AA[MAXN];
#define LOWBIT(t) (t&(-t))
struct TreeArr
{
	int d[ASIZE+5];
	void init()
	{
		memset(d,0,sizeof(d));
	}
	void mark(int pos,int t)
	{
		for (int i=pos;i<=ASIZE;i+=LOWBIT(i))
		{
			d[i]+=t;
		}
	}
	int sum(int pos)
	{
		int Ret=0;
		for (int i=pos;i>0;i-=LOWBIT(i))
		{
			Ret+=d[i];
		}
		return Ret;
	}

}T1;
struct TreeArr2
{
	int d[ASIZE+5];
	void init()
	{
		memset(d,0,sizeof(d));
	}
	void mark(int pos,int t)
	{
		for (int i=pos;i;i-=LOWBIT(i))
		{
			d[i]+=t;
		}
	}
	int sum(int pos)
	{
		int Ret=0;
		for (int i=pos;i<=ASIZE;i+=LOWBIT(i))
		{
			Ret+=d[i];
		}
		return Ret;
	}
}T2;

void Main()
{
	T1.init();
	T2.init();
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		scanf("%d",&A[i]);
	}
	for (int i=1;i<=N;++i)
	{
		T2.mark(A[i],1);
	}
	long long Ans=0;
	for (int i=1;i<=N;++i)
	{
		T2.mark(A[i],-1);
		Ans+=(long long)T1.sum(A[i]-1)*T2.sum(A[i]+1);
		T1.mark(A[i],1);
	}
	T1.init();
	T2.init();
	for (int i=1;i<=N;++i)
	{
		T1.mark(A[i],1);
	}
	for (int i=1;i<=N;++i)
	{
		T1.mark(A[i],-1);
		Ans+=(long long)T1.sum(A[i]-1)*T2.sum(A[i]+1);
		T2.mark(A[i],1);
	}


	std::cout <<Ans<<std::endl;
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--)
	{
		Main();
	}
}
