#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 50005
#define MAXWORD 205
#define MAXNODE MAXN*MAXWORD
struct Trie
{
	int ch[MAXNODE][2];
	int wordCount[MAXNODE];
	int Deepth[MAXNODE];
	int tot;
	void Init()
	{
		tot=1;
		memset(wordCount,0,sizeof(wordCount));
		memset(Deepth,0,sizeof(Deepth));
		memset(ch,0,sizeof(ch));
	}
	void Insert(char *Word)
	{
		int n=strlen(Word);
		int now=1;
		wordCount[now]++;
		for (int i=0;i<n;++i)
		{
			if (ch[now][Word[i]-'0']) {now=ch[now][Word[i]-'0'];}
			else 
			{
				++tot;
				ch[now][Word[i]-'0']=tot;
				Deepth[tot]=Deepth[now]+1;
				now=tot;
			};
			wordCount[now]++;
		}
	}
}T;
char Buf[205];
int f[MAXN];
int GetAns(int now)
{
	int Ret=T.Deepth[now]*T.wordCount[now];
	if (T.ch[now][0])
	{
		int d=GetAns(T.ch[now][0]);
		if (d>Ret) Ret=d;
	}
	if (T.ch[now][1])
	{
		int d=GetAns(T.ch[now][1]);
		if (d>Ret) Ret=d;
	}
	return Ret;
}
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
	printf("%d\n",GetAns(1));
};
int main()
{
	int T;
	for (scanf("%d",&T);T;T--)
	{
		Main();
	}
	return 0;
}
