#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 200
char Map[MAXN][MAXN];
int N,M;
struct DType
{
	int x,y;
}d[26][MAXN*MAXN];
int Ptot[26]; 
void InputMap()
{
	if (scanf("%d%d",&N,&M),!N) exit(0);
	for (int i=1;i<=N;++i)
	{
		scanf("%s",Map[i]+1);
	}
}
bool Check(int id)
{
	int MaxX=0,MinX=105,MaxY=0,MinY=105;
	for (int i=1;i<=Ptot[id];++i)
	{
		if (d[id][i].x>MaxX) MaxX=d[id][i].x;
		if (d[id][i].y>MaxY) MaxY=d[id][i].y;
		if (d[id][i].x<MinX) MinX=d[id][i].x;
		if (d[id][i].y<MinY) MinY=d[id][i].y;
	}
	if (MaxX-MinX<2) return 0;
	if (MaxY-MinY<2) return 0;
	int BoardSize=2*(MaxX-MinX+MaxY-MinY);
	if (Ptot[id]!=BoardSize) return 0;
	for (int i=MinX;i<=MaxX;++i)
	{
		for (int j=MinY;j<=MaxY;++j)
		{
			if (Map[i][j]>='A'&&Map[i][j]<='Z') if (Map[i][j]!=id+'A') return 0;
		}
	}
	return 1;
}
int main()
{
	while (1) 
	{
		memset(Map,0,sizeof(Map));
		InputMap();
		memset(Ptot,0,sizeof(Ptot));
		for (int i=1;i<=N;++i)
		{
			for (int j=1;j<=M;++j)
			{
				if (Map[i][j]>='A'&&Map[i][j]<='Z')
				{
					int Num=Map[i][j]-'A';
					Ptot[Num]++;
					d[Num][Ptot[Num]].x=i;
					d[Num][Ptot[Num]].y=j;
				}
			}
		}
		for (int i=0;i<26;++i)
		{
			if (Check(i))
			{
				printf("%c",i+'A');
			}
		}
		puts("");
	}
	return 0;
}
