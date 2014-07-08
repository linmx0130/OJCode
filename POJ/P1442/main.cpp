#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define MAXN 30005
int N,M;
struct Treap
{
	int L[MAXN],R[MAXN],D[MAXN],K[MAXN],S[MAXN],Root,tot;
	void RotateL(int &o)
	{
		int k=R[o];
		R[o]=L[k];
		L[k]=o;
		S[o]=S[L[o]]+S[R[o]]+1;
		S[k]=S[L[k]]+S[R[k]]+1;
		o=k;
	}
	void RotateR(int &o)
	{
		int k=L[o];
		L[o]=R[k];
		R[k]=o;
		S[o]=S[L[o]]+S[R[o]]+1;
		S[k]=S[L[k]]+S[R[k]]+1;
		o=k;
	}
	int Insert(int &now,int d)
	{
		if (now==0)
		{
			now=++tot;
			D[now]=d;
			S[now]=1;
			L[now]=R[now]=0;
			return K[now]=rand();
		}
		S[now]++;
		if (d<=D[now]) 
		{
			if (Insert(L[now],d)>K[now]) RotateR(now);
		}
		else 
		{
			if (Insert(R[now],d)>K[now]) RotateL(now);
		}
	}
	void Insert(int d){Insert(Root,d);}
	int FindKth(int now,int k)
	{
		if (S[L[now]]+1==k) return D[now];
		if (S[L[now]]>=k) return FindKth(L[now],k);
		if (S[L[now]]+1<k) return FindKth(R[now],k-S[L[now]]-1);
	}
	int FindKth(int k)
	{
		return FindKth(Root,k);
	}
	void Init()
	{
		Root=tot=0;
	}
	void Print(int now)
	{
		if (L[now]) Print(L[now]);
		printf("%d ",D[now]);
		if (R[now]) Print(R[now]);
	}
	void Print()
	{
		Print(Root);
		puts("");
	}
}T;
int A[MAXN],U[MAXN],UT;
int main()
{
	srand(19960515);
	scanf("%d%d",&N,&M);
	T.Init();
	for (int i=1;i<=N;++i) scanf("%d",&A[i]);
	for (int i=1;i<=M;++i) scanf("%d",&U[i]);
	UT=1;
	int GetI=0;
	for (int i=1;i<=N;++i)
	{
		T.Insert(A[i]);
		while (U[UT]==i)
		{
			printf("%d\n",T.FindKth(++GetI));
			UT++;
		}
	//	T.Print();
	}
	return 0;
}
