#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 25002
int N,T;
struct Pair
{
	int l,r;
}d[MAXN];
bool cmp(const Pair & a,const Pair & b)
{
	return a.l!=b.l?a.l<b.l:a.r<b.r;
}
int main()
{
	scanf("%d%d",&N,&T);
	for (int i=1;i<=N;++i)
	{
		scanf("%d%d",&d[i].l,&d[i].r);
	}
	std::sort(d+1,d+N+1,cmp);
	int now=1,Qh=0,Qt=0;
	int Ans=0;
	while (now<=T)
	{
		while (d[Qh].r<now && Qh<=N) Qh++;
		if (d[Qh].l>now|| Qh>N) {puts("-1");return 0;}
		int choose=d[Qh].r;
		Qt=Qh;
		while (d[Qt+1].l<=now && Qt<N) {Qt++;if (d[Qt].r>choose) choose=d[Qt].r;}
		Ans++;
		now=choose+1;
	}
	printf("%d\n",Ans);
}
