#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 10005
#define MAXM 50005
int min(int a,int b) {return a<b?a:b;}
struct eList
{
	int Head[MAXN],Pre[MAXM],V[MAXM],tot;
	void AddEdge(int a,int b)
	{
		++tot;
		V[tot]=b;Pre[tot]=Head[a];Head[a]=tot;
	}
}G,G2;
int N,M;
int Pre[MAXN],Low[MAXN],TStamp,SCC_Cnt,SCC_No[MAXN];
int Stack[MAXN],St;
void Dfs(int now)
{
	Pre[now]=Low[now]=++TStamp;
	Stack[++St]=now;
	for (int p=G.Head[now];p;p=G.Pre[p])
	{
		if (!Pre[G.V[p]])
		{
			Dfs(G.V[p]);
			Low[now]=min(Low[now],Low[G.V[p]]);
		}else 
		{
			if (!SCC_No[G.V[p]])
			{
				Low[now]=min(Low[now],Pre[G.V[p]]);
			}
		}
	}
	if (Low[now]==Pre[now])
	{
		SCC_Cnt++;
		while(1)
		{
			int x=Stack[St--];
			SCC_No[x]=SCC_Cnt;
			if (x==now) break;
		}
	}
}
int Cd[MAXN];
int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		G.AddEdge(a,b);
	}
	for (int i=1;i<=N;++i)
	{
		if (!Pre[i]) Dfs(i);
	}

	for (int i=1;i<=N;++i)
	{
		for (int p=G.Head[i];p;p=G.Pre[p])
		{
			if (SCC_No[i]!=SCC_No[G.V[p]])
			{
				G2.AddEdge(SCC_No[i],SCC_No[G.V[p]]);
				Cd[SCC_No[i]]++;
			}
		}
	}
	int Point=0;
	for (int i=1;i<=SCC_Cnt;++i)
	{
		if (Cd[i]==0) 
		{
			if (Point==0) Point=i;
			else 
			{
				puts("0");
				return 0;
			}
		}
	}
	int Ans=0;
	for (int i=1;i<=N;++i) if (SCC_No[i]==Point) Ans++;
	printf("%d\n",Ans);
	return 0;
}
