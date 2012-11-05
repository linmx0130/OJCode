#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 200002
int N,R,Q;
struct Ath
{
	int s,w,id;
}d[MAXN],win[MAXN],lost[MAXN];
bool cmp(Ath a,Ath b)
{
	return (a.s!=b.s)?a.s>b.s:a.id<b.id;
}

int main()
{
	scanf("%d%d%d",&N,&R,&Q);
	int n=N;
	N+=N;
	for (int i=1;i<=N;++i)
	{
		scanf("%d",&d[i].s);
		d[i].id=i;
	}
	for (int i=1;i<=N;++i)
	{
		scanf("%d",&d[i].w);
	}
	std::sort(d+1,d+N+1,cmp);
	for (;R;R--)
	{
		for (int i=1,j=1;i<=N;i+=2,j++)
		{
			if (d[i].w>d[i+1].w)
			{
				win[j]=d[i];
				win[j].s++;
				lost[j]=d[i+1];
			}else
			{
				win[j]=d[i+1];
				win[j].s++;
				lost[j]=d[i];
			}
		}
		int Wh=1,Lh=1,Nh=0;
		while (Wh<=n&&Lh<=n)
		{
			++Nh;
			if (cmp(win[Wh],lost[Lh]))
			{
				d[Nh]=win[Wh];
				Wh++;
			}else
			{
				d[Nh]=lost[Lh];
				Lh++;
			}
		}
		while (Wh<=n)
		{
			d[++Nh]=win[Wh++];
		}
		while (Lh<=n)
		{
			d[++Nh]=lost[Lh++];
		}
	}
	printf("%d\n",d[Q].id);
	return 0;
}
