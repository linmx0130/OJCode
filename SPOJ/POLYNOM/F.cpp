#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define eps 1e-1
int N;
double x[505];

double Pow(double x,int i)
{
	double ret=1;
	for (;i;i--) ret*=x;
	return ret;
}
void Main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;++i) scanf("%lf",&x[i]);
	if (N<=3) {puts("YES");return ;}
	double a=(x[4]-3*x[3]+3*x[2]-x[1])/6;
	double b=(x[3]-2*x[2]+x[1]-12*a)/2;
	double c=(x[2]-x[1]-7*a-3*b);
	double d=x[1]-a-b-c;
	for (int i=1;i<=N;++i)
	{
	//	printf("%lf\n",a*Pow(i,3)+b*Pow(i,2)+c*Pow(i,1)+d-x[i]);
		if (fabs(a*Pow(i,3)+b*Pow(i,2)+c*Pow(i,1)+d-x[i])>eps)
		{
			puts("NO");
			return ;
		}
	}
	puts("YES");
	return ;
}
int main()
{
	int N;
	for (scanf("%d",&N);N;N--) Main();
	return 0;
}
