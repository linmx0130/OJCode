#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 18
int M,N;
bool Map[MAXN][MAXN];
bool NMap[MAXN][MAXN];
int Ans[MAXN][MAXN];
int Best[MAXN][MAXN];
int BestTot=(~0U>>1);
void Search(int now)
{
	if (now>N)
	{
		memcpy(NMap,Map,sizeof(NMap));
		for (int i=1;i<=N;++i)
		{
			if (Ans[1][i])
			{
				NMap[0][i]=!NMap[0][i];
				NMap[1][i]=!NMap[1][i];
				NMap[1][i-1]=!NMap[1][i-1];
				NMap[1][i+1]=!NMap[1][i+1];
				NMap[2][i]=!NMap[2][i];

			}
		}
		for (int i=2;i<=M;++i)
		{
			for (int j=1;j<=N;++j)
			{
				Ans[i][j]=NMap[i-1][j]?1:0;
				if (Ans[i][j])
				{
					NMap[i-1][j]=!NMap[i-1][j];
					NMap[i][j]=!NMap[i][j];
					NMap[i][j-1]=!NMap[i][j-1];
					NMap[i][j+1]=!NMap[i][j+1];
					NMap[i+1][j]=!NMap[i+1][j];
				}
			}
		}
		for (int i=1;i<=M;++i)
		{
			for (int j=1;j<=N;++j)
			{
				if (NMap[i][j]) return ;
			}
		}
		int Tmp=0;
		for (int i=1;i<=M;++i)
		{
			for (int j=1;j<=N;++j)
			{
				if (Ans[i][j]) Tmp++;
			}
		}
		if (Tmp<BestTot) 
		{
			BestTot=Tmp;
			memcpy(Best,Ans,sizeof(Best));
		}
		return ;
	}
	Ans[1][now]=0;
	Search(now+1);
	Ans[1][now]=1;
	Search(now+1);
}
int main()
{
	scanf("%d%d",&M,&N);
	for (int i=1;i<=M;++i)
	{
		for (int j=1;j<=N;++j)
		{
			int T;
			scanf("%d",&T);
			Map[i][j]=T;
		}
	}
	Search(1);
	if (BestTot>5000) puts("IMPOSSIBLE");
	else 
	{
		for (int i=1;i<=M;++i)
		{
			for (int j=1;j<N;++j)
			{
				printf("%d ",Best[i][j]);
			}
			printf("%d\n",Best[i][N]);
		}
	}
	return 0;
}
