#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using std::sort;
#define MAXN 1002
int N,L;
template <typename T>
T sqr(T a)
{
	return a*a; 
}
struct Point
{
	double x,y;
	inline Point operator- (const Point &t)
	{
		Point ret;
		ret.x=x-t.x;
		ret.y=y-t.y;
		return ret;
	}
	inline Point operator+ (const Point &t)
	{
		Point ret;
		ret.x=x+t.x;
		ret.y=y+t.y;
		return ret;
	}
	inline int det(const Point &t)
	{
		return x*t.y-t.x*y;
	}
	inline double dist(Point &t)
	{
		return sqrt(sqr(x-t.x)+sqr(y-t.y));
	}
}d[MAXN];
bool cmpPoint(const Point &a, const Point &b)
{
	if (a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
int convex[MAXN],cTotal;
void get_convex_hull()
{
	sort(d,d+N,cmpPoint);
	int Total=0,tmp;
	for (int i=0;i<N;++i)
	{
		while ( (Total>1) && 
			    ((d[convex[Total-1]]-d[convex[Total-2]]).det(
			    d[i]-d[convex[Total-1]])<=0) ) Total--;
		convex[Total++]=i;
	}
	tmp=Total;
	for (int i=N-2;i>=0;--i)
	{
		while ( (Total>tmp) &&
				((d[convex[Total-1]]-d[convex[Total-2]]).det(
				d[i]-d[convex[Total-1]])<=0) ) Total--;
		convex[Total++]=i;
	}
	cTotal=Total;
}
int main()
{
	scanf("%d%d",&N,&L);
	for (int i=0;i<N;++i)
	{
		scanf("%lf%lf",&d[i].x,&d[i].y);
	}
	get_convex_hull();
	double Ans=0;
	for (int i=0;i<cTotal-1;++i)
	{
		Ans+=d[convex[i]].dist(d[convex[i+1]]);
	}
	Ans+=d[convex[0]].dist(d[convex[cTotal-1]]);
	Ans+=3.1415926*2*L;
	printf("%.0lf\n",Ans);
	return 0;
}
