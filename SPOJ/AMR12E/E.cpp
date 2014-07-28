#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 405
#define MAXT 50000
#define STATOT ((2<<11)-1)
#define MOD 1000000007
int F[MAXN][STATOT];
int N,K;
bool NoUse[STATOT];
void Insert(int t)
{
	NoUse[t]=1;
}
bool isPalindrom(int now,int Len)
{
	int i=0,j=Len-1;
	while (i<j)
	{
		bool a=(now &(1<<i)),b=(now &(1<<j));
		if (a!=b) return 0;
		i++;j--;
	}
	return 1;
}
void GetPalindrom1(int Len,int K)
{
	int statot=1<<(K);
	for (int i=0;i<statot;++i)
	{
		if (isPalindrom(i,K))
			Insert(i);
	}
}
void GetPalindrom2(int Len,int K)
{
	int statot=1<<(K+1);
	for (int i=0;i<statot;++i)
	{
		if (isPalindrom(i,K))
			Insert(i);
		if (isPalindrom(i,K+1))
			Insert(i);
	}
}

void Main()
{
	scanf("%d%d",&N,&K);
	if (K==1) {puts("0");return ;}
	if (N<K) 
	{
		int Ans=1;
		for (int i=1;i<=N;++i) Ans<<=1;
		printf("%d\n",Ans);
		return ;
	}

	memset(NoUse,0,sizeof(NoUse));
	GetPalindrom1(0,K);
	int statot=(1<<K+1),mask=statot-1;
	memset(F,0,sizeof(F));
	for (int i=0;i<(1<<K);++i)
	{
		F[K][i]=NoUse[i]?0:1;
	}
	GetPalindrom2(0,K);
	int nj;
	for (int i=K;i<N;++i)
	{
		for (int j=0;j<statot;++j)
		{
			nj=(j<<1)&mask;
			if (!NoUse[nj]) 
			{
				F[i+1][nj]+=F[i][j];
				if (F[i+1][nj]>=MOD) F[i+1][nj]-=MOD;
			}
			nj=((j<<1)+1)&mask;
			if (!NoUse[nj])
			{
				F[i+1][nj]+=F[i][j];
				if (F[i+1][nj]>=MOD) F[i+1][nj]-=MOD;
			}
		}
	}
	int Ans=0;
	for (int i=0;i<statot;++i)
	{
		Ans+=F[N][i];
		int k=i;
		if (Ans>=MOD) Ans-=MOD;
	}
	printf("%d\n",Ans);
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--) Main();
	return 0;
}
