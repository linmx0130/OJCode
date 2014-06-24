#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using std::min;
#define MAXN 100002
int N,F;
double D[MAXN];
double A[MAXN];
double S[MAXN];
double MinS[MAXN];
bool Check(double Ans)
{
	for (int i=1;i<=N;++i) A[i]=D[i]-Ans;
	for (int i=1;i<=N;++i) S[i]=S[i-1]+A[i];
	for (int i=1;i<=N;++i) MinS[i]=min(MinS[i-1],S[i]);
	for (int i=F;i<=N;++i)
	{
		if (S[i]>=MinS[i-F]) return true;
	}
	return false;
}
int main()
{
	scanf("%d%d",&N,&F);
	for (int i=1;i<=N;++i) scanf("%lf",&D[i]);
	double L=0,R=2000;
	while (R-L>0.0005)
	{
		double Mid=(L+R)/2;
		if (Check(Mid))
		{
			L=Mid;
		}else 
		{
			R=Mid;
		}
	}
	printf("%.0lf\n",L*1000);
	return 0;
}
