#include <cstdio>
#include <cstring>
#define MAXN 10002
int n;
int d[MAXN];
int f[MAXN];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",d+i);
	int maxt=0;
	for (int i=1;i<=n;++i) 
	{
		if (f[i-1]<0) f[i]=d[i];
		else f[i]=f[i-1]+d[i];
		if (f[i]>f[maxt]) maxt=i;
	}
	if (maxt==0) puts("0");
	int start;
	for (int i=maxt;i>=1;--i)
	{
		if (f[i]==d[i]) {start=i;break;}
	}
	printf("%d %d\n%d\n",start,maxt,f[maxt]);
	return 0;
}
