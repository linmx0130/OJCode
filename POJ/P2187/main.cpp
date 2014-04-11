#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using std::sort;
using std::max;
#define MAXN 50005
inline double sqr(double t)
{
	return t*t;
}
struct Point
{
	double x,y;
	inline Point operator-(Point &t)
	{
		Point a;
		a.x=this->x-t.x;
		a.y=this->y-t.y;
		return a;
	}
	inline Point operator+(Point &t)
	{
		Point a;
		a.x=this->x+t.x;
		a.y=this->y+t.y;
		return a;
	}
	inline double det(const Point &t)
	{
		return this->x*t.y-this->y*t.x;
	}
	inline double dist(Point &t)
	{
		return sqr(this->x-t.x)+sqr(this->y-t.y);
	}
}d[MAXN];
bool cmpPoint(const Point &a,const Point &b)
{
	if (a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
int N;
int convex[MAXN],cTotal;
void get_convex_hull()
{
	sort(d,d+N,cmpPoint);
	int Total=0,tmp;
	for (int i=0;i<N;++i)
	{
		while (Total>1 && (d[convex[Total-1]]-d[convex[Total-2]]).det(d[i]-d[convex[Total-1]])<=0) Total--;
		convex[Total++]=i;
	}
	tmp=Total;
	for (int i=N-2;i>=0;--i)
	{
		while (Total>tmp && (d[convex[Total-1]]-d[convex[Total-2]]).det(d[i]-d[convex[Total-1]])<=0) Total--;
		convex[Total++]=i;
	}
	cTotal=Total;
}

int main()
{
	scanf("%d",&N);
	for (int i=0;i<N;++i)
	{
		scanf("%lf%lf",&d[i].x,&d[i].y);
	}	
	get_convex_hull();
	double Ans=0;
	for (int i=0;i<cTotal;++i)
	{
		for (int j=0;j<i;++j)
		{
			Ans=max(Ans,d[convex[i]].dist(d[convex[j]]));
		}
	}
	printf("%.0lf\n",Ans);
	return 0;
}
