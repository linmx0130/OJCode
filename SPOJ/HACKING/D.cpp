#include <cstdio>
#include <cstdlib>
#include <cstring>
#define HASHSIZE 100007
#define MAXN 10005
bool Hash[HASHSIZE];
char Buf[MAXN];
int N,M,K;
int GetHash(int s,int L)
{
//	printf("%s\n",Buf+s);
	int ret=0;
	for (int i=0;i<L;++i)
	{
		ret=ret*K+(int)(Buf[s+i]-'a');
	}
	return ((ret%HASHSIZE)+HASHSIZE)%HASHSIZE;
}
int AnsS[104];
void GetBack(int h)
{
	int Anst=0;
	while (h)
	{
		AnsS[++Anst]=h%K;
		h/=K;
	}
	for (int i=Anst+1;i<=M;++i) AnsS[i]=0;
	for (int i=M;i>=1;--i) putchar(AnsS[i]+'a');
	putchar('\n');
}
void Main()
{
	memset(Hash,0,sizeof(Hash));
	scanf("%d%d%d",&N,&M,&K);
	scanf("%s",Buf);
	for (int i=0;i+M<=N;++i)
	{
		Hash[GetHash(i,M)]=1;
	}
	for (int i=0;i<HASHSIZE;++i)
	{
		if (!Hash[i])
		{
			GetBack(i);
			return ;
		}
	}
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--) Main();
	return 0;
}
