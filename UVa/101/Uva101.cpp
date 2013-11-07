/* UVa 101
   By Sweetdumplings
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define MAXN 30
using namespace std;
int N;
int Pos[MAXN];
int BoxS[MAXN][MAXN];
void ReturnA(int a)
{
	Pos[a]=a;
	BoxS[a][0]=1;
	BoxS[a][1]=a;
}
void ReturnUpX(int x)
{
	int NowPos=Pos[x];
	int NowHigh=0;
	for (NowHigh=1;NowHigh<=BoxS[NowPos][0];++NowHigh)
	{
		if (BoxS[NowPos][NowHigh]==x) break;
	}
	for (int i=NowHigh+1;i<=BoxS[NowPos][0];++i)
	{
		int NowBox=BoxS[NowPos][i];
		ReturnA(NowBox);
	}
	BoxS[NowPos][0]=NowHigh;
}
void GetAPos(int A,int &X,int &Y)
{
	X=Pos[A];
	for (int i=1;i<=BoxS[X][0];++i)
	{
		if (BoxS[X][i]==A)
		{
			Y=i;
			return ;
		}
	}
	fprintf(stderr,"Failed at GetAPos(%d, .. ,..)!\n",A);
}
void MoveAOntoB(int a,int b)
{
	ReturnUpX(a);
	ReturnUpX(b);
	int AX,AY;
	GetAPos(a,AX,AY);
	Pos[a]=Pos[b];
	BoxS[AX][0]--;
	int Bx=Pos[b];
	BoxS[Bx][0]++;
	BoxS[Bx][BoxS[Bx][0]]=a;
}
void MoveAOverB(int a,int b)
{
	ReturnUpX(a);
	int AX,AY;
	GetAPos(a,AX,AY);
	int BX=Pos[b];
	Pos[a]=BX;
	BoxS[AX][0]--;
	BoxS[BX][0]++;
	BoxS[BX][BoxS[BX][0]]=a;
}
void PileAOntoB(int a,int b)
{
	ReturnUpX(b);
	int AX,AY;
	GetAPos(a,AX,AY);
	int BX=Pos[b];
	for (int i=AY;i<=BoxS[AX][0];++i)
	{
		Pos[BoxS[AX][i]]=BX;
		BoxS[BX][++BoxS[BX][0]]=BoxS[AX][i];
	}
	BoxS[AX][0]=AY-1;
}
void PileAOverB(int a,int b)
{
	int AX,AY;
	GetAPos(a,AX,AY);
	int BX=Pos[b];
	for (int i=AY;i<=BoxS[AX][0];++i)
	{
		Pos[BoxS[AX][i]]=BX;
		BoxS[BX][++BoxS[BX][0]]=BoxS[AX][i];
	}
	BoxS[AX][0]=AY-1;
}
void Output()
{
	for (int i=0;i<N;++i)
	{
		printf("%d:",i);
		for (int j=1;j<=BoxS[i][0];++j)
		{
			printf(" %d",BoxS[i][j]);
		}
		putchar('\n');
	}
}
int main()
{
	//freopen("uva101.in","r",stdin);
	//freopen("myout.out","w",stdout);
	while (scanf("%d",&N)!=EOF)
	{
		for (int i=0;i<N;++i)
		{
			Pos[i]=i;
			BoxS[i][0]=1;
			BoxS[i][1]=i;
		}
		char Cmd1[10],Cmd2[10];
		int A,B;
		while (scanf("%s",Cmd1)!=EOF)
		{
			if (Cmd1[0]=='q')
			{
				Output();
				break;
			}
			scanf("%d%s%d",&A,Cmd2,&B);
			if (Pos[A]==Pos[B]) continue;
			if (Cmd1[0]=='m')
			{
				if (Cmd2[1]=='n')
				{
					MoveAOntoB(A,B);
				}
				if (Cmd2[1]=='v')
				{
					MoveAOverB(A,B);
				}
			}
			if (Cmd1[0]=='p')
			{
				if (Cmd2[1]=='n')
				{
					PileAOntoB(A,B);
				}
				if (Cmd2[1]=='v')
				{
					PileAOverB(A,B);
				}
			}
		}
	}
	return 0;
}
