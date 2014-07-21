#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#define MAXN 105
using namespace std;
char emoji[MAXN][20];
int lemoji[MAXN];
char Text[85];
int N,M;
char Buf[85];
inline bool Same(char *s ,int pos,int emo,int Len)
{
	if (pos+lemoji[emo]-1>=Len) return 0;
	for (int i=0;i<lemoji[emo];++i)
	{
		if (s[i+pos]!=emoji[emo][i]) return 0;
	}
	return 1;
}
struct Pair
{
	int L,R;
}Tmp,Q[10000];
bool cmp(const Pair & a, const Pair & b)
{
	return a.R<b.R;
}
bool mark[10000];
void Main()
{
	for (int i=1;i<=N;++i)
	{
		//scanf("%s\n",emoji[i]);
		gets(emoji[i]);
		lemoji[i]=strlen(emoji[i]);
	}
	int Ans=0;
	for (;M;M--)
	{
		int Qt=0;
		gets(Text);
		int Len=strlen(Text);
		for (int j=0;j<Len;++j)
		{
			for (int k=1;k<=N;++k)
			{
				if(Same(Text,j,k,Len))
				{
					Q[Qt].L=j;Q[Qt].R=j+lemoji[k]-1;
					mark[Qt]=0;
					Qt++;
				}
			}
		}
		memset(mark,0,sizeof(mark));
		if (Qt==0) continue;
		sort(Q,Q+Qt,cmp);
		int NowQ=0;
		for (int i=0;i<Len;++i)
		{
			while (NowQ<Qt) if (mark[NowQ]) NowQ++;else break;
			if (i==Q[NowQ].R)
			{
				NowQ++;
				Ans++;
				for (int j=NowQ;j<Qt;++j)
				{
					if (Q[j].L<=i && Q[j].R>=i)
					{
						mark[j]=1;
					}
					if (Q[j].L>i) break;
				}
				while (NowQ<Qt) if (mark[NowQ]) NowQ++;else break;
			}
			if (NowQ==Qt) break;
		}
	}
	printf("%d\n",Ans);
}
int main()
{
	while (scanf("%d%d\n",&N,&M),N) {Main();}
	return 0;
}
