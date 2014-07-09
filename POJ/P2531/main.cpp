#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 22
int C[MAXN][MAXN];
int N;
int A[MAXN],Atot,B[MAXN],Btot,Ans;
inline void GetAns()
{
	int tmp=0;
	for (int i=1;i<=Atot;++i)
	{
		for (int j=1;j<=Btot;++j)
		{
			tmp+=C[A[i]][B[j]];
		}
	}
	if (tmp>Ans) Ans=tmp;
}
void Search(int now)
{
	if (now==N+1) {GetAns();return ;}
	++Atot;
	A[Atot]=now;
	Search(now+1);
	--Atot;
	++Btot;
	B[Btot]=now;
	Search(now+1);
	--Btot;
}
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=N;++j) scanf("%d",&C[i][j]);
	}
	Search(1);
	printf("%d\n",Ans);
	return 0;
}
