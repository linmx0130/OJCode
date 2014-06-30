#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using std::sort;
#define MAXN 100004
int N,C;
int D[MAXN];
bool Check(int T)
{
	int Last=1,Count=1;
	for (int i=2;i<=N;++i)
	{
		if (D[i]>=D[Last]+T) 
		{
			Last=i;Count++;
			if (Count==C) return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d%d",&N,&C);
	for (int i=1;i<=N;++i) scanf("%d",&D[i]);
	sort(D+1,D+N+1);
	int L=1,R=D[N];
	while (L<R)
	{
		int mid=((L+R)>>1)+1;
		if (Check(mid))
		{
			L=mid;
		}else
		{
			R=mid-1;
		}
	}
	printf("%d\n",L);
}
