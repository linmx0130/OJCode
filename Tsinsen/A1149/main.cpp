#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN (1<<10)
int N;
int Sum[MAXN];
int S[MAXN];
char Buf[MAXN];
void BuildTree(int L,int R)
{
	if (L!=R)
	{
		int k=(L+R)>>1;
		BuildTree(L,k);
		BuildTree(k+1,R);
	}
	if (Sum[R]-Sum[L-1]==R-L+1)
	{
		printf("I");
		return ;
	}
	if (Sum[R]-Sum[L-1]==0)
	{
		printf("B");
		return ;
	}
	printf("F");
}
int main()
{
	scanf("%d",&N);scanf("%s",&Buf);
	N=1<<N;
	for (int i=0;i<N;++i)
	{
		S[i+1]=Buf[i]-'0';
		Sum[i+1]=Sum[i]+S[i+1];
	}
	BuildTree(1,N);
	puts("");
	return 0;
}
