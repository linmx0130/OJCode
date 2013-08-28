#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXM 5002
#define MAXN 505
int N,M,s,t;
struct Edge
{
	int u,v,c;
}E[MAXM];
bool cmp(Edge a,Edge b)
{
	return a.c<b.c;
}
struct USet
{
	int d[MAXN];
	void init(int N)
	{
		for (int i=1;i<=N;++i) d[i]=i;
	}
	int Fa(int t)
	{
		return (d[t]==t)?t:d[t]=Fa(d[t]);
	}
	void Merge(int a,int b)
	{
		int fa=Fa(a),fb=Fa(b);
		d[fb]=fa;
	}
}S;
int gcd(int a,int b)
{
	while (b>0)
	{
		int r=a%b;
		a=b;b=r;
	}
	return a;
}
int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;++i)
	{
		scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].c);
	}
	std::sort(E+1,E+M+1,cmp);
	scanf("%d%d",&s,&t);
	int AnsMax=-1,AnsMin=0;
	for (int MinE=1;MinE<=M;++MinE)
	{
		S.init(N);
		int Max=0;bool found=0;
		for (int i=MinE;i<=M;++i)
		{
			if (S.Fa(E[i].u)!=S.Fa(E[i].v))
			{
				S.Merge(E[i].u,E[i].v);
				Max=E[i].c;
			}
			if (S.Fa(s)==S.Fa(t))
			{
				found=1;break;
			}
		}
		if (found)
		{
			if (!AnsMin)
			{
				AnsMin=E[MinE].c;
				AnsMax=Max;
			}else
			{
				if (((double)AnsMax/AnsMin)>((double)Max/E[MinE].c))
				{
					AnsMin=E[MinE].c;
					AnsMax=Max;
				}
			}
		}
	}
	if (!AnsMin) puts("IMPOSSIBLE");
	else 
	{
		int r=gcd(AnsMax,AnsMin);
		AnsMax/=r;AnsMin/=r;
		if (AnsMin==1) printf("%d\n",AnsMax);
		else printf("%d/%d\n",AnsMax,AnsMin);
	}
	return 0;
}
