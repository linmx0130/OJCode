#include <cstdio>
#include <cstring>
#include <cstdlib>
int N;
struct Point{int x,y;};
Point operator- (const Point & a, const Point & b)
{
	return (Point){a.x-b.x,a.y-b.y};
}
Point D[205];
Point K[205][205];
int GCD(int a,int b)
{
	int r;
	while (b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
void GCDize(Point & t)
{
	if (t.x<0) 
	{
		t.x=-t.x;
		t.y=-t.y;
	}
	int a=GCD(t.x,t.y);
	t.x/=a;t.y/=a;
}
bool Mark[205][205];
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		scanf("%d%d",&D[i].x,&D[i].y);
	}
	for (int i=1;i<=N;++i)
	{
		for (int j=i+1;j<=N;++j)
		{
			K[i][j]=D[i]-D[j];
			GCDize(K[i][j]);
		}
	}
	int Ans=0;
	for (int i=1;i<=N;++i)
	{
		for (int j=i+1;j<=N;++j)
		{
			if (Mark[i][j]) continue;
			int Ret=2;
			for (int k=j+1;k<=N;++k)
			{
				if (K[i][j].x==K[i][k].x && K[i][j].y==K[i][k].y)
				{
					Mark[i][k]=1;
					Ret++;
				}
			}
			if (Ret>Ans) Ans=Ret;
		}
	}
	printf("%d\n",Ans);
	return 0;
}
