#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 110
#define oo 0x3f3f3f3f
int min(int a,int b){return a<b?a:b;}
int N,M,X[MAXN],V[MAXN],GG[MAXN][MAXN],MaxV;
struct eList
{
	int Head[MAXN],V[MAXN*MAXN],U[MAXN*MAXN],Cap[MAXN*MAXN],tot,Pre[MAXN*MAXN],W[MAXN*MAXN];	
	void AddEdge(int a,int b,int c,int d)
	{
		++tot;
		V[tot]=b;U[tot]=a;Cap[tot]=c;W[tot]=d;
		Pre[tot]=Head[a];Head[a]=tot;
		++tot;
		V[tot]=a;U[tot]=b;Cap[tot]=0;W[tot]=-d;
		Pre[tot]=Head[b];Head[b]=tot;
	}
	void Init()
	{
		tot=1;
		memset(Head,0,sizeof(Head));
	}
}G;
#define QSIZE 400000
int Q[QSIZE],Path[MAXN],Dist[MAXN],Flow[MAXN];
bool inQ[MAXN];
bool Spfa(int S,int T)
{
	memset(Dist,60,sizeof(Dist));
	memset(Flow,0,sizeof(Flow));
	int Qh=0,Qt=1;inQ[S]=1;
	Q[1]=S;Dist[S]=0;Flow[S]=oo;
	while (Qh!=Qt)
	{
		++Qh;if (Qh==QSIZE) Qh=0;
		int now=Q[Qh];
		for (int p=G.Head[now];p;p=G.Pre[p])
		{
			if (G.Cap[p] && Dist[G.V[p]]>Dist[now]+G.W[p])
			{
				Dist[G.V[p]]=Dist[now]+G.W[p];
				Flow[G.V[p]]=min(G.Cap[p],Flow[now]);
				Path[G.V[p]]=p;
				if (!inQ[G.V[p]])
				{
					inQ[G.V[p]]=1;
					++Qt;if (Qt==QSIZE) Qt=0;
					Q[Qt]=G.V[p];
				}
			}
		}
		inQ[now]=0;
	}
	return Flow[T]>0;
}
bool Rec[20000001],Rec2[20000001];
int FoundT[1<<13],Foundtot;
int FoundT2[1<<13],Found2tot;
void BuildGraph()
{
	for (int i=1;i<=M;++i)
	{
		for (int j=1;j<=Found2tot;++j) Rec[FoundT2[j]]=0;
		for (int j=1;j<=Foundtot;++j) Rec2[FoundT[j]]=0;
		Foundtot=Found2tot=0;
		int x2=X[i]>>1,x1=X[i]-x2;
		int obj1=1<<x1;
		int obj2=1<<x2;
		bool flag;

		for (int j=0;j<obj1;++j)
		{
			int v=0;flag=0;
			for (int k=0;k<x1;++k)
			{
				if (j &(1<<k) )
				{
					v+=GG[i][k+1];
					if (v>MaxV) {flag=1;break;}
				}
			}
			if (flag) continue;
			if (!Rec[v]) {Rec[v]=1;	FoundT2[++Found2tot]=v;}
		}

		for (int j=0;j<obj2;++j)
		{
			int v=0;flag=0;
			for (int k=0;k<x2;++k)
			{
				if (j &(1<<k) )
				{
					v+=GG[i][X[i]-k];
					if (v>MaxV) {flag=1;break;}
				}
			}
			if (flag) continue;
			if (!Rec2[v]) {Rec2[v]=1;FoundT[++Foundtot]=v;}
		}

		for (int j=1;j<=N;++j)
		{
			for (int k=1;k<=Foundtot;++k)
			{
				if (Rec[V[j]-FoundT[k]])
				{
					G.AddEdge(j,i+N,1,0);
					break;
				}
			}
		}
	}
}
void Main()
{
	MaxV=0;
	scanf("%d%d",&N,&M);
	G.Init();
	for (int i=1;i<=N;++i) {scanf("%d",&V[i]);if (V[i]>MaxV) MaxV=V[i];}
	for (int i=1;i<=M;++i)
	{
		scanf("%d",&X[i]);
		for (int j=1;j<=X[i];++j) scanf("%d",&GG[i][j]);
	}
	BuildGraph();
	int S=N+M+1,T=N+M+2;
	for (int i=1;i<=N;++i)
		G.AddEdge(S,i,1,-V[i]);
	for (int i=1;i<=M;++i)
		G.AddEdge(i+N,T,1,0);
	int Ans=0;
	while (Spfa(S,T))
	{
		Ans+=Dist[T];
		for (int x=T;x!=S;x=G.U[Path[x]])
		{
			G.Cap[Path[x]]-=Flow[T];
			G.Cap[Path[x]^1]+=Flow[T];
		}
	}
	printf("%d\n",-Ans);
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--) Main();
	return 0;
}
