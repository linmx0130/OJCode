#include <cstdio>
#include <cstring>
#include <cstdlib>
#define QSIZE 1000000
#define MAXN 22
bool Vis[MAXN][MAXN][16384];
int Map[MAXN][MAXN];
int dxy[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int Rdxy[4]={2,3,0,1};
int N,M,L,K;
int hx,hy;
int Q[QSIZE][4];
int Hash(int hx,int hy)
{
	int dx,dy;
	for (int i=0;i<4;++i)
	{
		dx=hx+dxy[i][0];dy=hy+dxy[i][1];
		if (Map[dx][dy]==Map[hx][hy]+1)
		{
			return Hash(dx,dy)*4+i;
		}
	}
	return 0;
}
void UnHash(int hx,int hy,int hash)
{
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=M;++j)
		{
			if (Map[i][j]>0) Map[i][j]=0;
		}
	}
	Map[hx][hy]=1;
	for (int i=2;i<=L;++i)
	{
		int dx,dy,dct=hash%4;
		dx=hx+dxy[dct][0];
		dy=hy+dxy[dct][1];
		Map[dx][dy]=i;
		hash>>=2;
		hx=dx;hy=dy;
	}
}
void SnakeGo(int hx,int hy,int dct)
{
	int T=0;
	for (int i=1;i<=L;++i)
	{
		Map[hx+dxy[dct][0]][hy+dxy[dct][1]]=Map[hx][hy];
		for (int i=0;i<4;++i)
		{
			int dx=hx+dxy[i][0],dy=hy+dxy[i][1];
			if (Map[dx][dy]==Map[hx][hy]+1)
			{
				Map[hx][hy]=0;
				hx=dx;hy=dy;dct=Rdxy[i];
				break;
			}
		}
	}
}
void Search()
{
	int Qh=0,Qt=1;
	Q[1][0]=hx;Q[1][1]=hy;Q[1][2]=Hash(hx,hy);Q[1][3]=0;
	Vis[Q[1][0]][Q[1][1]][Q[1][2]]=1;
	if ((hx==1)&&(hy==1))
	{
		puts("0");
		return ;
	}
	while (Qh!=Qt)
	{
		++Qh;
		int nx=Q[Qh][0],ny=Q[Qh][1];
		for (int i=0;i<4;++i)
		{
			UnHash(nx,ny,Q[Qh][2]);
			int dx=nx+dxy[i][0],dy=ny+dxy[i][1];
			if (dx<1||dx>N||dy<1||dy>M) continue;
			if (Map[dx][dy]==0)
			{
				SnakeGo(nx,ny,i);++Qt;
				Q[Qt][0]=dx;Q[Qt][1]=dy;Q[Qt][3]=Q[Qh][3]+1;
				if (dx==1 && dy==1)
				{
					printf("%d\n",Q[Qt][3]);
					return ;
				}
				Q[Qt][2]=Hash(dx,dy);
				if (Vis[Q[Qt][0]][Q[Qt][1]][Q[Qt][2]]) Qt--;
				else Vis[Q[Qt][0]][Q[Qt][1]][Q[Qt][2]]=1;
			}
		}
	}
	puts("-1");
}
void Main()
{
	memset(Map,0,sizeof(Map));
	memset(Vis,0,sizeof(Vis));
	for (int i=1;i<=L;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Map[x][y]=i;
		if (i==1) 
		{
			hx=x;hy=y;
		}
	}
	scanf("%d",&K);
	for (int i=1;i<=K;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Map[x][y]=-1;
	}
	Search();
}
int main()
{
	int Count=1;
	while (true)
	{
		scanf("%d%d%d",&N,&M,&L);
		if (N==0) return 0;
		printf("Case %d: ",Count++);
		Main();
	}
}
