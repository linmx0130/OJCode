#include <cstdio>
#include <cstring>
#include <cstdlib>
int Mat1[2][2]={{1,1},{1,0}};
int Mat[2][2];
int E[2][2]={{1,0},{0,1}};
void Cheng()
{
	int Ret[2][2];
	memset(Ret,0,sizeof(Ret));
	for (int i=0;i<2;++i)
	{
		for (int j=0;j<2;++j)
		{
			for (int k=0;k<2;++k)
			{
				Ret[i][j]+=Mat[i][k]*Mat1[k][j];
			}
		}
	}
	memcpy(Mat,Ret,sizeof(Mat));
}
long long G[25];
void Work()
{
	int I,J,GI,T;
	scanf("%d%d%d",&I,&GI,&J);
	memcpy(Mat,E,sizeof(E));
	for (int i=1;i<I;++i)
	{
		Cheng();
	}
	if (I==1)
	{
		T=GI;
	}else {
		GI-=Mat[0][1];
		if (GI%Mat[0][0]!=0) {puts("-1");return ;}
		if (GI<=0) {puts("-1");return ;}
		T=GI/Mat[0][0];
	}
	G[0]=1;G[1]=T;
	for (int i=2;i<=J;++i) G[i]=G[i-1]+G[i-2];
	printf("%lld\n",G[J]);
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--)
	{
		Work();
	}
}
