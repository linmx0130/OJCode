#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXeN 90002
#define MAXN 302
int n;
bool found[MAXN+5][MAXN+5];
int q[MAXeN][3];
int bomb[MAXN+5][MAXN+5];
const int dxy[][2]={{0,0},{1,0},{0,1},{-1,0},{0,-1}};
bool nosafe[MAXN+5][MAXN+5];
int main()
{
	scanf("%d",&n);
	memset(bomb,60,sizeof(bomb));
	for (int i=1;i<=n;++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		for (int i=0;i<5;++i)
		{
			if ((x+dxy[i][0]>300)||(x+dxy[i][0]<0)||(y+dxy[i][1]>300)||(y+dxy[i][1]<0)) continue;
			if (z<bomb[x+dxy[i][0]][y+dxy[i][1]]) bomb[x+dxy[i][0]][y+dxy[i][1]]=z;
			nosafe[x+dxy[i][0]][y+dxy[i][1]]=1;
		}
	}
	found[0][0]=1;
	if (bomb[0][0]==0) {puts("-1");return 0;}
	if (!nosafe[0][0]) {puts("0");return 0;}
	q[1][0]=0,q[1][1]=0;
	int qh=0,qt=1;
	while (qh<qt)
	{
		int nx=q[++qh][0],ny=q[qh][1],step=q[qh][2];
		for (int i=1;i<=4;++i)
		{
			int wx=nx+dxy[i][0],wy=ny+dxy[i][1];
			if ((wx>MAXN)||(wy>MAXN)||(wx<0)||(wy<0)) continue;
			if (!nosafe[wx][wy])
			{
				printf("%d\n",step+1);
				return 0;
			}
			if ((!found[wx][wy])&& (bomb[wx][wy]>step+1))
			{
				found[wx][wy]=1;
				q[++qt][0]=wx,q[qt][1]=wy,q[qt][2]=step+1;
			}
		}
	}
	puts("-1");
	return 0;
}
