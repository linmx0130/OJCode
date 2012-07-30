#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 1100
#define MAXN 1100
#define LOWBIT(t) (t&(-t))
class TArr
{
public:
	int d[MAXN+5][MAXN+5];
	int n;
	void Add(int x,int y,int c)
	{
		for (int i=x;i<=n;i+=LOWBIT(i))
		{
			for (int j=y;j<=n;j+=LOWBIT(j))
			{
				d[i][j]+=c;
			}
		}
	}
	int sum(int x,int y)
	{
		int ret=0;
		for (int i=x;i>0;i-=LOWBIT(i))
		{
			for (int j=y;j>0;j-=LOWBIT(j))
			{
				ret+=d[i][j];
			}
		}
		return ret;
	}
	void init(int k)
	{
		memset(d,0,sizeof(d));
		n=k;
	}
}T;
int main()
{
	int op;
	for(;~scanf("%d",&op);)
	{
		if (op==0) {scanf("%d",&op); T.init(op);continue;}
		if (op==3) return 0;
		if (op==1)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			T.Add(x+1,y+1,z);
		}
		if (op==2)
		{
			int l,b,r,t;
			scanf("%d%d%d%d",&l,&b,&r,&t);
			printf("%d\n",T.sum(r+1,t+1)-T.sum(l,t+1)-T.sum(r+1,b)+T.sum(l,b));
		}
	}
	return 0;
}
