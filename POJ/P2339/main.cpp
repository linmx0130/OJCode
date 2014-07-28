#include <cstdio>
#include <cstring>
#include <cstdlib>
char Map[2][102][102];
int R,C,N;
const int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int Died[256];
void Main()
{
	scanf("%d%d%d",&R,&C,&N);
	for (int i=1;i<=R;++i)
	{
		scanf("%s",Map[0][i]+1);
	}
	for (int I=0;I<N;++I)
	{
		int c=I&1;
		for (int i=1;i<=R;++i)
		{
			for (int j=1;j<=C;++j)
			{
				int nx,ny;
				Map[c^1][i][j]=Map[c][i][j];
				for (int k=0;k<4;++k)
				{
					nx=i+dxy[k][0],ny=j+dxy[k][1];
					if (nx>0 && ny >0 && nx<=R &&ny <=C)
					{
						if (Map[c][nx][ny]==Died[Map[c][i][j]])
						{
							Map[c^1][i][j]=Died[Map[c][i][j]];
						}
					}
				}
			}
		}
	}
	for (int i=1;i<=R;++i)
	{
		puts(Map[N&1][i]+1);
	}
	puts("");
}
int main()
{
	int T;
	Died['R']='P';Died['P']='S';Died['S']='R';
	for (scanf("%d",&T);T;T--) Main();
	return 0;
}
