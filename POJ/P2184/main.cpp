#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 105
#define MAXD 2005
#define _(t) (t+100000)
#define __(t) (t-100000)
#define NOW(t) (t&1)
#define LAST(t) ((t&1)^1)
inline int max(int a,int b)
{return a>b?a:b;}
int N;
int Cow[MAXN][2];
int F[2][MAXD*MAXN];
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		scanf("%d%d",&Cow[i][0],&Cow[i][1]);
	}
	int SizeofF=sizeof(F[0]);
	memset(F[0],200,SizeofF);
	F[0][_(0)]=0;
	int Empty=F[0][0];
	int Ans=0;
	for (int i=1;i<=N;++i)
	{
		memcpy(F[NOW(i)],F[LAST(i)],SizeofF);
		for (int j=0;j<MAXD*MAXN;j++)
		{
			if (F[LAST(i)][j]!=Empty)
			{
				if (F[LAST(i)][j]+Cow[i][1]>F[NOW(i)][j+Cow[i][0]])
				{
					F[NOW(i)][j+Cow[i][0]]=F[LAST(i)][j]+Cow[i][1];
					if ( ( __(j+Cow[i][0]) >0) && (F[NOW(i)][j+Cow[i][0]]>0))
						Ans=max(Ans,F[NOW(i)][j+Cow[i][0]]+__(j+Cow[i][0]));
				}
			}
		}
	}
	printf("%d\n",Ans);
	return 0;
}
