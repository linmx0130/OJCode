#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using std::sort;
#define MAXN 105
struct Point
{
	int x,y;
	Point operator + (const Point & b)
	{
		Point t;
		t.x=x+b.x;
		t.y=y+b.y;
		return t;
	}
	Point operator - (const Point & b)
	{
		Point t;
		t.x=x-b.x;
		t.y=y-b.y;
		return t;
	}
	int det(const Point &b)
	{
		return x*b.y-b.x*y;
	}
}d[MAXN];
int N;
int convex[MAXN],cTotal;
bool cmp(const Point &a,const Point &b)
{
	return a.x!=b.x?a.x<b.x:a.y<b.y;
}
void get_convex_hull()
{
	sort(d,d+N,cmp);
	int Total=0,tmp;
	for (int i=0;i<N;++i)
	{
		while (Total>1 && (d[convex[Total-1]] - d[convex[Total-2]]).det(d[i] - d[convex[Total-1]])<=0) Total--;
		convex[Total++]=i;
	}
	tmp=Total;
	for (int i=N-2;i>=0;--i)
	{
		while (Total>tmp && (d[convex[Total-1]] - d[convex[Total-2]]).det(d[i] - d[convex[Total-1]])<=0) Total--;
		convex[Total++]=i;
	}
	cTotal=Total;
}
int main()
{
	int x,y;
	N=0;
	while (scanf("%d%d",&x,&y)!=EOF)
	{
		d[N].x=x;d[N].y=y;N++;
	}
	get_convex_hull();
	cTotal--;
	int Start;
	for (int i=0;i<cTotal;++i)
	{
		if (d[convex[i]].x==0 && d[convex[i]].y==0 ) 
		{
			Start=i;
			break;
		}
	}
	printf("(0,0)\n");
	int i=Start+1;
	while (i!=Start)
	{
		printf("(%d,%d)\n",d[convex[i]].x,d[convex[i]].y);
		if (++i >= cTotal) i=0;	
	}
	return 0;
}
