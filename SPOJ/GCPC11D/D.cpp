#include <cstdio>
#include <cstring>
#include <cstdlib>
char Map[10][10];
const int Line[6][4][2]=
{
	{{1,5},{2,4},{3,3},{4,2}},
	{{2,2},{3,3},{4,4},{5,5}},
	{{4,2},{4,4},{4,6},{4,8}},
	{{5,5},{4,6},{3,7},{2,8}},
	{{4,8},{3,7},{2,6},{1,5}},
	{{2,8},{2,6},{2,4},{2,2}}
};
const int Pos[12][2]={{1,5},{2,2},{2,4},{2,6},{2,8},{3,3},{3,7},{4,2},{4,4},{4,6},{4,8},{5,5}};
const int InLine[12][2]={{0,4},{1,5},{0,5},{4,5},{3,5},{0,1},{3,4},{0,2},{1,2},{2,3},{2,4},{1,3}};
bool Used[27];
int LineSum[6],LineUse[6];
bool Check()
{
	for (int i=0;i<6;++i)
	{
		if (LineSum[i]!=26) return 0;
		if (LineUse[i]!=4) return 0;
	}
	return 1;
}
void Search(int now)
{
	if (now==12)
	{
		if (Check())
		{
			for (int i=1;i<=5;++i) puts(Map[i]+1);
		}
		exit(0);
	}
	if (Map[Pos[now][0]][Pos[now][1]]!='x')
	{
		Search(now+1);
		return ;
	}
	for (int i=1;i<=26;++i)
	{
		if (!Used[i])
		{
			LineSum[InLine[now][0]]+=i;
			LineSum[InLine[now][1]]+=i;
			LineUse[InLine[now][0]]++;
			LineUse[InLine[now][1]]++;
			Used[i]=1;
			Map[Pos[now][0]][Pos[now][1]]='A'+i-1;
			if (LineSum[InLine[now][0]]<=26 && LineSum[InLine[now][1]]<=26
			&& LineUse[InLine[now][0]]<=4 && LineUse[InLine[now][1]]<=4 )
				Search(now+1);
			Map[Pos[now][0]][Pos[now][1]]='x';
			LineSum[InLine[now][0]]-=i;
			LineSum[InLine[now][1]]-=i;
			LineUse[InLine[now][0]]--;
			LineUse[InLine[now][1]]--;
			Used[i]=0;
		}
	}
}
int main()
{
	for (int i=1;i<=5;++i)
	{
		scanf("%s",Map[i]+1);
	}
	for (int i=0;i<12;++i)
	{
		if (Map[Pos[i][0]][Pos[i][1]]!='x')
		{
			Used[Map[Pos[i][0]][Pos[i][1]]-'A'+1]=1;
		}
	}
	for (int i=0;i<6;++i)
	{
		for (int j=0;j<4;++j)
		{
			if (Map[Line[i][j][0]][Line[i][j][1]]!='x')
			{
				LineSum[i]+=Map[Line[i][j][0]][Line[i][j][1]]-'A'+1;
				LineUse[i]++;
			}
		}
	}
	Search(0);
	return 0;
}
