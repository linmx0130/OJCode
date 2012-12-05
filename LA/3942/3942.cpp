#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 4505
#define MAXLEN 350005
#define MAXWORD 150
#define MAXNODE 4505*150
#define MOD 20071027
char S[MAXLEN];
struct Trie
{
	int ch[MAXNODE][26];
	bool beWord[MAXNODE];
	int tot;
	void Init()
	{
		tot=1;
		memset(beWord,0,sizeof(beWord));
		memset(ch,0,sizeof(ch));
	}
	void Insert(char *Word)
	{
		int n=strlen(Word);
		int now=1;
		for (int i=0;i<n;++i)
		{
			if (ch[now][Word[i]-'a']) {now=ch[now][Word[i]-'a'];continue;}
			else 
			{
				++tot;
				ch[now][Word[i]-'a']=tot;
				now=tot;
			};
		}
		beWord[now]=1;
	}
}T;
char Buf[150];
int f[MAXLEN];
void Main()
{
	int N;
	T.Init();
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		scanf("%s",Buf);
		T.Insert(Buf);
	}
	N=strlen(S);
	memset(f,0,sizeof(f));
	f[N]=1;
	for (int i=N-1;i>=0;--i)
	{
		int j=i-1,now=1;
		while (now)
		{
			j++;
			if (!T.ch[now][S[j]-'a']) break;
			now=T.ch[now][S[j]-'a'];
			if (T.beWord[now])
			{
				f[i]+=f[j+1];
				if (f[i]>=MOD) f[i]-=MOD;
			}
		}
	}
	printf("%d\n",f[0]);
};
int main()
{
	int i=0;
	while (scanf("%s",S)!=EOF)
	{
		printf("Case %d: ",++i);
		Main();
	}
	return 0;
}
