/*
ID: linmx011
LANG: C++
TASK: castle
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 52
int map[MAXN][MAXN];
int n,m;
int dxy[][3]={{0,-1,1},{-1,0,2},{0,1,4},{1,0,8}};
namespace MapSet
{
	int Set[MAXN*MAXN];
	inline int getNum(int x,int y)
	{
		return (x-1)*m+y;
	}
	void Init()
	{
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=m;++j)
			{
				Set[getNum(i,j)]=getNum(i,j);
			}
		}
	}
	int Fa(int v)
	{
		return (Set[v]==v)?v:Set[v]=Fa(Set[v]);
	}
	void Merge(int x1,int y1,int x2,int y2)
	{
		int fa=Fa(getNum(x1,y1)),fb=Fa(getNum(x2,y2));
		Set[fb]=fa;
	}
	bool Diff(int x1,int y1,int x2,int y2)
	{
		return Fa(getNum(x1,y1))!=Fa(getNum(x2,y2));
	}
}
namespace Solve1
{
	bool mark[MAXN][MAXN];
	int maplist[MAXN*MAXN][3],maptot;
	int search(int x,int y)
	{
		mark[x][y]=1;
		int ret=1;
		for (int i=0;i<4;++i)
		{
			int wx=x+dxy[i][0],wy=y+dxy[i][1];
			if (wx>n||wy>m||wx<1||wy<1) continue;
			if ((!(map[x][y]&dxy[i][2]))&&(!mark[wx][wy]))
			{
				ret+=search(wx,wy);
				MapSet::Merge(x,y,wx,wy);
			}
		}
		return ret;
	}
	void Main()
	{
		MapSet::Init();
		memset(mark,0,sizeof(mark));
		int ret=0,ans=0;
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=m;++j)
			{
				if (!mark[i][j])
				{
					ans++;
					maplist[ans][0]=i;
					maplist[ans][1]=j;
					int t=search(i,j);
					if (t>ret) ret=t;
					maplist[ans][2]=t;
				}
			}
		}
		printf("%d\n%d\n",ans,ret);
		maptot=ans;
	}
	int getSize(int x,int y)
	{
		for (int i=1;i<=maptot;++i)
		{
			if (!MapSet::Diff(x,y,maplist[i][0],maplist[i][1]))
			{
				return maplist[i][2];
			}
		}
	}
}
namespace Solve2
{
	void Main()
	{
		int ret=0,x,y,dir;
		for (int j=1;j<=m;++j)
		{
			for (int i=n;i>=1;--i)
			{
				for (int k=1;k<=2;++k)
				{
					if (map[i][j]&dxy[k][2])
					{
						int wx=i+dxy[k][0],wy=j+dxy[k][1];
						if ((wx>n)||(wy>m)||(wx<1)||(wy<1)) continue;
						if (MapSet::Diff(i,j,wx,wy))
						{
							//puts("WWW");
							int s1=Solve1::getSize(i,j),s2=Solve1::getSize(wx,wy);
							if (s1+s2>ret)
							{
								ret=s1+s2;
								x=i;y=j;dir=k;
							}
						}
					}
				}
			}
		}
		printf("%d\n%d %d %c\n",ret,x,y,(dir==1)?'N':'E');
	}
}
int main()
{
//	freopen("castle.in","r",stdin);
//	freopen("castle.out","w",stdout);
	while (~scanf("%d%d",&n,&m)){
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=m;++j)
			{
				scanf("%d",&map[i][j]);
			}
		}
		Solve1::Main();
//		Solve2::Main();
	}
}
