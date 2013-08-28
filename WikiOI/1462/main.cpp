#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
int A,B;
int Prime[65530],Ptot;
bool notP[70000];
int main()
{
	scanf("%d%d",&A,&B);
	for (int i=2;i<=65536;++i)
	{
		if (!notP[i])
		{
			Prime[++Ptot]=i;
		}
		for (int j=1;j<=Ptot;++j)
		{
			if (Prime[j]*i<=65536) notP[Prime[j]*i]=1;
			else break;
		}
	}
	int Ans=0;
	if (A>B) {int k=A;A=B;B=k;}
	for (int i=1;i<=Ptot;++i)
	{
		if ((Prime[i]>A)&&(Prime[i]<B)) Ans+=Prime[i];
	}
	printf("%d\n",Ans);
	return 0;
};
