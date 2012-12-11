#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 2302
int N;
int Land[MAXN][2];
struct eList
{
	int Head[MAXN*2],Pre[MAXN*MAXN*4],V[MAXN*MAXN*4],tot;
	void Init()
	{
		tot=0;
		memset(Head,0,sizeof(Head));
//		memset(Pre,0,sizeof(Pre));
	}
	void AddEdge(int a,int b)
	{
		++tot;
		V[tot]=b;
		Pre[tot]=Head[a];
		Head[a]=tot;
	};
	void AddClause(int x,int xval,int y,int yval)
	{
		x=(x<<1)+xval;
		y=(y<<1)+yval;
		AddEdge(x^1,y);AddEdge(y^1,x);
	};
}G;
bool Mark[MAXN*2];
int S[MAXN*2],Stot;
bool Dfs(int x)
{
	if (Mark[x^1]) return 0;
	if (Mark[x]) return 1;
	Mark[x]=1;
	S[Stot++]=x;
	for (int p=G.Head[x];p;p=G.Pre[p])
	{
		if (!Dfs(G.V[p])) return 0;
	};
	return 1;
};
bool TwoSAT()
{
	memset(Mark,0,sizeof(Mark));
	for (int i=0;i<(N<<1);i+=2)
	{
		if (!Mark[i]&&!Mark[i+1])
		{
			Stot=0;
			if (!Dfs(i))
			{
				while (Stot>0) Mark[S[--Stot]]=0;
				if (!Dfs(i+1)) return 0;
			}
		}
	};
	return 1;
};
bool Check(int P)
{
	G.Init();
	for (int i=0;i<N;++i)
	{
		for (int j=i+1;j<N;++j)
		{
			if (abs(Land[i][0]-Land[j][0])<P) G.AddClause(i,1,j,1);
			if (abs(Land[i][1]-Land[j][0])<P) G.AddClause(i,0,j,1);
			if (abs(Land[i][1]-Land[j][1])<P) G.AddClause(i,0,j,0);
			if (abs(Land[i][0]-Land[j][1])<P) G.AddClause(i,1,j,0);
		}
	}
	return TwoSAT();
}
void Main()
{
	int L=0,R=0;
	for (int i=0;i<N;++i)
	{
		scanf("%d%d",&Land[i][0],&Land[i][1]);
		if (Land[i][1]>R) R=Land[i][1];
	}
	while (L<R)
	{
		int Mid=(L+R+1)>>1;
		if (Check(Mid))
		{
			L=Mid;
		}else
		{
			R=Mid-1;
		}
	}
	printf("%d\n",L);
};
int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		Main();
	}
	return 0;
};

