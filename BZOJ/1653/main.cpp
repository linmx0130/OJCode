#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 12
int N,S;
int C[MAXN][MAXN];
int Used[MAXN];
int Stack[MAXN];
void Search(int now)
{
	if (now>N)
	{
		int Tmp=0;
		for (int i=1;i<=N;++i)
		{
			Tmp+=Stack[i]*C[N-1][i-1];
		}
		if (Tmp==S)
		{
			for (int i=1;i<N;++i)printf("%d ",Stack[i]);
			printf("%d\n",Stack[N]);
			exit(0);
		}
		return ;
	}
	for (int i=1;i<=N;++i)
	{
		if (!Used[i])
		{
			Used[i]=1;
			Stack[now]=i;
			Search(now+1);
			Used[i]=0;
		}
	}
}
int main()
{
	scanf("%d%d",&N,&S);
	C[0][0]=1;
	for (int i=1;i<=N;++i)
	{
		C[i][0]=1;
		for (int j=1;j<=i;++j)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	Search(1);
	return 0;
}
