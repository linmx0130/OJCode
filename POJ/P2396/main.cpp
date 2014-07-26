#include <cstdio>
#include <cstring>
#include <cstdlib>
#define oo 0x3f3f3f3f
#define MAXN 3000
#define MAXM 100005
int MatC[202][202][2];
int RowSum[202];
int ColSum[202];
int RowNum[202],ColNum[202];
int M,N;
char Buf[10];
int eRec[202][202];
struct eList
{
	int Head[MAXN],Pre[MAXM],V[MAXM],U[MAXM],Cap[MAXM],tot;
	void AddEdge(int a,int b,int c)
	{
		++tot;U[tot]=a;V[tot]=b;Cap[tot]=c;
		Pre[tot]=Head[a];Head[a]=tot;
		++tot;U[tot]=b;V[tot]=a;Cap[tot]=0;
		Pre[tot]=Head[b];Head[b]=tot;
	}
	void Init()
	{
		tot=1;
		memset(Head,0,sizeof(Head));
	}
}G;
int Du[MAXN];
void Deal(int i,int j,int v)
{
	if (Buf[0]=='>') if (v+1>MatC[i][j][1]) MatC[i][j][1]=v+1;
	if (Buf[0]=='<') if (v-1<MatC[i][j][0]) MatC[i][j][0]=v-1;
	if (Buf[0]=='=') 
	{
		if (v<MatC[i][j][0]) MatC[i][j][0]=v;
		if (v>MatC[i][j][1]) MatC[i][j][1]=v;
	}
}
int Count[MAXN],Path[MAXN],Dist[MAXN],Stack[MAXN],MaxFlow,NowHead[MAXN];
void SAP(int N,int S,int T)
{
	memset(Count,0,sizeof(Count));
	memset(Dist,0,sizeof(Dist));
	memcpy(NowHead,G.Head,sizeof(NowHead));
	MaxFlow=0;
	int x=S,MinFlow=oo;
	Count[0]=N;
	while (Dist[S]<N)
	{
		Stack[x]=MinFlow;
		bool flag=0;
		for (int p=NowHead[x];p;p=G.Pre[p])
		{
			if (G.Cap[p] && Dist[G.V[p]]+1==Dist[x])
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
void Main()
{
	scanf("%d%d",&M,&N);
	memset(eRec,0,sizeof(eRec));
	memset(Du,0,sizeof(Du));
	G.Init();
	for (int i=1;i<=M;++i)
	{
		for (int j=1;j<=N;++j)
		{
			MatC[i][j][0]=oo;
			MatC[i][j][1]=0;
		}
	}
	for (int i=1;i<=M;++i) scanf("%d",&RowSum[i]);
	for (int i=1;i<=N;++i) scanf("%d",&ColSum[i]);
	int C;
	scanf("%d",&C);
	for (int i=1;i<=C;++i)
	{
		int r,q,v;
		scanf("%d%d%s%d",&r,&q,Buf,&v);
		if (r==0 && q==0)
		{
			for (int i=1;i<=M;++i)
			{
				for (int j=1;j<=N;++j) Deal(i,j,v);
			}
		}
		else if (r==0)
		{
			for (int i=1;i<=M;++i)
			{
				Deal(i,q,v);
			}
		}
		else if (q==0)
		{
			for (int j=1;j<=N;++j)
			{
				Deal(r,j,v);
			}
		}else Deal(r,q,v);
	}
	for (int i=1;i<=M;++i)
	{
		for (int j=1;j<=N;++j)
			if (MatC[i][j][0]<MatC[i][j][1])
			{
				puts("IMPOSSIBLE");
				return ;
			}
	}
	int Ptot=4,S2=1,T2=2,S=3,T=4;
	for (int i=1;i<=M;++i) RowNum[i]=++Ptot;
	for (int i=1;i<=N;++i) ColNum[i]=++Ptot;
	for (int i=1;i<=M;++i)
	{
		for (int j=1;j<=N;++j)
		{
			G.AddEdge(RowNum[i],ColNum[j],MatC[i][j][0]-MatC[i][j][1]);
			eRec[i][j]=G.tot;
			Du[RowNum[i]]-=MatC[i][j][1];
			Du[ColNum[j]]+=MatC[i][j][1];
		}
	}
	for (int i=1;i<=M;++i)
	{
		Du[S]-=RowSum[i];Du[RowNum[i]]+=RowSum[i];
	}
	for (int i=1;i<=N;++i)
	{
		Du[T]+=ColSum[i];Du[ColNum[i]]-=ColSum[i];
	}
	for (int i=3;i<=Ptot;++i)
	{
		if (Du[i]>0) G.AddEdge(S2,i,Du[i]);
		if (Du[i]<0) G.AddEdge(i,T2,-Du[i]);
	}
	G.AddEdge(T,S,oo);
	/*
	for (int i=1;i<=G.tot;++i)
	{
		if (G.Cap[i])printf("%d->%d Cap=%d\n",G.U[i],G.V[i],G.Cap[i]);
	}*/
	SAP(Ptot,S2,T2);
	for (int p=G.Head[S2];p;p=G.Pre[p])
	{
		if (G.Cap[p]) {
			puts("IMPOSSIBLE");
			return ;
		}
	}
	for (int i=1;i<=M;++i)
	{
		for (int j=1;j<=N;++j)
		{
			printf("%d ",G.Cap[eRec[i][j]]+MatC[i][j][1]);
		}
		puts("");
	}
	return ;
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--)
	{
		Main();
		puts("");
	}
	return 0;
}
