/* UVa 104
   By Sweetdumplings
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 25
#define NoAns "no arbitrage sequence exists"
double F[MAXN][MAXN][MAXN];
int Path[MAXN][MAXN][MAXN];
int N;
void PrintAns(int s,int t,int k)
{
	if (k==1) return ;
	PrintAns(s,Path[s][t][k],k-1);
	printf("%d ",Path[s][t][k]);
};
void Solve()
{
	memset(F,0,sizeof(F));
	memset(Path,0,sizeof(Path));
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=N;++j)
		{
			if (i!=j) 
			{
				scanf("%lf",&F[i][j][1]);
			}else
			{
				F[i][j][1]=1;
			}
		}
	}
	for (int t=2;t<=N+1;++t)
	{
		for (int k=1;k<=N;++k)
		{
			for (int i=1;i<=N;++i)
			{
				for (int j=1;j<=N;++j)
				{
					if (F[i][j][t]<F[i][k][t-1]*F[k][j][1])
					{
						F[i][j][t]=F[i][k][t-1]*F[k][j][1];
						Path[i][j][t]=k;
					}
				}
			}
		}
		for (int i=1;i<=N;++i)
		{
			if (F[i][i][t]>=1.01) 
			{
				printf("%d ",i);
				PrintAns(i,i,t);
				printf("%d\n",i);
				return ;
			}
		}
	}
	puts(NoAns);
}
int main()
{
	//freopen("UVa104.in","r",stdin);
	while (scanf("%d",&N)!=EOF)
	{
		Solve();
	}
	//while(1);
	return 0;
}
