#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 202
int n,ktot;
double x[MAXN],y[MAXN];
double k[MAXN*MAXN];
bool zero=0;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%lf%lf",x+i,y+i);
	}
	for (int i=1;i<=n;++i)
	{
		for (int j=i+1;j<=n;++j)
		{
			double ktmp;
			if (x[i]-x[j]) 
			{
				ktmp=(y[i]-y[j])/(x[i]-x[j]);
				k[++ktot]=ktmp;
			}else zero=1;
		}
	}
	std::sort(k+1,k+ktot+1);
	//k[0]=k[1];
	int ans=1;
	for (int i=2;i<=ktot;++i)
	{
		if (k[i]!=k[i-1]) ans++;
	}
	if (zero) ans++;
	printf("%d\n",ans);
	return 0;
}
