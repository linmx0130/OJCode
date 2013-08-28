#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 102
#define RW(l,r) (Sum[r]-Sum[l-1])
int w[MAXN],Sum[MAXN];
int N;
int F[MAXN][MAXN];
bool Done[MAXN][MAXN];
int Dp(int L,int R)
{
	if (Done[L][R]) return F[L][R];
	Done[L][R]=1;
	if (L==R)
	{
		return F[L][R]=0;
	}
	for (int k=L;k<R;++k)
	{
		if (Dp(L,k)+Dp(k+1,R)+RW(L,R)<F[L][R])
		{
			F[L][R]=Dp(L,k)+Dp(k+1,R)+RW(L,R);
		}
	}
	return F[L][R];
}
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		scanf("%d",&w[i]);
		Sum[i]=Sum[i-1]+w[i];
	}
	memset(F,60,sizeof(F));
	printf("%d\n",Dp(1,N));
	return 0;
}
