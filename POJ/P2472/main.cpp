#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 103
#define MAXM 10005
struct eList 
{
	int Head[MAXN],Pre[MAXM],V[MAXM],P[MAXM],tot;
	void AddEdge(int a,int b,int c)
	{
		++tot;
		V[tot]=b;P[tot]=c;Pre[tot]=Head[a];Head[a]=tot;
	}
	void AddEdge2(int a,int b,int c)
	{
		AddEdge(a,b,c);
		AddEdge(b,a,c);
	}
	void Init()
	{
		tot=0;
		memset(Head,0,sizeof(Head));
	}
}G;
int N,M;
double Dist[MAXN];
int Q[MAXM*10];
bool inQ[MAXN];
void SPFA()
{
	memset(Dist,0,sizeof(Dist));
	Q[1]=1;
	Dist[1]=1;
	inQ[1]=1;
	int Qh=0,Qt=1;
	while (Qh<Qt)
	{
		int x=Q[++Qh];
		for (int p=G.Head[x];p;p=G.Pre[p])
		{
			if (Dist[G.V[p]]<Dist[x]*0.01*G.P[p])
			{
				Dist[G.V[p]]=Dist[x]*0.01*G.P[p];
				if (!inQ[G.V[p]])
				{
					inQ[G.V[p]]=1;
					Q[++Qt]=G.V[p];
				}
			}
		}
		inQ[x]=0;
	}
}
void Main()
{
	G.Init();
	for (int i=1;i<=M;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		G.AddEdge2(a,b,c);
	}
	SPFA();
	printf("%.6f percent\n",Dist[N]*100);
}
int main()
{
	while (scanf("%d%d",&N,&M),N)
	{
		Main();
	}
	return 0;
}
