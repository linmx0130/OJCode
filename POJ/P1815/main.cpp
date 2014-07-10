#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 510
#define MAXM MAXN*MAXN*2
#define oo 0x3f3f3f3f
int N,S,T,Ans;
int AnsList[MAXN],AnsTot;
bool Mark[MAXN];
struct eList
{
	int Head[MAXN],Pre[MAXM],V[MAXM],U[MAXM],Cap[MAXM],tot;
	void AddEdge(int a,int b,int c)
	{
		++tot;
		U[tot]=a;V[tot]=b;Cap[tot]=c;
		Pre[tot]=Head[a];Head[a]=tot;
		++tot;
		U[tot]=b;V[tot]=a;Cap[tot]=0;
		Pre[tot]=Head[b];Head[b]=tot;
	}
	void Init()
	{
		memset(Head,0,sizeof(Head));
		tot=1;
	}
}G;
int GMat[MAXN][MAXN];
int PMap[MAXN][2],Ptot;
int Count[MAXN],Path[MAXN],Dist[MAXN],Stack[MAXN],NowHead[MAXN],MaxFlow;
void Sap(int N,int S,int T)
{
	memset(Count,0,sizeof(Count));
	memset(Dist,0,sizeof(Dist));
	MaxFlow=0;
	int x=S,MinFlow=oo;
	Count[0]=N;
	bool flag;
	memcpy(NowHead,G.Head,sizeof(NowHead));
	while (Dist[S]<N)
	{
		Stack[x]=MinFlow;
		flag=0;
		for (int p=NowHead[x];p;p=G.Pre[p])
		{
			if (G.Cap[p] && Dist[G.V[p]]+1==Dist[x])
			{
				flag=1;
				NowHead[x]=p;
				if (G.Cap[p]<MinFlow) MinFlow=G.Cap[p];
				x=G.V[p];
				Path[x]=p;
				if (x==T)
				{
					MaxFlow+=MinFlow;
					for (;x!=S;x=G.U[Path[x]]){
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
		--Count[Dist[x]];
		tmp=Dist[x];
		Dist[x]=MinDist+1;
		++Count[Dist[x]];
		if (!Count[tmp]) break;
		if (x!=S)
		{
			x=G.U[Path[x]];
			MinFlow=Stack[x];
		}
	}
}
void BuildGraph1()
{
	PMap[S][0]=1;  // 1 -> out
	PMap[S][1]=2;  // 0 -> in 
	PMap[T][0]=3;   
	PMap[T][1]=4;  
	G.Init();
	G.AddEdge(1,2,oo);
	G.AddEdge(3,4,oo);
	Ptot=4;
	for (int i=1;i<=N;++i)
	{
		if (i!=S && i!=T)
		{
			PMap[i][0]=++Ptot;
			PMap[i][1]=++Ptot;
			G.AddEdge(Ptot-1,Ptot,1);
		}
	}
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=N;++j)
		{
			if (GMat[i][j] && PMap[i][1] &&PMap[j][0])
			{
				G.AddEdge(PMap[i][1],PMap[j][0],oo);
			}
		}
	}
	Sap(Ptot,PMap[S][1],PMap[T][0]);
}
bool CheckPoint(int P)
{
	G.Init();
	G.AddEdge(1,2,oo);
	G.AddEdge(3,4,oo);
	Mark[P]=1;
	for (int i=1;i<=N;++i)
	{
		if (i!=S && i!=T && !Mark[i])
		{
			G.AddEdge(PMap[i][0],PMap[i][1],1);
		}
	}
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=N;++j)
		{
			if (GMat[i][j] && i!=j)
			{
				G.AddEdge(PMap[i][1],PMap[j][0],oo);
			}
		}
	}
	Sap(Ptot,PMap[S][1],PMap[T][0]);
	Mark[P]=0;
	return MaxFlow==Ans-1;
}


int main()
{
	scanf("%d%d%d",&N,&S,&T);
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=N;++j)
		{
			scanf("%d",&GMat[i][j]);
		}
	}
	if (GMat[S][T])
	{
		puts("NO ANSWER!");
		return 0;
	}
	BuildGraph1();
	printf("%d\n",Ans=MaxFlow);
	AnsTot=0;
	for (int i=1;i<=N && Ans ;++i)
	{
		if (i==S || i==T) continue;
		if (CheckPoint(i))
		{
			AnsList[++AnsTot]=i;
			Mark[i]=1;
			Ans--;
		}
	}
	for (int i=1;i<AnsTot;++i) printf("%d ",AnsList[i]);
	if (AnsTot>0) printf("%d\n",AnsList[AnsTot]);
	return 0;
}
