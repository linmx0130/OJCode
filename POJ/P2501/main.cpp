#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXS 30
char Buf[MAXS];
double s=0,v=0;
void toTime(int s)
{
	int h=s/3600;
	s%=3600;
	int m=s/60;
	s%=60;
	printf("%02d:%02d:%02d ",h,m,s);
}
int Time,nV;
bool getData()
{
	int h,m,s;
	int Count=0;
	for (char *c=Buf;*c;c++)
	{
		if ((*c>='0')&&(*c<='9')) Count++;
	}
	if (Count==6)
	{
		sscanf(Buf,"%d:%d:%d",&h,&m,&s);
		Time=h*3600+m*60+s;
		return 0;
	}else 
	{
		sscanf(Buf,"%d:%d:%d%d",&h,&m,&s,&nV);
		Time=h*3600+m*60+s;
		return 1;
	}
}
int main()
{
	int now=0,last=0;;
	while (gets(Buf))
	{
		last=now;
		bool flag=getData();
		now=Time;
		s+=v*(now-last)/3600.0;
		if (flag) v=nV;
		else 
		{
			toTime(now);
			printf("%.2f km\n",s);
		}
	}
	return 0;
}
