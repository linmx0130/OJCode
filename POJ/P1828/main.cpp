#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using std::sort;
#define MAXN 50005
struct Point
{
	int x,y;
}D[MAXN];
int N;
bool cmp(const Point & a, const Point & b)
{
	return a.x!=b.x?a.x>b.x:a.y>b.y;
}
void Main()
{
	for (int i=1;i<=N;++i)
	{
		scanf("%d%d",&D[i].x,&D[i].y);
	}
	sort(D+1,D+N+1,cmp);
	int Ans=1;
	int LastY=D[1].y;
	for (int i=2;i<=N;++i)
	{
		if (D[i].y>LastY)
		{
			Ans++;
			LastY=D[i].y;
		}
	}
	printf("%d\n",Ans);
}
int main()
{
	while (scanf("%d",&N),N)
	{
		Main();
	}
	return 0;
}
