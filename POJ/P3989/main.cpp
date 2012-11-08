#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 20
char S1[MAXN],S2[MAXN],S3[MAXN];
bool Found[5];
int N1,N2,N3;
int Stack[10];
int Ans=0;
bool Used[10];
int Check()
{
	long long s1=0,s2=0,s3=0;
	//Check first 0
	if (N1>1) if (Stack[S1[0]-'A']==0) return 0;
	if (N2>1) if (Stack[S2[0]-'A']==0) return 0;
	if (N3>1) if (Stack[S3[0]-'A']==0) return 0;
	//build num
	for (int i=0;i<N1;++i) 
	{
		s1=10*s1+Stack[S1[i]-'A'];
	}
	for (int i=0;i<N2;++i) 
	{
		s2=10*s2+Stack[S2[i]-'A'];
	}
	for (int i=0;i<N3;++i) 
	{
		s3=10*s3+Stack[S3[i]-'A'];
	}

	int Ret=0;
	if (s1+s2==s3) Ret++;
	if (s1-s2==s3) Ret++;
	if (s1*s2==s3) Ret++;
	if (s2) if (s1%s2==0) if (s1/s2==s3) Ret++;
	return Ret;
}
void Search(int now)
{
	if (now==5)
	{
		Ans+=Check();
		return ;
	}
	if (!Found[now]) {Search(now+1);return ;}
	for (int i=0;i<=9;++i)
	{
		if (Used[i])continue;
		Used[i]=1;
		Stack[now]=i;
		Search(now+1);
		Used[i]=0;
	}
}
void Main()
{
	Ans=0;
	memset(Found,0,sizeof(Found));
	scanf("%s%s%s",S1,S2,S3);
	N1=strlen(S1);N2=strlen(S2);N3=strlen(S3);
	for (int i=0;i<N1;++i) Found[S1[i]-'A']=1;
	for (int i=0;i<N2;++i) Found[S2[i]-'A']=1;
	for (int i=0;i<N3;++i) Found[S3[i]-'A']=1;
	Search(0);
	printf("%d\n",Ans);
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--) Main();
	return 0;
};
