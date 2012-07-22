#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 102
#define MAXE 352
int k,e,n;
long long f[MAXE][MAXN];
struct Store
{
	int x,f,c;
}store[MAXN];
bool cmp(Store a,Store b)
{
	return a.x<b.x;
}
inline long long min(long long a,long long b)
{
	return a<b?a:b;
}
int main()
{
	scanf("%d%d%d",&k,&e,&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&store[i].x,&store[i].f,&store[i].c);
	}
	std::sort(store+1,store+n+1,cmp);
	memset(f,60,sizeof(f));
	f[0][0]=0;
	int now=1;
	for (int i=1;i<=e;++i)
	{
		if (store[now].x!=i) {
			for (int j=0;j<=k;++j)
			{
				f[i][j]=f[i-1][j]+j;
			}
		}
		else 
		{
			for (;store[now].x==i;++now){
				for (int j=0;j<=k;++j){
					for (int t=0;t<=store[now].f;++t)
					{
						if (j-t<0)break;
						f[i][j]=min(f[i][j],f[i-1][j-t]+(long long)t*store[now].c+(j-t));
					}
				}
			}
		}
	}
	printf("%lld\n",f[e][k]);
	return 0;
}
