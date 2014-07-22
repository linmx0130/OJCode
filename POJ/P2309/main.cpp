#include <cstdio>
#include <cstring>
#include <cstdlib>
#define LOWBIT(t) (t&(-t))
int N;
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		int k;scanf("%d",&k);
		printf("%d %d\n",k-LOWBIT(k)+1,k+(LOWBIT(k)-1));
	}
	return 0;
}
