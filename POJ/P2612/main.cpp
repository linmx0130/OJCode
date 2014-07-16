#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 12
int N;
char Map[MAXN][MAXN];
char Touch[MAXN][MAXN];
char Out[MAXN][MAXN];
char RealOut[MAXN][MAXN];
int dxy[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;++i) scanf("%s",Map[i]+1);
	for (int i=1;i<=N;++i) scanf("%s",Touch[i]+1);
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=N;++j) Out[i][j]=Map[i][j];
	}
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=N;++j)
		{
			int Count=0;
			if (Map[i][j]=='*') continue;
			for (int k=0;k<8;++k)
			{
				int Nx=i+dxy[k][0],Ny=j+dxy[k][1];
				if (Nx>=1 && Nx<=N && Ny>=1 && Ny<=N)
				{
					if (Map[Nx][Ny]=='*') Count++;
				}
			}
			Out[i][j]=Count+'0';
		}
	}
	bool TouchMine=0;
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=N;++j)
		{
			if (Touch[i][j]=='x')
			{
				RealOut[i][j]=Out[i][j];
				if (Map[i][j]=='*') TouchMine=1;
			}else
			{
				RealOut[i][j]='.';
			}
		}
	}
	if (TouchMine)
	{
		for (int i=1;i<=N;++i)
		{
			for (int j=1;j<=N;++j)
			{
				if (Map[i][j]=='*') RealOut[i][j]='*';
			}
		}
	}
	for (int i=1;i<=N;++i)
	{
		puts(RealOut[i]+1);
	}
	return 0;
}
