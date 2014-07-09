#include <cstdio>
#include <cstring>
#include <cstdlib>
int N,M,P,C;
int main()
{
	while (scanf("%d%d%d%d",&N,&M,&P,&C),N!=0)
	{
		int Ans=M-N;
		Ans-=P;
		printf("%d\n",-Ans);
	}
	return 0;
}
