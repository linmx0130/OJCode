#include <cstdio>
#include <cstring>
#include <cstdlib>
int N;
int F[125][125];
int main()
{
	F[1][0]=1;
	for (int i=2;i<=120;++i)
	{
		for (int j=0;j<=120;++j)
		{
			F[i][j]+=F[i-1][j];
			F[i][j]+=F[i-2][j];
			for (int k=3;k<=123;++k)
			{
				if (k>i || k>j+2) break;
				F[i][j]+=F[i-k][j-k+2];
			}
		}
	}
	int P;
	scanf("%d",&P);
	for (;P;P--)
	{
		int num,n,k;
		scanf("%d%d%d",&num,&n,&k);
		printf("%d %d\n",num,F[n+2][k]);
	}
	return 0;
}
