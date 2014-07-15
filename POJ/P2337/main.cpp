#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
char Buf[25];
#define MAXN 1002
int Count[26],Start[26];
vector <string> S;
bool Mark[MAXN];
int Stack[MAXN],St;
bool Search(int now)
{
	if (St==N) return 1;
	for (int i=Start[now];i<N;++i)
	{
		if (S[i][0]-'a'!=now) break;
		if (!Mark[i])
		{
			Mark[i]=1;
			Stack[++St]=i;
			if (Search(S[i][S[i].size()-1]-'a')) return 1;
			Mark[i]=0;
			St--;
		}
	}
	return 0;
}
void Print()
{
	for (int i=1;i<St;++i) printf("%s.",S[Stack[i]].c_str());
	puts(S[Stack[St]].c_str());
}
void Main()
{
	scanf("%d",&N);
	S.clear();
	for (int i=1;i<=N;++i)
	{
		scanf("%s",Buf);
		S.push_back(Buf);
	}
	sort(S.begin(),S.end());
	memset(Start,60,sizeof(Start));
	memset(Count,0,sizeof(Count));
	memset(Mark,0,sizeof(Mark));
	for (int i=0;i!=S.size();++i)
	{
		int h=S[i][0]-'a',t=S[i][S[i].size()-1]-'a';
		Count[h]++;
		Count[t]--;
		if (i<Start[h]) Start[h]=i;
	}
	int Tmp=0;
	for (int i=0;i<26;++i)
	{
		if (Count[i]==1) Tmp++;
		if (Count[i]>=2) 
		{
			puts("***");
			return ;
		}
	}
	if (Tmp>2) {puts("***");return ;}
	memset(Mark,0,sizeof(Mark));
	St=0;
	if (Tmp==0) 
	{
		if (!Search(S[0][0]-'a')) {puts("***"); return ;}
	}
	else
	{
		int first=0;
		for (int i=0;i<26;++i)
		{
			if (Count[i]==1)
			{
				if (Search(i)) break;
				else {puts("***");return;}
			}
		}
	}
	Print();
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--) Main();
	return 0;
}
