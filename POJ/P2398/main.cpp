#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 1005
using std::sort;
struct Point
{
	int x,y;
	Point operator- (const Point & t)
	{
		Point ret;
		ret.x=x-t.x;
		ret.y=y-t.y;
		return ret;
	}
	int det(const Point &t)
	{
		return x*t.y-y*t.x;
	}
}Toys[MAXN];
struct CardBoardT
{
	Point U,L,v;
}C[MAXN];
int N,M,x1,y1,x2,y2;
bool cmp(const CardBoardT & a, const CardBoardT & b)
{
	return a.U.x!=b.U.x?a.U.x<b.U.x:a.L.y<b.L.y;
}
bool OnLeft(CardBoardT & L, Point & Toy)
{
	Point lt=Toy-L.L;
	Point ut=Toy-L.U;
	if (ut.det(L.v)<0 && lt.det(L.v) <0) return 1;
	return 0;
}
int BoxCount[MAXN];
int Count[MAXN];
void Main()
{
	for (int i=1;i<=N;++i)
	{
		scanf("%d%d",&C[i].U.x,&C[i].L.x);
		C[i].U.y=y1;
		C[i].L.y=y2;
		C[i].v=C[i].U-C[i].L;
	}
	sort(C+1,C+N+1,cmp);
	memset(BoxCount,0,sizeof(BoxCount));
	for (int i=1;i<=M;++i)
	{
		scanf("%d%d",&Toys[i].x,&Toys[i].y);
		bool flag=0;
		for (int j=1;j<=N;++j)
		{
			if (OnLeft(C[j],Toys[i]))
			{
				flag=1;
				BoxCount[j]++;
				break;
			}
		}
		if (!flag) BoxCount[N+1]++;
	}
	memset (Count,0,sizeof(Count));
	for (int i=1;i<=N+1;++i) 
	{
		Count[BoxCount[i]]++;
	}
	puts("Box");
	for (int i=1;i<=M;++i)
	{
		if (Count[i])
		{
			printf("%d: %d\n",i,Count[i]);
		}
	}
}
int main()
{
	while (scanf("%d%d%d%d%d%d",&N,&M,&x1,&y1,&x2,&y2),N)
	{
		Main();
	}
}
