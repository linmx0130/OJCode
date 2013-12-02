#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#define MAXN 1000002
int n,m;
int N;
bool Found[MAXN];
int GCD(int a,int b)
{
	int r;
	while (b)
	{
		r=b;
		b=a%b;
		a=r;
	}
	return a;
}
int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		int SqrN=sqrt(N)+1;
		memset(Found,0,sizeof(Found));
		int Ans1=0;
		for (int i=1;i<=SqrN;i+=2)
		{
			for (int j=i+2;i*j<=N;j+=2)
			{
				if (GCD(i,j)==1) 
				{
					long long a=(long long)i*j;
					long long b=((long long)j*j-i*i)/2;
					long long c=((long long)j*j+i*i)/2;
					if (c<=N)
					{
						Ans1++;
						Found[a]=1;
						Found[b]=1;
						Found[c]=1;
						for (int k=2;(k*c<=N)&&(b*k<=N);++k)
						{
							Found[a*k]=1;
							Found[b*k]=1;
							Found[c*k]=1;
						}
					}
				}
			}
		}
		int Ans2=0;
		for (int i=1;i<=N;++i) 
			if (!Found[i]) Ans2++;
		printf("%d %d\n",Ans1,Ans2);
	}
	return 0;
}
