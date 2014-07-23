#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using std::max;
using std::min;
int F[60][1100];
int main()
{
	memset(F,60,sizeof(F));
	for (int j=0;j<=1020;++j)
	{
		F[1][j]=j;
	}
	for (int i=2;i<=51;++i)
	{
		F[i][1]=1;
		F[i][2]=2;
		for (int j=3;j<=1020;++j)
		{
			for (int k=2;k<j;++k)
			{
				F[i][j]=min(max(F[i-1][k-1],F[i][j-k])+1,F[i][j]);
			}
		}
	}
	int P;scanf("%d",&P);
	for (;P;P--) 
	{
		int num,b,m;
		scanf("%d%d%d",&num,&b,&m);
		printf("%d %d\n",num,F[b][m]);
	}
	return 0;
}
