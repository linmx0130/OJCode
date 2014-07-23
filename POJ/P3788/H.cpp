#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 55
int N;
struct Point
{
	int x,y;
}d[MAXN];
bool cmp(const Point & a,const Point &b)
{
	return a.y!=b.y?a.y>b.y:a.x<b.x;
}
double JD[2];
int JDtot;
int Output[5000000][3];
void Main()
{
	scanf("%d",&N);printf("%d ",N);
	scanf("%d",&N);
	int starty=-0x7fffffff,endy=0x7fffffff;
	for (int i=1;i<=N;++i)
	{
		scanf("%d%d",&d[i].x,&d[i].y);
		if (d[i].y>starty) starty=d[i].y;
		if (d[i].y<endy) endy=d[i].y;
	}
	d[N+1]=d[1];
	int Ans=0;
	for (int i=starty-1;i>endy;--i)
	{
		JDtot=0;
		for (int j=1;j<=N;++j)
		{
			if (d[j].y>i && d[j+1].y<=i)
			{
				double m=(double)(d[j].x-d[j+1].x)/(d[j].y-d[j+1].y);
				JD[JDtot]=(double)d[j].x+m*((double)i-d[j].y);
				JDtot++;
			}
			else if (d[j].y<i && d[j+1].y>=i)
			{
				double m=(double)(d[j].x-d[j+1].x)/(d[j].y-d[j+1].y);
				JD[JDtot]=(double)d[j].x+m*((double)i-d[j].y);
				JDtot++;
			}
		}
		if (JD[0]>JD[1]){double k=JD[0];JD[0]=JD[1];JD[1]=k;}
		int startx=JD[0]+1,endx;
		if ((double)(int)(JD[1])==JD[1]) endx=JD[1]-1;
		else endx=JD[1];
		if (startx<=endx)
		{
			Ans++;
			Output[Ans][0]=i;
			Output[Ans][1]=startx;
			Output[Ans][2]=endx;
		}
	}
	printf("%d\n",Ans);
	for (int i=1;i<=Ans;++i) printf("%d %d %d\n",Output[i][0],Output[i][1],Output[i][2]);
}
int main()
{
	int P;scanf("%d",&P);
	for (;P;P--) Main();
	return 0;
}
