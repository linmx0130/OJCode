#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 1002
#define MAXDIG 40
#define DIG 1000
struct BigNum
{
	int d[MAXDIG+1],point;
	BigNum()
	{
		this->init();
	}
	void init()
	{
		memset(d,0,sizeof(d));
		point=MAXDIG;
	}
	void operator+=(int t)
	{
		d[MAXDIG]+=t;
		for (int i=MAXDIG;d[i]>=DIG||i>point;--i)
		{
			d[i-1]+=d[i]/DIG;
			d[i]%=DIG;
			if (point==i) point--;
		}
	}
	void operator*=(int t)
	{
		for (int i=MAXDIG;i>=point;--i) d[i]*=t;
		for (int i=MAXDIG;d[i]>=DIG||i>point;--i)
		{
			d[i-1]+=d[i]/DIG;
			d[i]%=DIG;
			if (point==i) point--;
		}
	}
	bool operator> (BigNum &t)
	{
		if (point!=t.point) return point<t.point;
		for (int i=point;i<=MAXDIG;++i) 
		{
			if (d[i]!=t.d[i]) return d[i]>t.d[i];
		}
		return 0;
	}
	void print()
	{
		printf("%d",d[point]);
		for (int i=point+1;i<=MAXDIG;++i)
		{
			printf("%03d",d[i]);
		}
		puts("");
	}
};
BigNum f[MAXN][2],tmp;
int n,c1,c2,c3,c4;
int main()
{
	scanf("%d%d%d%d%d",&n,&c1,&c2,&c3,&c4);
	c2+=c3;
	for (int i=1;i<=n;++i)
	{
		//input
		if (i-c1>=0)
		{
			tmp=f[i-c1][0];
			tmp+=1;
			if (tmp>f[i][0]) f[i][0]=tmp;
		}
		//ctrla+ctrlc
		if (i-c2>=0)
		{
			tmp=f[i-c2][0];
			if (tmp>f[i][1]) f[i][1]=tmp;
		}
		//ctrlv
		for (int j=2;i-c4*j>0;++j)
		{
			tmp=f[i-c4*j][1];
			tmp*=j;
			if (tmp>f[i][0]) f[i][0]=tmp;
		}
	}
	tmp.init();
	//tmp=0;
	for (int i=1;i<=n;++i)
	{
		if (f[i][1]>tmp) tmp=f[i][1];
		if (f[i][0]>tmp) tmp=f[i][0];
	}
	tmp.print();
//	printf("%lld\n",tmp);
	return 0;
}
