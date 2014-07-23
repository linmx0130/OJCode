#include <cstdio>
#include <cstring>
#include <cstdlib>
char Buf[100];
char Ans[100];
int n;
void Work(int pos)
{
	memcpy(Ans,Buf,sizeof(Ans));
	int mint=pos+1;
	for (int i=pos+2;i<n;++i)
	{
		if (Buf[i]<Buf[mint] && Buf[i]>Buf[pos]) mint=i;
	}
	Ans[pos]=Buf[mint];
	Buf[mint]='9'+1;
	for (int i=pos+1;i<n;++i)
	{
		mint=pos;
		for (int j=pos;j<n;++j)
		{
			if (Buf[mint]>Buf[j]) mint=j;
		}
		Ans[i]=Buf[mint];
		Buf[mint]='9'+1;
	}
	puts(Ans);
}
void Main()
{
	scanf("%d",&n);printf("%d ",n);
	scanf("%s",Buf);
	n=strlen(Buf);
	for (int i=n-2;i>=0;--i)
	{
		if (Buf[i]<Buf[i+1])
		{
			Work(i);
			return ;
		}
	}
	puts("BIGGEST");
}
int main()
{
	int P;
	scanf("%d",&P);
	for (;P;P--) Main();
	return 0;
}
