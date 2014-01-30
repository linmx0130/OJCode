#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 200005
int Tmp[MAXN],SA[MAXN],SA2[MAXN],Rank[MAXN],Rank2[MAXN],Num[MAXN];
int Height[MAXN];
char S[MAXN];
bool same(int i,int j,int l)
{
	return (Tmp[i]==Tmp[j])&&(Tmp[i+l]==Tmp[j+l]);
}
void GetSA(int n,int m)
{
	int i,j,p,tot;
	for (i=0;i<=m;++i) Num[i]=0;
	for (i=0;i<n;++i) ++Num[Rank[i]=S[i]];
	for (i=1;i<=m;++i) Num[i]+=Num[i-1];
	for (i=n-1;i>=0;--i) SA[--Num[Rank[i]]]=i;
	for (j=1,p=1;p<n;j*=2,m=p)
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
void GetHeight(int n)
{
	for (int i=0;i<n;++i) Rank[SA[i]]=i;
	int h=0;
	Height[0]=0;
	for (int i=0;i<n;++i)
	{
		if (h>0) h--;
		if (Rank[i])
		{
			int j=SA[Rank[i]-1];
			for (;j+h<n && i+h<n;++h)
			{
				if (S[j+h]!=S[i+h]) break;
			}
		}
		Height[Rank[i]]=h;
	}
}
char B[MAXN>>1];
int main()
{
	scanf("%s",S);
	scanf("%s",B);
	int N=strlen(S);
	int N1=N;
	S[N]='$';N++;
	int Nb=strlen(B);
	for (int i=0;i<Nb;++i)
	{
		S[N+i]=B[i];
	}
	N=strlen(S);
	GetSA(N,256);
	GetHeight(N);
	int Ans=0;
	for (int i=1;i<N;++i)
	{
		if ((SA[i]<N1)^(SA[i-1]<N1))
		{
			if (Height[i]>Ans) Ans=Height[i];
		}
	}
	printf("%d\n",Ans);
	return 0;
}
