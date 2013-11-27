#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using std::sort;
#define MAXN 200005
int SA[MAXN],Rank[MAXN],Num[MAXN],SA2[MAXN],Rank2[MAXN],Tmp[MAXN];
char S[MAXN];
bool same(int i,int j, int l)
{
	return (Tmp[i]==Tmp[j]) && (Tmp[i+l]==Tmp[j+l]);
}
void GetSA(int n,int m)
{
	int i,j,p,tot;
	for (i=0;i<=m;++i) Num[i]=0;
	for (i=0;i<n;++i) ++Num[Rank[i]=S[i]];
	for (i=1;i<=m;++i) Num[i]+=Num[i-1];
	for (i=n-1;i>=0;--i) SA[--Num[Rank[i]]]=i;
	for (int j=1,p=1;p<n;j*=2,m=p)
	{
		for (tot=0,i=n-j;i<n;++i) SA2[tot++]=i;
		for (i=0;i<n;++i) if (SA[i]>=j) SA2[tot++]=SA[i]-j;
		for (i=0;i<=m;++i) Num[i]=0;
		for (i=0;i<n;++i) ++Num[Rank2[i]=Rank[SA2[i]]];
		for (i=1;i<=m;++i) Num[i]+=Num[i-1];
		for (i=n-1;i>=0;--i) SA[--Num[Rank2[i]]]=SA2[i],Tmp[i]=Rank[i];
		for (Rank[SA[0]]=1,p=1,i=1;i<n;++i)
		{
			Rank[SA[i]]=same(SA[i-1],SA[i],j)?p:++p;
		}
	} 
}
char Ans[MAXN];
struct TmpT
{
	int Start,SA;
}d[MAXN];
bool cmp(TmpT a, TmpT b)
{
	return a.SA<b.SA;
}
int main()
{
	scanf("%s",S);
	int N=strlen(S);
	for (int i=0;i<N;++i) S[i+N]=S[i];
	//S[N++]='{';
	N+=N;
	//S[N++]='#';
	GetSA(N,255);
	
	for (int i=0;i<N;++i)
	{
		Rank[SA[i]]=i;
	}
	int Ndiv2=N>>1;
	/*
	for (int i=0;i<N;++i)
	{
		printf("%s:%d\n",S+i,Rank[i]);
	}*/
	int Cnt=0;
	for (int i=0;i<N;++i)
	{
		if (SA[i]<Ndiv2)
		{
			Ans[Cnt++]=S[SA[i]+Ndiv2-1];
		}
	}
	printf("%s\n",Ans);
	//while(1);
	return 0;
}
