/*
 * I programmed in Linux, but RQNOJ is on Windows...
 * The IO made me WA for 7 times!!!
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
#define MAXN 200002
int N,M;
long long S;
long long W[MAXN],V[MAXN];
int Query[MAXN][2];
long long Stone_Num[MAXN],Stone_V[MAXN];
long long Abs(long long A){return A>0?A:-A;}
long long Check(long long nW)
{
	for (int i=1;i<=N;++i)
	{
		Stone_Num[i]=Stone_Num[i-1];
		Stone_V[i]=Stone_V[i-1];
		if (W[i]>=nW)
		{
			Stone_Num[i]++;
			Stone_V[i]+=V[i];
		}
	}
	long long Ret=0;
	for (int i=1;i<=M;++i)
	{
		int l=Query[i][0]-1,r=Query[i][1];
		Ret+=(Stone_Num[r]-Stone_Num[l])*(Stone_V[r]-Stone_V[l]);
	}
	return S-Ret;
}
int main()
{
	scanf("%d%d%I64d",&N,&M,&S);
	long long L=0,R=0;
	for (int i=1;i<=N;++i)
	{
		scanf("%I64d%I64d",&W[i],&V[i]);
		if (W[i]>R) R=W[i];
	}
	for (int i=1;i<=M;++i)
	{
		scanf("%d%d",&Query[i][0],&Query[i][1]);
	}
	long long Ans=(~0ULL)>>1;
	while (L<R)
	{
		long long Mid=(L+R)/2;
		long long Tmp=Check(Mid);
		if (Abs(Tmp)<Ans) Ans=Abs(Tmp);
		if (Tmp>0)
		{
			R=Mid-1;
		}
		if (Tmp<0)
		{
			L=Mid+1;
		}
		if (Tmp==0) {printf("0\n");return 0;}
	}
	Ans=Abs(Check(L));
	long long T=Abs(Check(L+1));
	if (T<Ans) Ans=T;
	T=Abs(Check(L-1));
	if (T<Ans) Ans=T;
	printf("%I64d\n",Ans);
	return 0;
}
