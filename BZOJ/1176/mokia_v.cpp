#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXW 4005
#define LOWBIT(t) (t&(-t))
struct TreeArr
{
	int D[MAXW][MAXW];
	int N;
	void Add(int x,int y,int v)
	{
		for (int i=x;i<=N;i+=LOWBIT(i))
		{
			for (int j=y;j<=N;j+=LOWBIT(j))
			{
				//printf(":%d %d\n",i,j);
				D[i][j]+=v;
			}
		}
	}
	int Sum(int x,int y)
	{
		int ret=0;
		for (int i=x;i;i-=LOWBIT(i))
		{
			for (int j=y;j;j-=LOWBIT(j))
			{
				ret+=D[i][j];
			}
		}
		return ret;
	}
	void Clean()
	{
		memset(D,0,sizeof(D));
	}
}T;
int main()
{
	freopen("Mokia.in","r",stdin);
	freopen("Mokia.out","w",stdout);
	int W;
	scanf("%d",&W);scanf("%d",&W);
	T.N=W;
	int K;
	for (;~scanf("%d",&K);)
	{
		if (K==3) return 0;
		if (K==1)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			T.Add(x,y,z);
		}
		if (K==2)
		{
			int x0,y0,x1,y1;
			scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
			printf("%d\n",T.Sum(x1,y1)-T.Sum(x0-1,y1)-T.Sum(x1,y0-1)+T.Sum(x0-1,y0-1));
		}
	}
	return 0;
}
