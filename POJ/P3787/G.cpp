#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using std::sort;
#define MAXN 55
int N;
struct Point
{
	double x,y;
	Point operator-(Point &a)
	{
		Point ret;
		ret.x=x-a.x;
		ret.y=y-a.y;
		return ret;
	}
	double det(const Point & a)
	{
		return x*a.y-y*a.x;
	}
}d[MAXN];
bool cmp(const Point &a,const Point &b)
{
	return (a.x!=b.x) ? a.x<b.x : a.y<b.y;
}
int convex[MAXN],ctot;
void get_convex_hull()
{
	sort(d+1,d+N+1,cmp);
	ctot=0;
	for (int i=1;i<=N;++i)
	{
		while (ctot>1 && ((d[convex[ctot]]-d[convex[ctot-1]]).det(d[i]-d[convex[ctot]])<=0)) ctot--;
		convex[++ctot]=i;
	}
	int tmp=ctot;
	for (int i=N;i>=1;--i)
	{
		while (ctot>tmp && ((d[convex[ctot]]-d[convex[ctot-1]]).det(d[i]-d[convex[ctot]])<=0)) ctot--;
		convex[++ctot]=i;
	}
}
void Main()
{
	scanf("%d",&N);printf("%d ",N);
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		scanf("%lf%lf",&d[i].x,&d[i].y);
	}
	get_convex_hull();
	printf("%d\n",ctot-1);
	int startp=1;
	for (int i=2;i<ctot;++i)
	{
		if ((d[convex[i]].y>d[convex[startp]].y) || (d[convex[i]].y==d[convex[startp]].y && d[convex[i]].x<d[convex[startp]].x)) startp=i;
	}
	for (int i=startp;i>=1;--i)
	{
		printf("%.0f %.0f\n",d[convex[i]].x,d[convex[i]].y);
	}
	for (int i=ctot-1;i>startp;--i)
	{
		printf("%.0f %.0f\n",d[convex[i]].x,d[convex[i]].y);
	}
}
int main()
{
	int P;scanf("%d",&P);
	for (;P;P--) Main();
	return 0;
}
