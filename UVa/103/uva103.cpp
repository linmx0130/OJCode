/* Uva 103
   By Sweetdumplings
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#define MAXN 50
using std::vector;
using std::sort;
int N,K;
struct eList
{
	int tot,Head[MAXN],V[MAXN*MAXN*2],Pre[MAXN*MAXN*2];
	void AddEdge(int a,int b)
	{
		++tot;
		V[tot]=b;
		Pre[tot]=Head[a];
		Head[a]=tot;
	}
	void Clear()
	{
		tot=0;
		memset(Head,0,sizeof(Head));
		memset(Pre,0,sizeof(Pre));
	}
}G;
struct BoxT
{
	vector <int> len;
}Tmp;
vector <BoxT> Box;
bool InBox(int a, int b)
{
	for (int i=0;i<K;++i)
	{
		if (Box[a].len[i]>=Box[b].len[i]) return 0;
	}
	return 1;
}
int Dis[MAXN], Path[MAXN];
bool Mark[MAXN];
int Dp(int now)
{
	if (Mark[now]) return Dis[now];
	Mark[now]=1;
	for (int p=G.Head[now];p;p=G.Pre[p])
	{
		if (Dp(G.V[p])>=Dis[now]) 
		{
			Dis[now]=Dis[G.V[p]]+1;
			Path[now]=G.V[p];
		}
	}
	return Dis[now];
}
void PrintPath(int now)
{
	if (Path[now]>=0)
	{
		printf("%d ",now+1);
		PrintPath(Path[now]);
	}
	else
	{
		printf("%d\n",now+1);
	}
}
void Solve()
{
	Box.clear();
	G.Clear();
	int t;
	for (int i=0;i<N;++i)
	{
		Tmp.len.clear();
		for (int j=0;j<K;++j)
		{
			scanf("%d",&t);
			Tmp.len.push_back(t);
		}
		sort(Tmp.len.begin(),Tmp.len.end());
		Box.push_back(Tmp);
	}
	for (int i=0;i<N;++i)
	{
		for (int j=0;j<N;++j)
		{
			if (i==j) continue;
			if (InBox(i,j))
			{
				G.AddEdge(i,j);
			}
		}
	}
	memset(Dis,0,sizeof(Dis));
	memset(Path,200,sizeof(Path));
	memset(Mark,0,sizeof(Mark));
	for (int i=0;i<N;++i)
	{
		if (!Mark[i]) Dp(i);
	}
	int Ans=0,Start=0;
	for (int i=0;i<N;++i)
	{
		if (Dis[i]>Ans) {Ans=Dis[i];Start=i;}
	}
	//printf("Start At:%d, Dis=%d\n",Start,Dis[Start]);
	Ans++;
	printf("%d\n",Ans);
	PrintPath(Start);
}
int main()
{
	//freopen("uva103.in","r",stdin);
	for (;scanf("%d%d",&N,&K)!=EOF;)
	{
		Solve();
	}
	//while(1);
	return 0;
}
