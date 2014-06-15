#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using std::min;
#define MAXN 202
#define MAXK 35
int N,K;
int D[MAXN];
int F[MAXN][MAXK];
int Cost[MAXN][MAXN];
void Main()
{
	memset(Cost,0,sizeof(Cost));
	memset(F,60,sizeof(F));
	for (int i=1;i<=N;++i)
	{
		scanf("%lld",&D[i]);
	}
	for (int i=1;i<=N;++i)
	{
		for (int j=i;j<=N;++j)
		{
			int mid=(i+j)/2;
			for (int k=i;k<=j;++k)
			{
				Cost[i][j]+=abs(D[k]-D[mid]);
			}
		}
	}
	F[0][0]=0;
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=i;++j)
		{
			for (int k=1;k<=K;++k)
			{
				F[i][k]=min(F[i][k],F[j-1][k-1]+Cost[j][i]);
			}
		}
	}
	printf("Total distance sum = %d\n",F[N][K]);
}
int main()
{
	int Count=0;
	while (scanf("%d%d",&N,&K),N!=0)
	{
		printf("Chain %d\n",++Count);
		Main();
		puts("");
	}
	return 0;
}
