#include <cstdio>
#include <cstring>
#include <cstdlib>
int min(int a,int b){return a<b?a:b;}
#define MAXN 100005
int N;
int F[MAXN][2];
int L[2],S[2];
int Passing[MAXN][2];
int Dribbling[MAXN][2];
void Main()
{
	scanf("%d%d%d%d%d",&N,&L[0],&L[1],&S[0],&S[1]);
	for (int i=1;i<N;++i)
		scanf("%d",&Dribbling[i][0]);
	for (int i=1;i<N;++i)
		scanf("%d",&Passing[i][0]);
	for (int i=1;i<N;++i)
		scanf("%d",&Dribbling[i][1]);
	for (int i=1;i<N;++i)
		scanf("%d",&Passing[i][1]);
	memset(F,60,sizeof(F));
	F[1][0]=L[0];
	F[1][1]=L[1];
	for (int i=1;i<N;++i)
	{
		F[i+1][0]=min(F[i][0]+Passing[i][0],F[i][1]+Dribbling[i][1]);
		F[i+1][1]=min(F[i][1]+Passing[i][1],F[i][0]+Dribbling[i][0]);
	}
	printf("%d\n",min(F[N][0]+S[0],F[N][1]+S[1]));
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--)Main();
	return 0;
}
