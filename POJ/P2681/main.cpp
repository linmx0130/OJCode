#include <cstdio>
#include <cstring>
#include <cstdlib>
char S1[100],S2[100];
int N;
int Count1[26],Count2[26];
int min(int a,int b){return a<b?a:b;}
void Main()
{
	gets(S1);
	gets(S2);
	memset(Count1,0,sizeof(Count1));
	memset(Count2,0,sizeof(Count2));
	for (char *c=S1;*c;c++)
	{
		if (*c=='\n')break;
		Count1[(*c)-'a']++;
	}
	for (char *c=S2;*c;c++)
	{
		if (*c=='\n')break;
		Count2[(*c)-'a']++;
	}
	int Ans=0;
	for (int i=0;i<26;++i)
	{
		Ans+=min(Count1[i],Count2[i]);
	}
	printf("%d\n",strlen(S1)+strlen(S2)-Ans-Ans);
}
int main()
{
	scanf("%d\n",&N);
	for (int i=1;i<=N;++i)
	{
		printf("Case #%d:  ",i);
		Main();
	}
	return 0;
}
