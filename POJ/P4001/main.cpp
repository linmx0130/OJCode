#include <cstdio>
#include <cstring>
#include <cstdlib>
#define GENERAL 1
#define CHARIOT 2
#define CANNON 3
#define HORSE 4
#define OBJECT 5
int dxy[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int hdxy[8][2]={{2,-1},{2,1},{-1,2},{1,2},{-2,-1},{-2,1},{1,-2},{-1,-2}};
int Map[12][12];
int N;
char Buf[10];
int Ox,Oy;
bool Check(int Ox,int Oy)
{
	int Piece=0;
	for (int i=Oy-1;i>=1;--i)
	{
		if (Map[Ox][i]==CHARIOT && Piece==0) return 0;
		if (Map[Ox][i]==CANNON && Piece==1) return 0;
		if (Map[Ox][i]!=0) Piece++;
	}
	Piece=0;
	for (int i=Oy+1;i<=10;++i)
	{
		if (Map[Ox][i]==CHARIOT && Piece==0) return 0;
		if (Map[Ox][i]==CANNON && Piece==1) return 0;
		if (Map[Ox][i]!=0) Piece++;
	}
	Piece=0;
	for (int i=Ox-1;i>=1;--i)
	{
		if (Map[i][Oy]==CHARIOT && Piece==0) return 0;
		if (Map[i][Oy]==CANNON && Piece==1) return 0;
		if (Map[i][Oy]!=0) Piece++;
	}
	Piece=0;
	for (int i=Ox+1;i<=10;++i)
	{
		if (Map[i][Oy]==CHARIOT && Piece==0) return 0;
		if (Map[i][Oy]==CANNON && Piece==1) return 0;
		if (Map[i][Oy]==GENERAL && Piece==0) return 0;
		if (Map[i][Oy]!=0) Piece++;
	}
	for (int i=1;i<=10;++i)
	{
		for (int j=1;j<=10;++j)
		{
			if (Map[i][j]==HORSE)
			{
				for (int k=0;k<8;++k)
				{
					int Hx=i+hdxy[k][0],Hy=j+hdxy[k][1];
					int Sx=i+dxy[k>>1][0],Sy=j+dxy[k>>1][1];
					if (Hx>=1 && Hx<=10 && Hy>=1 && Hy<=10)
					{
						if (Map[Sx][Sy]==0 && Map[Hx][Hy]==OBJECT) return 0;
					}
				}
			}
		}
	}
	return 1;
}
void Main()
{
	int x,y;
	scanf("%d%d",&Ox,&Oy);
	memset(Map,0,sizeof(Map));
	Map[Ox][Oy]=OBJECT;
	for (int i=1;i<=N;++i)
	{
		scanf("%s%d%d",Buf,&x,&y);
		if (Buf[0]=='G') Map[x][y]=GENERAL;
		if (Buf[0]=='R') Map[x][y]=CHARIOT;
		if (Buf[0]=='H') Map[x][y]=HORSE;
		if (Buf[0]=='C') Map[x][y]=CANNON;
	}
	for (int i=0;i<4;++i)
	{
		int Nx=Ox+dxy[i][0],Ny=Oy+dxy[i][1];
		int k=Map[Nx][Ny];Map[Nx][Ny]=Map[Ox][Oy];
		Map[Ox][Oy]=0;
		if (Nx>=1 && Nx<=3 &&Ny>=4 &&Ny<=6) 
		if (Check(Nx,Ny))
		{
			puts("NO");
			return ;
		}
		Map[Ox][Oy]=OBJECT;
		Map[Nx][Ny]=k;
	}
	puts("YES");
}
int main()
{
	while (scanf("%d",&N),N)
	{
		Main();
	}
	return 0;
}
