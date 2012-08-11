#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXDIG 35
#define MAXN 82
struct BigNum
{
	int d[MAXDIG+2],point;
	BigNum()
	{
		memset(d,0,sizeof(d));
		point=MAXDIG+1;
	}
	void init()
	{
		memset(d,0,sizeof(d));
		point=MAXDIG+1;
	}
	BigNum(int will)
	{
		memset(d,0,sizeof(d));
		point=MAXDIG+1;
		getint(will);
	}
	void getint(int will)
	{
		while(will)
		{
			d[--point]=will%10;
			will/=10;
		}
	}
	BigNum operator*(const BigNum &t)
	{
		BigNum ret(0);
		for (int i=MAXDIG;i>=point;--i)
		{
			for (int j=MAXDIG;j>=t.point;--j)
			{
				ret.d[i+j-MAXDIG]+=d[i]*t.d[j];
				if (i+j-MAXDIG<ret.point) ret.point=i+j-MAXDIG;
			}
		}
		for (int i=MAXDIG;i>ret.point;--i)
		{
			if (ret.d[i]>=10)
			{
				ret.d[i-1]+=ret.d[i]/10;
				ret.d[i]%=10;
			}
		}
		while (ret.d[ret.point]>=10)
		{
			ret.d[ret.point-1]+=ret.d[ret.point]/10;
			ret.d[ret.point]%=10;
			ret.point--;
		}
		return ret;
	}
	BigNum operator*(int t)
	{
		BigNum ret(0);
		for (int i=MAXDIG;i>=point;--i)
		{
			ret.d[i]=d[i]*t;
		}
		ret.point=point;
		for (int i=MAXDIG;i>ret.point;--i)
		{
			if (ret.d[i]>=10)
			{
				ret.d[i-1]+=ret.d[i]/10;
				ret.d[i]%=10;
			}
		}
		while (ret.d[ret.point]>=10)
		{
			ret.d[ret.point-1]+=ret.d[ret.point]/10;
			ret.d[ret.point]%=10;
			ret.point--;
		}
		return ret;
	}

	void operator+=(BigNum t)
	{
		for (int i=MAXDIG;i>=t.point;--i) 
		{
			d[i]+=t.d[i];
		}
		if (t.point<point) point=t.point;
		if (d[point-1]) point--;
		for (int i=MAXDIG;i>point;--i)
		{
			if (d[i]>=10)
			{
				d[i-1]++;
				d[i]-=10;
			}
		}
		if (d[point]>=10)
		{
			d[point-1]++;
			d[point]-=10;
			point--;
		}
	}
	void print()
	{
		for (int i=point;i<=MAXDIG;++i)printf("%d",d[i]);
		puts("");
	}
	bool operator>(BigNum& t)
	{
		if (point!=t.point) return point<t.point;
		for (int i=point;i<=MAXDIG;++i)
		{
			if (d[i]!=t.d[i]) return d[i]>t.d[i];
		}
		return 0;
	}
};
BigNum twopow[85];
int n,m;
BigNum f[MAXN][MAXN][MAXN],Ans;
int q[500000][3];
bool inqueue[MAXN][MAXN][MAXN];
int d[MAXN][MAXN];
void work(int now)
{
	int qh=0,qt=1;
	q[1][0]=1;q[1][1]=m;q[1][2]=0;
	BigNum tmp,ans;
	while (qh<qt)
	{
		++qh;
		int l=q[qh][0],r=q[qh][1],times=q[qh][2];
		if (l>r) 
		{
			if (f[now][l][r]>ans)
			{
				ans=f[now][l][r];
			}
			continue;
		}
		tmp=f[now][l][r];
		tmp+=(twopow[times+1]*d[now][l]);
		if (tmp>f[now][l+1][r])
		{
			f[now][l+1][r]=tmp;
			if (!inqueue[now][l+1][r])
			{
				inqueue[now][l+1][r]=1;
				q[++qt][0]=l+1;
				q[qt][1]=r;
				q[qt][2]=times+1;
			}
		}
		tmp=f[now][l][r];
		tmp+=twopow[times+1]*d[now][r];
		if (tmp>f[now][l][r-1])
		{
			f[now][l][r-1]=tmp;
			if (!inqueue[now][l][r-1])
			{
				inqueue[now][l][r-1]=1;
				q[++qt][0]=l;
				q[qt][1]=r-1;
				q[qt][2]=times+1;
			}
		}
	}
	Ans+=ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) 
	{
		for (int j=1;j<=m;++j)
		{
			scanf("%d",&d[i][j]);
		}
	}
	if ((n==1)&&(m==1))
	{
		printf("%d\n",d[1][1]*2);
		return 0;
	}
	twopow[0].getint(1);
	for (int i=1;i<=m+1;++i) twopow[i]=twopow[i-1]*2;
	for (int i=1;i<=n;++i) 
	{
		work(i);
//		Ans.print();
	}
	Ans.print();
	return 0;
}
