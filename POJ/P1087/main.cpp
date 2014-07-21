#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using std::string;
#define MAXN 102
#define MAXP 310
#define MAXPM 310*310
#define oo 0x3f3f3f3f
int N,M,K;
struct Receptacle
{
	string name;
	int id;
}R[MAXN];
struct Device
{
	string name,plug;
	int id;
}D[MAXN];
struct Adapter
{
	string from,to;
	int id;
}A[MAXN];
struct eList
{
	int Head[MAXP],Pre[MAXPM],V[MAXPM],U[MAXPM],Cap[MAXPM],tot;
	void AddEdge(int a,int b,int c)
	{
		++tot;V[tot]=b;U[tot]=a;Cap[tot]=c;
		Pre[tot]=Head[a];Head[a]=tot;
		++tot;V[tot]=a;U[tot]=b;Cap[tot]=0;
		Pre[tot]=Head[b];Head[b]=tot;
	}
}G;
char Buf[50]; 
int Ptot=0;
int Count[MAXP],Path[MAXP],Dist[MAXP],Stack[MAXP],MaxFlow,NowHead[MAXP];
void Sap(int N,int S,int T)
{
	MaxFlow=0;
	memcpy(NowHead,G.Head,sizeof(G.Head));
	int x=S,MinFlow=oo;
	Count[0]=N;
	while (Dist[S]<N)
	{
		Stack[S]=MinFlow;
		bool flag=0;
		for (int p=NowHead[x];p;p=G.Pre[p])
		{
			if (G.Cap[p] && Dist[G.V[p]] +1 == Dist[x])
			{
				NowHead[x]=p;
				flag=1;
				if (G.Cap[p]<MinFlow) MinFlow=G.Cap[p];
				x=G.V[p];
				Path[x]=p;
				if (x==T)
				{
					MaxFlow+=MinFlow;
					for (;x!=S;x=G.U[Path[x]])
					{
						G.Cap[Path[x]]-=MinFlow;
						G.Cap[Path[x]^1]+=MinFlow;
					}
					MinFlow=oo;
				}
				break;
			}
		}
		if (flag) continue;
		int tmp=0,MinDist=N+1;
		for (int p=G.Head[x];p;p=G.Pre[p])
		{
			if (G.Cap[p] && Dist[G.V[p]]<MinDist)
			{
				MinDist=Dist[G.V[p]];
				tmp=p;
			}
		}
		NowHead[x]=tmp;
		tmp=Dist[x];
		Count[Dist[x]]--;
		Dist[x]=MinDist+1;
		Count[Dist[x]]++;
		if (!Count[tmp]) break;
		if (x!=S)
		{
			x=G.U[Path[x]];
			MinFlow=Stack[x];
		}
	}
}
int main()
{
	G.tot=1;
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		scanf("%s",Buf);
		R[i].name=Buf;
		R[i].id=++Ptot;
	}
	scanf("%d",&M);
	for (int i=1;i<=M;++i)
	{
		scanf("%s",Buf);
		D[i].name=Buf;
		scanf("%s",Buf);
		D[i].plug=Buf;
		D[i].id=++Ptot;
	}
	scanf("%d",&K);
	for (int i=1;i<=K;++i)
	{
		scanf("%s",Buf);
		A[i].from=Buf;
		scanf("%s",Buf);
		A[i].to=Buf;
		A[i].id=++Ptot;
	}
	int S=++Ptot,T=++Ptot;
	for (int i=1;i<=M;++i)
	{
		G.AddEdge(S,D[i].id,1);
		for (int j=1;j<=N;++j)
		{
			if (D[i].plug==R[j].name) G.AddEdge(D[i].id,R[j].id,1);
		}
		for (int j=1;j<=K;++j)
		{
			if (D[i].plug==A[j].from) G.AddEdge(D[i].id,A[j].id,1);
		}
	}
	for (int i=1;i<=K;++i)
	{
		for (int j=1;j<=K;++j)
		{
			if (i!=j)
			{
				if (A[i].to==A[j].from)
				{
					G.AddEdge(A[i].id,A[j].id,1);
				}
			}
		}
		for (int j=1;j<=N;++j)
		{
			if (A[i].to==R[j].name)
			{
				G.AddEdge(A[i].id,R[j].id,1);
			}
		}
	}
	for (int i=1;i<=N;++i)
	{
		G.AddEdge(R[i].id,T,1);
	}
	Sap(Ptot,S,T);
	printf("%d\n",M-MaxFlow);
	return 0;
}
