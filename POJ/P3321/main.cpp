#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 105005
#define LOWBIT(t) (t&(-t))
int N,M;
struct TArr
{
	int S[MAXN],A[MAXN];
	void Add(int now,int t)
	{
		A[now]+=t;
		for (int i=now;i<=N;i+=LOWBIT(i))
		{
			S[i]+=t;
		};
	};
	int Sum(int R)
	{
		int Ret=0;
		for (int i=R;i>0;i-=LOWBIT(i))
		{
			Ret+=S[i];
		}
		return Ret;
	}
	void Modify(int now)
	{
		if (A[now]) Add(now,-1);
		else Add(now,1);
	};
	void init()
	{
		memset(S,0,sizeof(S));
		memset(A,0,sizeof(A));
	}
}T;
struct eList
{
	int Head[MAXN],Pre[MAXN*2],V[MAXN*2],tot;
	void AddEdge(int a,int b)
	{
		++tot;
		V[tot]=b;
		Pre[tot]=Head[a];
		Head[a]=tot;
	};
	void AddEdge2(int a,int b)
	{
		AddEdge(a,b);
		AddEdge(b,a);
	}
	void init()
	{
		memset(Head,0,sizeof(Head));
	}
}G;
int TSize[MAXN];
int TNum[MAXN],PTot;
bool Marked[MAXN];
void FDfs(int now)
{
	++PTot;
	Marked[now]=1;
	TNum[now]=PTot;
	for (int p=G.Head[now];p;p=G.Pre[p])
	{
		if (!Marked[G.V[p]]) FDfs(G.V[p]);
	}
	Marked[now]=0;
};
void SDfs(int now)
{
	++PTot;
	Marked[now]=1;
	TSize[now]=1;
	for (int p=G.Head[now];p;p=G.Pre[p])
	{
		if (!Marked[G.V[p]])
		{
			SDfs(G.V[p]);
			TSize[now]+=TSize[G.V[p]];
		}
	}
	Marked[now]=0;
};
int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		T.init();
		G.init();
		for (int i=1;i<N;++i)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			G.AddEdge2(a,b);
		};
		FDfs(1);
		SDfs(1);
		for (int i=1;i<=N;++i) T.Modify(i);
		char Buf[10];int d;
		for (scanf("%d",&M);M;M--)
		{
			scanf("%s%d",Buf,&d);
			if (Buf[0]=='C') 
			{
				T.Modify(TNum[d]);
			}
			if (Buf[0]=='Q')
			{
				printf("%d\n",T.Sum(TNum[d]+TSize[d]-1)-T.Sum(TNum[d]-1));
			}
		};
	}
	return 0;
};
