#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXL 302
#define MAXW 602
int n,m;
char objs[MAXL];
char dic[MAXW][MAXL];
int match[MAXW],startp[MAXW];
int f[MAXL];
inline int min(int a,int b)
{
	return a<b?a:b;
}
void getmatch(int now,int start)
{
	int i=start,j=1;
	while (i<=m)
	{
		if (j==strlen(dic[now]+1)+1) break;
		if (objs[i]==dic[now][j])
		{
			if (j==1)
			{
				startp[now]=i;
			}
			i++;j++;
		}
		else 
		{
			i++;
		}
	}
	if (j==strlen(dic[now]+1)+1)match[now]=i-1;
	else match[now]=m+1;
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",objs+1);
	for (int i=1;i<=n;++i)
	{
		scanf("%s",dic[i]+1);
	}
	memset(f,60,sizeof(f));
	f[0]=0;
	for (int i=1;i<=m;++i)
	{
		f[i]=min(f[i],f[i-1]+1);
		for (int j=1;j<=n;++j)
		{
			if (startp[j]<i) getmatch(j,i);
			if (match[j]<=m)
			{
				f[match[j]]=min(f[match[j]],
								f[i-1]+(match[j]-i+1)-strlen(dic[j]+1));
			}
		}
	}
	printf("%d\n",f[m]);
	return 0;
}
