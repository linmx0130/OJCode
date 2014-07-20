#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 10002
struct Point
{
	int x,y;
	Point operator - (const Point &t)
	{
		Point ret;
		ret.x=x-t.x;
		ret.y=y-t.y;
		return ret;
	}
	int det(const Point & t)
	{
		return x*t.y-y*t.x;
	}
}d[MAXN];
bool cmpPoint(const Point & a,const Point & b)
{
	return a.x!=b.x?a.x<b.x:a.y<b.y;
}
int N;
int convex[MAXN],ctot;
void get_convex_hull()
{
	std::sort(d+1,d+N+1,cmpPoint);
	ctot=0;
	for (int i=1;i<=N;++i)
	{
		while (ctot>1 && (d[convex[ctot]]-d[convex[ctot-1]]).det(d[i]-d[convex[ctot]])<=0) ctot--;
		convex[++ctot]=i;
	}
	int tmp=ctot;
	for (int i=N;i>=1;--i)
	{
		while (ctot>tmp && (d[convex[ctot]]-d[convex[ctot-1]]).det(d[i]-d[convex[ctot]])<=0) ctot--;
		convex[++ctot]=i;
	}
}
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;++i) scanf("%d%d",&d[i].x,&d[i].y);
	get_convex_hull();
	int Ans=0;
	for (int i=2;i<ctot;++i)
	{
		Ans+=(d[convex[i]]-d[convex[1]]).det(d[convex[i+1]]-d[convex[1]]);
	}
	printf("%d\n",(int)((double)Ans/100.0));
	return 0;
}
