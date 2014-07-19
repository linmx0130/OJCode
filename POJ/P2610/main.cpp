#include <cstdio>
#include <cstring>
#include <cstdlib>
double Gopher[2],Dog[2];
double x,y;
double Sqr(double x){return x*x;}
double Dis(double x1,double y1,double x2,double y2)
{
	return Sqr(x1-x2)+Sqr(y1-y2);
}
int main()
{
	scanf("%lf%lf%lf%lf",&Gopher[0],&Gopher[1],&Dog[0],&Dog[1]);
	while (scanf("%lf%lf",&x,&y)!=EOF)
	{
		double d1=Dis(Gopher[0],Gopher[1],x,y);
		double d2=Dis(Dog[0],Dog[1],x,y);
		if (d1*4<d2)
		{
			printf("The gopher can escape through the hole at (%.3f,%.3f).\n",x,y);
			return 0;
		}
	}
	puts("The gopher cannot escape.");
	return 0;
}
