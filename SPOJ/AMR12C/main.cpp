#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define EPS 1e-7
#define MAXN 55
int N;
struct Point
{
	double x,y;
}P[MAXN];
double S[MAXN];
double Sqr(double t){return t*t;}
double Dist(double x1,double y1,double x2,double y2)
{
	return sqrt(Sqr(x1-x2)+Sqr(y1-y2));
}
double GetAns(double x,double y)
{
	double ret=0,tmp;
	for (int i=1;i<=N;++i)
	{
		tmp=Dist(x,y,P[i].x,P[i].y)/S[i];
		if (tmp>ret)ret=tmp;
	}
	return ret;
}
double GetansY(double x)
{
	double L=-1e+6,R=1e+6;
	while (R-L>EPS)
	{
		double ml=(L+L+R)/3.0,mr=(L+R+R)/3.0;
		if (GetAns(x,ml)>GetAns(x,mr))
			L=ml;
		else 
			R=mr;
	}
	return GetAns(x,L);
}
void Main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
		scanf("%lf%lf%lf",&P[i].x,&P[i].y,&S[i]);
	double L=-1e+6,R=1e+6;
	while (R-L>EPS)
	{
		double ml=(L+L+R)/3.0,mr=(L+R+R)/3.0;
		if (GetansY(ml)>GetansY(mr))
		{
			L=ml;
		}else
		{
			R=mr;
		}
	}
	printf("%lf\n",GetansY(L));
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--) Main();
	return 0;
}
