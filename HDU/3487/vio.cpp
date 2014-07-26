#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 300203
int N,M;
int d[MAXN];
int Tmp[MAXN];
int Tmp2[MAXN];
void Cut(int a,int b,int c)
{
	int L=b-a+1;
	for (int i=a;i<=b;++i)
	{
		Tmp[i-a+1]=d[i];
	}
	for (int i=0;i+b+1<=N;++i)
	{
		d[a+i]=d[i+b+1];
	}
	N-=L;
	int L2=N-c;
	for (int i=1;i+c<=N;++i)
	{
		Tmp2[i]=d[i+c];
	}
	N=c;
	for (int i=1;i<=L;++i)
	{
		d[i+N]=Tmp[i];
	}
	N+=L;
	for (int i=1;i<=L2;++i)
	{
		d[i+N]=Tmp2[i];
	}
	N+=L2;
}
void Flip(int a,int b)
{
	for (int i=a,j=b;i<j;i++,j--)
	{
		int k=d[i];
		d[i]=d[j];
		d[j]=k;
	}
}
char Buf[10];
void Main()
{
	for (int i=1;i<=N;++i) d[i]=i;
	for (;M;M--)
	{
		scanf("%s",Buf);
		if (Buf[0]=='C')
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			Cut(a,b,c);
//			for (int i=1;i<N;++i)printf("%d ",d[i]);
//			printf("%d\n",d[N]);
		}else
		{
			int a,b;
			scanf("%d%d",&a,&b);
			Flip(a,b);		
//			for (int i=1;i<N;++i)printf("%d ",d[i]);
//			printf("%d\n",d[N]);
		}
	}
	for (int i=1;i<N;++i)printf("%d ",d[i]);
	printf("%d\n",d[N]);
}
int main()
{
	while (scanf("%d%d",&N,&M),N>0) Main();
	return 0;
}
