#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 110050
char Buf[MAXN];
char S[MAXN*2];
int p[MAXN*2];
int min(int a,int b){return a<b?a:b;}
void Main()
{
	int N1=strlen(Buf);
	int N=0;
	for (int i=0;i<N1;++i)
	{
		S[N++]='#';
		S[N++]=Buf[i];
	}
	S[N++]='#';
	S[N++]='$';
	int j=0,id;
	memset(p,0,sizeof(p));
	for (int i=0;i<N;++i)
	{
		if (j>i) p[i]=min(p[2*id-i],j-i);
		else p[i]=1;
		while (S[i-p[i]]==S[i+p[i]]) p[i]++;
		if (i+p[i]-1>j)
		{
			j=i+p[i]-1;
			id=i;
		}
	}
	int Ans=0;
	for (int i=0;i<N;++i)
	{
		if (Ans<p[i]-1) Ans=p[i]-1;
	}
	printf("%d\n",Ans);
}
int main()
{
	while (scanf("%s",Buf)!=EOF) Main();
}
