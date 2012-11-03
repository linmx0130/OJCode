#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 200002
#define MAXK 51
#define MAXP 102
int N,K,P;
int Color[MAXN],Price[MAXN];
int Color_Ansa[MAXK][MAXN];
int Low_Price_Pos[MAXN];
int main()
{
	scanf("%d%d%d",&N,&K,&P);
	for (int i=1;i<=N;++i) scanf("%d%d",&Color[i],&Price[i]);
	for (int i=1;i<=N;++i)
	{
		for (int j=0;j<K;++j)
		{
			Color_Ansa[j][i]=Color_Ansa[j][i-1];
		}
		Color_Ansa[Color[i]][i]++;
	}
	for (int i=1;i<=N;++i)
	{
		if (Price[i]<=P) Low_Price_Pos[i]=i;
		else Low_Price_Pos[i]=Low_Price_Pos[i-1];
	}
	long long Ans=0;
	for (int i=1;i<=N;++i)
	{
		if (Low_Price_Pos[i]>i) continue;
		Ans+=Color_Ansa[Color[i]][Low_Price_Pos[i]];
		if (Price[i]<=P) Ans--;
	}
	printf("%lld\n",Ans);
	return 0;
}
