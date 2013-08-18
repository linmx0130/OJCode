#include <cstdio>
#include <cstring>
#include <cstdlib>
int N,Ans;
char Map[6][6];
bool Castle[6][6];
bool CanCastle(int X,int Y)
{
	for(int i=X-1;i>0;--i)
	{
		if (Map[i][Y]=='X') break;
		if (Castle[i][Y]) return 0;
	}
	for (int i=X+1;i<=N;++i)
	{
		if (Map[i][Y]=='X') break;
		if (Castle[i][Y]) return 0;
	}
	for (int i=Y-1;i>0;--i)
	{
		if (Map[X][i]=='X') break;
		if (Castle[X][i]) return 0;
	}
	for (int i=Y+1;i<=N;++i)
	{
		if (Map[X][i]=='X') break;
		if (Castle[X][i]) return 0;
	}
	return 1;
}
void Search(int X,int Y,int Count)
{
	if ((X==N+1)&&(Y==1))
	{
		if (Count>Ans)
		{
			Ans=Count;
		}
		return ;
	}
	int Nx=X,Ny=Y+1;
	if (Ny>N)
	{
		Nx=X+1;Ny=1;
	}
	if (Map[X][Y]=='X') {Search(Nx,Ny,Count);return ;}
	if (CanCastle(X,Y))
	{
		Castle[X][Y]=1;
		Search(Nx,Ny,Count+1);
		Castle[X][Y]=0;
	}
	Search(Nx,Ny,Count);
}
void Work()
{
	memset(Map,0,sizeof(Map));
	Ans=0;
	for (int i=1;i<=N;++i)
	{
		scanf("%s",Map[i]+1);
	}
	Search(1,1,0);
	printf("%d\n",Ans);
}
int main()
{
	while (scanf("%d",&N),N)
	{
		Work();
	}
	return 0;
}
