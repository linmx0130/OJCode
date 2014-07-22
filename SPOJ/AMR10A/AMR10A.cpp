#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define MAXN 50005
int N,Q;
struct Point
{
	double x,y;
	Point operator- (Point & t)
	{
		Point ret;
		ret.x=x-t.x;
		ret.y=y-t.y;
		return ret;
	}
	double det(const Point & t)
	{
		return x*t.y-y*t.x;
	}
}D[MAXN];
double F[MAXN];
int main()
{
	scanf("%d%d",&N,&Q);
	for (int i=0;i<N;++i)
	{
		scanf("%lf%lf",&D[i].x,&D[i].y);
	}
	F[0]=0;F[1]=0;
	for (int i=2;i<N;++i)
	{
		F[i]=F[i-1]+(D[i]-D[0]).det(D[i-1]-D[0]);
	}
	double S=F[N-1];
	for (;Q;Q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		double t1=(D[b]-D[0]).det(D[a]-D[0]);
		double s2=F[b]-F[a]-t1;
		double s1=S-s2;
		if (s1<s2) printf("%.1lf\n",s1/2.0);
		else printf("%.1lf\n",s2/2.0);
	}
	return 0;
}
