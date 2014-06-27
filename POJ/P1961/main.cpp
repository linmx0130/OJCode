#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 1000002
char S[MAXN];
int F[MAXN];
int N;
void getFail()
{
	memset(F,0,sizeof(F));
	for (int i=1;i<N;++i)
	{
		int j=F[i];
		while (j && S[i]!=S[j]) j=F[j];
		F[i+1]=S[i]==S[j]?j+1:0;
	}
}
void Main()
{
	scanf("%s",S);
	getFail();
	for (int i=1;i<=N;++i)
	{
		if (F[i]>0) if (i%(i-F[i])==0) 
		{
			printf("%d %d\n",i,i/(i-F[i]));
		}
	}
	puts("");
}
int main()
{
	int Count=0;
	while (scanf("%d",&N),N)
	{
		printf("Test case #%d\n",++Count);
		Main();
	}
}
