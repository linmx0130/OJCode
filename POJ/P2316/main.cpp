#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 12
int C[MAXN];
char S[MAXN];
int N;
int main()
{
	scanf("%s",S);
	N=strlen(S);
	do
	{
		for (int i=0;i<N;++i)
		{
			C[i]+=S[i]-'0';
		}
	}while (scanf("%s",S)!=EOF);
	for (int i=0;i<N;++i)
	{
		printf("%d",C[i]%10);
	}
	puts("");
	return 0;
}
