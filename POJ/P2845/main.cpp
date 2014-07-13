#include <cstdio>
#include <cstdlib>
#include <cstring>
char Buf[100];
struct BigBin
{
	int D[100],p;
	void Init (char *s)
	{
		int l=strlen(s);
		memset(D,0,sizeof(D));
		p=99;
		for (int i=l-1;i>=0;--i)
		{
			D[p]=Buf[i]-'0';
			p--;
		}
		while (D[p]==0 && p<99) p++;
	}
	void operator+=(const BigBin & t)
	{
		if (t.p<p) p=t.p;
		for (int i=99;i>=t.p;--i)
		{
			D[i]+=t.D[i];
			if (D[i]>1)
			{
				D[i]-=2;
				D[i-1]++;
			}
		}
		for (int i=t.p-1;i>=p;--i)
		{
			if (D[i]>1)
			{
				D[i]-=2;
				D[i-1]++;
			}
		}
		while (D[p-1]>0) p--;
	}
	void Print()
	{
		for (int i=p;i<=99;++i)
		{
			printf("%d",D[i]);
		}
		puts("");
	}
}A,B;
void Main()
{
	scanf("%s",Buf);
	A.Init(Buf);
	scanf("%s",Buf);
	B.Init(Buf);
	A+=B;
	A.Print();
};
int main()
{
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;++i)
	{
		printf("%d ",i);
		Main();
	}
	return 0;
}
