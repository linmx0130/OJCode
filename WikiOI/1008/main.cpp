#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
int N,K;
int X[22];
bool isPrime(int t)
{
	if (t==0) return 0;
	if (t==1) return 0;
	int p=sqrt(t);
	for (int i=2;i<=p;++i) if (t%i==0) return 0;
	return 1;
}
int Ans=0;
void Search(int now,int get,int getx)
{
	if (now>N)
	{
		if (get==K) if (isPrime(getx)) Ans++;
		return ;
	}
	if (N-now+get+1<K) return ;
	if (N-now+get>=K) Search(now+1,get,getx);
	Search(now+1,get+1,getx+X[now]);
}
int main()
{
	scanf("%d%d",&N,&K);
	for (int i=1;i<=N;++i)
	{
		scanf("%d",&X[i]);
	}
	Search(1,0,0);
	printf("%d\n",Ans);
	return 0;
};
